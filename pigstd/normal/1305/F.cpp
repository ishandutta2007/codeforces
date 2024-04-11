#include<bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int M=2e5+10;
const int N=1e6+10;
int T=100,n,k,a[M],ans,f[N],prime[N],cnt;
vector<int>v;map<int,int>t;

void solve(int x)
{
	if (x<=0)return;v.clear();
	for (int i=1;prime[i]<=x&&i<=cnt;i++)
	{
		if (x%prime[i]!=0)continue;
		if (!t[prime[i]])v.pb(prime[i]),t[prime[i]]=1;
		while(x%prime[i]==0)x/=prime[i];
	}if (x!=1&&!t[x])v.pb(x),t[x]=1;
	for (int i=0;i<v.size();i++)
	{
		if (v[i]==1)continue;
		int ss=0;
		for (int j=1;j<=n;j++)
			if (a[j]<v[i])ss+=v[i]-a[j];
			else ss+=min(a[j]%v[i],v[i]-a[j]%v[i]);
//		if (ss==0)cout<<v[i]<<endl;
		ans=min(ans,ss);
	}
}

signed main()
{
	srand(time(0));
	n=read();
	for (int i=2;i<=1e6;i++)
	{
		if (f[i])continue;
		prime[++cnt]=i;
		for (int j=i*i;j<=1e6;j+=i)
			f[j]=1;
	}
	for (int i=1;i<=n;i++)a[i]=read(),ans+=a[i]&1;
	random_shuffle(a+1,a+n+1);  
	while(T--)
	{
		int x=rand()%n+1;
		solve(a[x]+1);solve(a[x]);solve(a[x]-1);
	}cout<<ans<<endl;
	return 0;
}