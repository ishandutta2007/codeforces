#include <cstdio>
#include <vector>
#define meow(args...) fprintf(stderr, args)
const int N=1e6+1, P=998244353;
bool cho[N];
int n, c[N], head[N], next[N<<1], to[N<<1], max[N], maxcho[N], f[N], g[N], follow[N];
long long tot;
int find(int x)
{
	return follow[x]==x?x:(follow[x]=find(follow[x]));
}
void dfs(int x, int fa)
{
	if(x!=1 && !next[head[x]]) {
		tot+=c[x];
		max[x]=c[x];
		maxcho[x]=x;
		cho[x]=1;
		f[x]=g[x]=1;
		return;
	}
	f[x]=1;
	for(int i=head[x]; i; i=next[i])
		if(to[i]!=fa) {
			dfs(to[i], x);
			if(max[to[i]]>max[x]) max[x]=max[to[i]];
		}
	maxcho[x]=-1;
	for(int i=head[x]; i; i=next[i])
		if(to[i]!=fa) {
			if(max[x]==max[to[i]]) {
				g[x]=((long long)f[x]*g[to[i]]+(long long)g[x]*f[to[i]])%P;
				f[x]=(long long)f[x]*f[to[i]]%P;
				if(maxcho[x]==-1) maxcho[x]=maxcho[to[i]]; else maxcho[x]=0;
			} else {
				f[x]=(long long)f[x]*f[to[i]]%P;
				g[x]=(long long)g[x]*f[to[i]]%P;
			}
		}
	if(c[x]<max[x]) {
		cho[maxcho[x]]=false;
		cho[x]=true;
		tot=tot-max[x]+c[x];
		max[x]=c[x];
		maxcho[x]=x;
		f[x]=g[x];
	} else if(c[x]==max[x]) {
		if(maxcho[x]) follow[maxcho[x]]=x;
		maxcho[x]=x;
		cho[x]=true;
		f[x]=(f[x]+g[x])%P;
	}
}
int main()
{
	scanf("%d", &n);
	for(int i=1; i<=n; ++i) scanf("%d", &c[i]);
	for(int i=1, e=2; i<n; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		next[e]=head[u], to[e]=v, head[u]=e++;
		next[e]=head[v], to[e]=u, head[v]=e++;
	}
	for(int i=1; i<=n; ++i) follow[i]=i;
	dfs(1, 0);
	std::vector<int> ans;
	for(int i=1; i<=n; ++i) if(cho[find(i)]||c[i]==0) ans.push_back(i);
	printf("%lld %zu\n", tot, ans.size());
	for(int i: ans) printf("%d ", i);
	return 0;
}