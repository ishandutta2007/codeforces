#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

ll read(){static ll x;scanf("%lld",&x);return x;}
void write(ll x){printf("%lld",x);}
void print(ll x,char c='\n'){write(x),putchar(c);}

pair<int,int>c[N];
int a[N],b[N],m[N],L[N],R[N],l[N],r[N],ans[N];
vector<int>mp[N*10];
void GreenDay()
{
	int n=read(),zyk=0;
	static int zfl[N];
	for (int i=1;i<=n;i++)
	{
		a[i]=read(),b[i]=read(),m[i]=read();
		L[i]=max(m[i]-b[i],0),R[i]=min(a[i],m[i]);
		l[i]=(a[i]-R[i])-(b[i]-(m[i]-R[i]));
		r[i]=(a[i]-L[i])-(b[i]-(m[i]-L[i]));
		mp[zfl[++zyk]=a[i]+b[i]-m[i]].push_back(i);
	}
	sort(zfl+1,zfl+1+zyk);
	zyk=unique(zfl+1,zfl+1+zyk)-zfl-1;
	int tot=0;
	static int b[N];
	for (int ync=0;ync<=zyk;ync++)
	{
		int k=zfl[ync];
//		print(k);
		int cnt=b[0]=0;
		auto &now=mp[k];
		int n=now.size();
		for (int i=0;i<n;i++) b[++cnt]=r[now[i]];
		sort(b+1,b+1+cnt);
		cnt=unique(b+1,b+1+cnt)-b-1;
		sort(now.begin(),now.end(),[&](int x,int y){return r[x]<r[y];});
		for (int i=0;i<n;i++)
			c[i].first=lower_bound(b+1,b+1+cnt,l[now[i]])-b,
			c[i].second=lower_bound(b+1,b+1+cnt,r[now[i]])-b;
		static int q[N],dp[N],from[N];
		int h=1,t=1;
		dp[q[1]=0]=0;
//		for (int i=0;i<n;i++)
//		{
//			print(l[now[i]],' '),print(r[now[i]]);
//			print(c[i].first,','),print(c[i].second);
//		}
//		puts("asdf");
		for (int i=1,j=0,mx=0;i<=cnt+1;i++)
		{
			while (j<n&&c[j].second<i) mx=max(mx,c[j].first),j++;
			while (h<=t&&q[h]<mx) h++;
			dp[i]=dp[q[h]]+1,from[i]=q[h];
//			print(i,':'),print(q[h]);
			while (h<=t&&dp[q[t]]>dp[i]) t--;
			q[++t]=i;
		}
		tot+=dp[cnt+1]-1;
		int kkk=cnt+1;
		vector<int>pos;
//		puts("ASDASDA");
		while (from[kkk])
		{
			if (kkk==from[kkk]) assert(false);
			kkk=from[kkk];
			pos.push_back(kkk);
		}
//		puts("ASDASDASDASDASDA");
		reverse(pos.begin(),pos.end());
		for (int i=0;i<n;i++)
		{
			int tmp=b[*lower_bound(pos.begin(),pos.end(),c[i].first)];
			ans[now[i]]=R[now[i]]-(tmp-l[now[i]])/2;
		}
		mp[k].clear();
	}
	print(tot);
	for (int i=1;i<=n;i++) print(ans[i],' '),print(m[i]-ans[i]);
}

signed main()
{
//	int T=1;
	int T=read();
	while (T--) GreenDay();
	
	return 0;
}