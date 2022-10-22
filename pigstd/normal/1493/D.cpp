#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define WT int TT=read();while(TT--) 
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
const int M=2e5+10;
const int Mod=1e9+7;
int n,m,ans=1;
map<int,int>t[M],vis[M];
int p[M],cnt[M];
vector<pair<int,int> >v;

int poww(int a,int b)
{
	int res=1;
	while(b)
	{
		if (b&1)res=res*a%Mod;
		a=a*a%Mod,b>>=1;
	}return res;
}

void get(int x)
{
	v.clear();
	for (int i=2;i*i<=x;i++)
	{
		if (x%i==0)
		{
			int cnt=0;
			while(x%i==0)x/=i,cnt++;
			v.pb(mp(i,cnt));
		}
	}
	if (x!=1)v.pb(mp(x,1));
}

void work(int pp,int x)
{
	get(x);
	for (int i=0;i<v.size();i++)
	{
		int x=v[i].x,y=v[i].y;
//		cout<<x<<' '<<y<<endl;
		t[pp][x]+=y;
		if (vis[pp][x]==0)vis[pp][x]=1,cnt[x]++;
		if (cnt[x]==n)
		{
			int minn=inf;cnt[x]=0;
			for (int j=1;j<=n;j++)
				minn=min(minn,t[j][x]);
			ans=ans*poww(x,minn-p[x])%Mod,p[x]=minn;
			for (int j=1;j<=n;j++)
				if (t[j][x]==minn)vis[j][x]=0;
				else cnt[x]++;
		}
	}
}

signed main()
{
	n=read(),m=read();
	for (int i=1;i<=n;i++)
		{int x=read();work(i,x);}
	while(m--)
	{
		int p=read(),x=read();
		work(p,x);cout<<ans<<endl;
	}
	return 0;
}