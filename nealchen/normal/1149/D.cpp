#include <cstdio>
#include <cstring>
int to[400], c[200], pa[70], size[70], id[70], f[1<<17][70], q[256], headb[70], nextb[400], head[70], next[400];
bool in[70];
int find(int x) {
	return pa[x]==x?x:(pa[x]=find(pa[x]));
}
int main() {
	int n, m, a, b, tot=0;
	scanf("%d%d%d%d", &n, &m, &a, &b);
	for(int i=0; i<n; ++i) pa[i]=i, size[i]=1;
	memset(headb, -1, n*sizeof(int));
	for(int i=0; i<m; ++i) {
		int u, v;
		scanf("%d%d%d", &u, &v, c+i);
		--u, --v;
		to[2*i]=v, to[2*i+1]=u;
		if(c[i]==a) {
			int x=find(u), y=find(v);
			if(x!=y) {
				pa[x]=y;
				size[y]+=size[x];
			}
		} else {
			nextb[2*i]=headb[u];
			headb[u]=2*i;
			nextb[2*i+1]=headb[v];
			headb[v]=2*i+1;
		}
	}
	for(int i=0; i<n; ++i) if(i==pa[i]) id[i]=size[i]>3?tot++:-1;
	for(int i=0; i<n; ++i) id[i]=id[find(i)];
	int off;
	for(off=1; off<=n; off*=2);
	for(int s=0; s<(1<<tot); ++s) {
		int *F=f[s];
		memset(F, 63, n*sizeof(int));
		if(id[0]==-1||s>>id[0]&1) F[0]=0;
		for(int i=0; i<n; ++i) {
			if(id[i]!=-1&&s>>id[i]&1) {
				int *G=f[s^(1<<id[i])];
				for(int e=headb[i]; ~e; e=nextb[e]) {
					int update=G[to[e]]+b;
					if(update<F[i]) F[i]=update;
				}
			}
		}
		memset(head, -1, n*sizeof(int));
		for(int i=0; i<2*m; ++i) {
			int u=to[i^1], v=to[i];
			if(find(u)==find(v) ? (c[i/2]==a) : (id[v]==-1)) {
				next[i]=head[u];
				head[u]=i;
			}
		}
		unsigned char ql=0, qr=0;
		for(int i=0; i<n; ++i) {
			if(F[i]<1e9) in[q[qr++]=i]=true;
		}
		while(ql!=qr) {
			int u=q[ql++];
			in[u]=false;
			for(int e=head[u]; ~e; e=next[e]) {
				int v=to[e], update=F[u]+c[e/2];
				if(update<F[v]) {
					F[v]=update;
					if(!in[v]) in[q[qr++]=v]=true;
				}
			}
		}
	}
	for(int i=0; i<n; ++i) printf("%d ", f[(1<<tot)-1][i]);
	puts("");
	return 0;
}