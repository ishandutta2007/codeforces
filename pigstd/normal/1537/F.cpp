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

const int M=2e5+10;
int n,m,a[M],d[M],F=1;
vector<int>e[M];

void dfs(int u,int x)
{
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		if (d[to])
		{
			if (d[to]!=x)
				F=0;
		}
		else d[to]=x,dfs(to,x==1?2:1);
	}
}

signed main()
{
	WT
	{
		n=read(),m=read();F=1;
		for (int i=1;i<=n;i++)a[i]=read(),e[i].clear(),d[i]=0;
		for (int i=1;i<=n;i++)a[i]-=read();
		for (int i=1;i<=m;i++)
		{
			int u=read(),v=read();
			e[u].pb(v),e[v].pb(u);
		}d[1]=1;dfs(1,2);
		if (F)
		{
			int cnt1=0,cnt2=0;
			for (int i=1;i<=n;i++)
				if (d[i]==1)cnt1+=a[i];
				else cnt2+=a[i];
//			cnt1=abs(cnt1),cnt2=abs(cnt2);
			if (cnt1!=cnt2)NO
			else YES
		}
		else
		{
			int cnt=0;
			for (int i=1;i<=n;i++)
				cnt+=a[i];
			cnt=abs(cnt);
			if (cnt&1)NO
			else YES
		}
	}
	return 0;
}