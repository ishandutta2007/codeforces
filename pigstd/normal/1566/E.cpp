//AFO countdown:???
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
int f[M],n,ans;
vector<int>e[M]; 

void dfs(int u,int fa)
{
	int cnt1=0,cnt2=0;
	for (int i=0;i<e[u].size();i++)
	{
		int to=e[u][i];
		if (to==fa)continue;
		cnt1++,dfs(to,u),cnt2+=f[to];
	}
	if (cnt2==0)f[u]=1;
	if (cnt2>=1)ans+=cnt2-1;
}

signed main()
{
	WT
	{
		n=read();ans=0;
		for (int i=0;i<=n;i++)f[i]=0,e[i].clear();
		for (int i=1;i<n;i++)
		{
			int u=read(),v=read();
			e[u].pb(v),e[v].pb(u);
		}e[0].pb(1);
		dfs(0,0);
		/*int res=0;
		for (int i=0;i<e[1].size();i++)
			res+=f[e[1][i]]==0;
		res=min(res,(int)e[1].size()-1);
		ans-=res;cout<<ans<<endl;*/
		cout<<ans+1<<endl;
	}
	return 0;
}