#include <stdio.h>
#include <assert.h>
#include <string.h>
#define meow(args...) fprintf(stderr, args)
const int N=1e5+1, M=4e5, P=1e9+7;
bool vis[N];
int to[M], head[N], next[M], cnt[64][2];
long long weight[M], xorsum[N], base[64];
void add_edge(int u, int v, long long w) {
	static int e=0;
	to[e]=v;
	weight[e]=w;
	next[e]=head[u];
	head[u]=e++;
}
void dfs(int u) {
	vis[u]=true;
	for(int i=0; i<64; ++i) ++cnt[i][xorsum[u]>>i&1];
	for(int i=head[u]; ~i; i=next[i])
		if(vis[to[i]]) {
			long long ins=xorsum[u]^xorsum[to[i]]^weight[i];
			for(int j=64; j--; )
				if(ins>>j&1)
					if(base[j])
						ins^=base[j];
					else {
						base[j]=ins;
						break;
					}
		} else {
			xorsum[to[i]]=xorsum[u]^weight[i];
			dfs(to[i]);
		}
}
int main() {
	int n, m, ans=0;
	assert(scanf("%d%d", &n, &m)==2);
	memset(head+1, -1, n*sizeof(int));
	while(m--) {
		int u, v;
		long long w;
		assert(scanf("%d%d%I64d", &u, &v, &w)==3);
		add_edge(u, v, w);
		add_edge(v, u, w);
	}
	for(int i=1; i<=n; ++i)
		if(!vis[i]) {
			long long size, nbase=0, orsum=0;
			nbase=0;
			memset(cnt, 0, sizeof(cnt));
			memset(base, 0, sizeof(base));
			dfs(i);
			size=cnt[0][0]+cnt[0][1];
			size=size*(size-1)/2%P;
			for(int j=0; j<64; ++j) {
				nbase+=base[j]!=0;
				orsum|=base[j];
			}
			if(nbase) size=(1ll<<nbase-1)%P*size%P;
			nbase=(1ll<<nbase)%P;
			for(int j=0; j<64; ++j) {
				int cur=orsum>>j&1?size:nbase*cnt[j][0]%P*cnt[j][1]%P;
				ans=(ans+(1ll<<j)%P*cur)%P;
			}
		}
	printf("%d\n", ans);
	return 0;
}