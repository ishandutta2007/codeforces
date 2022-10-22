#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
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
void ckmax(int &a,int b){a=(a>b?a:b);}
void ckmin(int &a,int b){a=(a<b?a:b);}

const int M=2e5+10;
int n,a[M],deg[M],vis[M];
vector<int>e[M];
queue<int>q1,q[2];

int work()
{
	if (n==1)return 1;
	for (int i=1;i<=n;i++)deg[i]=e[i].size(),vis[i]=0;
	for (int i=1;i<=n;i++)
		if (deg[i]==1)
		{
			if (a[i]==0)q1.push(i);
			else q[a[i]&1].push(i);
		}
	int ans=0;
	while(1)
	{
		if (q1.empty()&&q[1].empty()&&q[0].empty())break;
		ans++;
		while(!q1.empty()||!q[ans&1].empty())
		{
			int u=-1;
			if (q1.empty())u=q[ans&1].front(),q[ans&1].pop();
			else u=q1.front(),q1.pop();
			vis[u]=1;
			for (auto v:e[u])
			{
				deg[v]--;
				if (deg[v]==1)
				{
					if (a[v]==0)q1.push(v);
					else q[a[v]&1].push(v);
				}
			}
		}
	}
	return ans;
}

void solve()
{
	n=read();
	for (int i=1;i<=n;i++)a[i]=read(),e[i].clear();
	for (int i=1;i<n;i++)
	{
		int u=read(),v=read();
		e[u].pb(v),e[v].pb(u);
	}
	int ans=work();
	for (int i=1;i<=n;i++)
		if (a[i]==1)a[i]=2;
		else if (a[i]==2)a[i]=1;
	ckmin(ans,work());
	cout<<ans<<'\n';
}

signed main()
{
	WT solve();
	return 0;
}