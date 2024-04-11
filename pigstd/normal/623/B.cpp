#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int T=read();while(T--) 
#define NO puts("NO");
#define YES puts("YES");
using namespace std;

inline int read()
{
    char c=getchar();int x=0;bool f=0;
    for(;!isdigit(c);c=getchar())f^=!(c^45);
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(f)x=-x;return x;
}

const int inf=1e18;
const int M=1e6+10;
int n,a,b,ans=inf;
int c[M],d[M];
vector<int>v;

int work(int x)
{
	int f=0;
	for (int i=1;i<=n;i++)
	{
		if (c[i]%x==0)d[i]=0;
		else if (c[i]%x==1||c[i]%x==x-1)d[i]=b;
		else d[i]=inf,f=1;
	}
	if (f)
	{
		int l=n,r=1;
		for (int i=1;i<=n;i++)
			if (d[i]==inf)
				l=min(l,i),r=max(r,i);
		int ans=(r-l+1)*a,min1=inf,min2=inf,sum1=0,sum2=0;
		for (int i=1;i<=l;i++)
		{
			min1=min(min1,sum1+(l-i)*a);
			sum1+=d[i];
		}
		for (int i=n;i>=r;i--)
		{
			min2=min(min2,sum2+(i-r)*a);
			sum2+=d[i];
		}ans+=min1+min2;
		return ans;
	}
	else
	{
		int res=0,sum=0,maxn=0;
		for (int i=1;i<=n;i++)
		{
			res+=d[i],sum+=d[i]-a;
			sum=max(sum,0ll),maxn=max(maxn,sum);
		}res-=maxn;
		return res;
	}
}

void find(int x)
{
	for (int i=2;i*i<=x;i++)
	{
		if (x%i==0)
		{
			while(x%i==0)x/=i;
			v.pb(i);
		}
	}
	if (x!=1)v.pb(x);
}

signed main()
{
	n=read(),a=read(),b=read();
	for (int i=1;i<=n;i++)
		c[i]=read();
	find(c[1]),find(c[1]-1),find(c[1]+1);
	find(c[n]),find(c[n]-1),find(c[n]+1);
	for (int i=0;i<v.size();i++)
		ans=min(ans,work(v[i]));//,cout<<v[i]<<' '<<work(v[i])<<endl;
	cout<<ans<<endl;
	return 0;
}