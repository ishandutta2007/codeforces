#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define WT int T;cin>>T;while(T--) 
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

const int M=4e5+10;
int p1[M],p2[M],n,m;
vector<int>e[M];

signed main()
{
	WT
	{
		cin>>n>>m;
		for (int i=1;i<=n;i++)
		{
			e[i].pb(0);string s;cin>>s; 
			for (int j=1;j<=m;j++)
				if (s[j-1]=='.')e[i].pb(0);
				else e[i].pb(1);
		}int ans=1e18;
		for (int i=1;i<=n;i++)
		{
			p1[i]=0;
			for (int j=1;j<=m;j++)p1[i]+=e[i][j]^1;
		}
		for (int j=1;j<=m;j++)
		{
			p2[j]=0;
			for (int i=1;i<=n;i++)p2[j]+=e[i][j]^1;
		}
		for (int i=1;i<=n;i++)
			for (int j=1;j<=m;j++)
				ans=min(ans,p1[i]+p2[j]+(e[i][j]?0:-1));
		cout<<ans<<endl;
		for (int i=1;i<=n;i++)e[i].clear();
	}
	return 0;
}
/*
1
3 3
.*.
*.*
.*.

*/