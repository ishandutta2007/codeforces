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
const int M=3e5+10;
int n,a[M],sum[M],ans;
map<int,int>t[2];
vector<pair<int,int>>e[2][M];

struct ST
{
	int lg2[M],f[25][M];
	void init()
	{
		for (int i=2;i<=n;i++)lg2[i]=lg2[i/2]+1;
		for (int j=1;j<=20;j++)
			for (int i=1;i+(1<<j)-1<=n;i++)
				f[j][i]=min(f[j-1][i],f[j-1][i+(1<<(j-1))]);
	}
	int query(int l,int r)
	{
		int k=lg2[r-l+1];
		return min(f[k][l],f[k][r-(1<<k)+1]);
	}
}T[2];

signed main()
{
	WT
	{
		n=read();ans=0;t[0].clear(),t[1].clear();
		for (int i=1;i<=n;i++)a[i]=read(),sum[i]=a[i]-sum[i-1];
		for (int i=1;i<=n;i++)T[i&1].f[0][i]=sum[i],T[(i&1)^1].f[0][i]=inf;
		T[0].init(),T[1].init();
		for (int i=1;i<=n;i++)
		{
			int l1=n,l2=n;
			int tl=1,tr=(n-i+1)/2,p=0;
			while(tl<=tr)
			{
				int Mid=(tl+tr)>>1;
				if (T[(i&1)^1].query(i,i+Mid*2-1)-sum[i-1]>=0)p=Mid,tl=Mid+1;
				else tr=Mid-1;
			}
			l1=i+p*2;
			tl=1,tr=(n-i)/2,p=0;
			while(tl<=tr)
			{
				int Mid=(tl+tr)>>1;
				if (T[i&1].query(i+1,i+Mid*2)+a[i]-sum[i]>=0)p=Mid,tl=Mid+1;
				else tr=Mid-1;
			}l2=i+p*2+1;
			int pos=min(l1,l2);
			e[i&1][pos].pb(mp(sum[i-1],1)),e[i&1][i-1].pb(mp(sum[i-1],-1)),
			e[(i&1)^1][pos].pb(mp(sum[i]-a[i],1)),e[(i&1)^1][i-2].pb(mp(sum[i]-a[i],-1));
//			cout<<i<<' '<<pos<<endl;
		}
		for (int i=0;i<=n;i++)
		{
			t[i&1][sum[i]]++;
			for (auto x:e[0][i])
				ans+=x.y*t[1][x.x];
			for (auto x:e[1][i])
				ans+=x.y*t[0][x.x];
		}printf("%lld\n",ans);
		for (int i=0;i<=n;i++)e[0][i].clear(),e[1][i].clear();
	}
	return 0;
}
/*
2
2
0 0
10
0 4 4 5 9 6 0 8 5 3 

*/