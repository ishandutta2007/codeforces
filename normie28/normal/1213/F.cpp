#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#ifdef DEBUG
#define debug(x) cerr << #x << " " << x << '\n'
#else
#define debug(x)
#endif
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 0x3f3f3f3f, N = 2e5 + 5;
inline int read()
{
    int sum = 0, f = 1;
    char c = getchar();
    while(c>'9'||c<'0') {if(c=='-') f = -f; c = getchar();}
    while(c>='0'&&c<='9') sum = sum*10 + c - 48, c = getchar();
    return sum*f;
}
int n, k, p[N], q[N], dfn[N], low[N], num[N], id, tot, sta[N], top, head[N], cnt, deg[N];
vector <int> G[N], scc[N];
char ans[N];
bool in[N];
struct node
{
	int to, next;
}e[N<<1];
inline void add(int u,int v)
{
	e[++cnt].next = head[u];
	e[cnt].to = v;
	head[u] = cnt;
}
void tarjan(int u)
{
	in[u] = 1;
	low[u] = dfn[u] = ++id;
	sta[++top] = u;
	for(int i=head[u];i;i=e[i].next)
	{
		int v = e[i].to;
		if(!dfn[v])
		{
			tarjan(v);
			low[u] = min(low[u],low[v]);
		}
		else if(in[v])
		{
			low[u] = min(low[u],dfn[v]);
		}
	}
	if(low[u]==dfn[u])
	{
		tot++;
		while(top)
		{
			int tmp = sta[top--];
			in[tmp] = 0;
			num[tmp] = tot;
			scc[tot].push_back(tmp);
			if(tmp==u) break;
		}
	}
}
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cin >> n >> k;
 	for(int i=1;i<=n;i++) cin >> p[i];
 	for(int i=1;i<=n;i++) cin >> q[i];
 	for(int i=1;i<n;i++)
 	{
 		add(p[i],p[i+1]);
 		add(q[i],q[i+1]);
 	}
 	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
 	for(int u=1;u<=n;u++)
 	{
 		for(int i=head[u];i;i=e[i].next)
 		{
 			int v = e[i].to;
 			if(num[u]==num[v]) continue;
 			G[num[u]].push_back(num[v]);
 			deg[num[v]]++;
 		}
 	}
 	if(tot<k)
 	{
 		cout << "NO" << '\n';
 		return 0;
 	}
  	char now = 'a';
  	for(int i=1;i<=n;i++)
  	{
  		if(scc[num[p[i]]].size()==0) continue;
  		for(int x : scc[num[p[i]]])
  		{
  			ans[x] = now;
  		}
  		if(now<'a'+k-1) now++;
  		scc[num[p[i]]].clear();
  	}
 	cout << "YES" << '\n';
 	ans[n+1] = 0;
 	cout << (ans+1) << '\n';
	return 0;
}