#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

int p[N],t[N];
bool vis[N];
void work()
{
	int n=read(),ans1=1,m=n;
	for (int i=1;i<=n;i++) p[i]=read(),t[i]=vis[i]=0;
	while (m>4) m-=3,ans1=ans1*3LL%mod;
	ans1=1LL*ans1*m%mod;
	print(ans1,' ');
	
	vector<int>a;
	for (int i=1;i<=n;i++)
	if (!vis[i])
	{
		int tot=0;
		for (int j=i;!vis[j];j=p[j]) tot++,vis[j]=1;
		a.push_back(tot);
		t[tot]++;
	}
	
	auto calc=[&](int cnt1,int cnt2)
	{
		int tmp=min(cnt1,cnt2),ret=0;
		ret+=tmp,cnt1-=tmp,cnt2-=tmp;
		ret+=cnt1/3*2+cnt2;
		return ret;
	};
	int cnt1=0,cnt2=0,ans=0;
	for (int i:a) ans+=(i-1)/3,cnt1+=i%3==1,cnt2+=i%3==2;
	auto b=a;
	sort(b.begin(),b.end());
	b.resize(unique(b.begin(),b.end())-b.begin());
	if (n%3==0) print(ans+calc(cnt1,cnt2));
	else if (n%3==2)
	{
		int res=N;
		for (int i:b) if (i>=2) res=min(res,calc(
			cnt1-(i%3==1)+((i-2)%3==1),
			cnt2-(i%3==2)+((i-2)%3==2)
		)-(i-1)/3+(i-2-1)/3+(i>2));
		if (cnt1>=2) res=min(res,calc(cnt1-2,cnt2)+1);
		if (cnt2) res=min(res,calc(cnt1,cnt2-1));
		print(ans+res);
	}
	else
	{
		int res=N;
		for (int i:b) if (i>=4) res=min(res,calc(
			cnt1-(i%3==1)+((i-4)%3==1),
			cnt2-(i%3==2)+((i-4)%3==2)
		)-(i-1)/3+(i-4-1)/3+(i>4));
//		print(ans-(6-1)/3+(6-4-1)/3,','),print(res);
		for (int i:b)
		for (int j:b)
		if (i!=j||t[i]>=2)
		{
			if (i>=1&&j>=3) res=min(res,calc(
				cnt1-(i%3==1)+((i-1)%3==1)-(j%3==1)+((j-3)%3==1),
				cnt2-(i%3==2)+((i-1)%3==2)-(j%3==1)+((j-3)%3==1)
			)-(i-1)/3+(i-1-1)/3-(j-1)/3+(j-3-1)/3+1+(i>1)+(j>3));
			if (i>=2&&j>=2) res=min(res,calc(
				cnt1-(i%3==1)+((i-2)%3==1)-(j%3==1)+((j-2)%3==1),
				cnt2-(i%3==2)+((i-2)%3==2)-(j%3==2)+((j-2)%3==1)
			)-(i-1)/3+(i-2-1)/3-(j-1)/3+(j-2-1)/3+(i>2)+(j>2));
		}
		if (cnt2>=2) res=min(res,calc(cnt1,cnt2-2));
		if (cnt1>=2&&cnt2>=1) res=min(res,calc(cnt1-2,cnt2-1)+1);
		if (cnt1>=4) res=min(res,calc(cnt1-4,cnt2)+2);
		print(ans+res);
	}
}

signed main()
{
	int T=read();
	while (T--) work();
	
	return 0;
}