#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)

struct Edge {
	int a, b, d;
	bool operator<(const Edge &o) const {return d<o.d;}
	bool operator==(const Edge &o) const {return d==o.d;}
};
int n, len;
unsigned lift[30][150][5], (*g)[5]=lift[0], sum[30][150][5], dis[150][5];
Edge e[150];
inline void set(unsigned set[], int bit) {set[bit/32]|=1<<(bit%32);}
inline bool test(unsigned set[], int bit) {return set[bit/32]>>(bit%32)&1;}
void zero(unsigned dst[][5]) {
	for(int i=0; i<n; ++i) memset(dst[i], 0, len*sizeof(unsigned));
}
void unit(unsigned dst[][5]) {
	zero(dst);
	for(int i=0; i<n; ++i) set(dst[i], i);
}
void copy(unsigned dst[][5], unsigned src[][5]) {
	for(int i=0; i<n; ++i) memcpy(dst[i], src[i], len*sizeof(unsigned));
}
bool singlemul(int x, int y, unsigned l[][5], unsigned r[][5]) {
	for(int i=0; i<n; ++i)
		if(test(l[x], i)&test(r[i], y)) return true;
	return false;
}
void mul(unsigned dst[][5], unsigned l[][5], unsigned r[][5], unsigned base[][5]=NULL) {
	static unsigned tmp[150][5];
	if(base==NULL) zero(tmp); else copy(tmp, base);
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			if(test(l[i], j))
				for(int k=0; k<len; ++k)
					tmp[i][k]|=r[j][k];
	copy(dst, tmp);
}
int main() {
	int m;
	assert(scanf("%d%d", &n, &m)==2);
	len=(n+31)/32;
	for(int i=0; i<m; ++i) {
		int a, b, d;
		assert(scanf("%d%d%d", &a, &b, &d)==3);
		e[i]={a-1, b-1, d};
	}
	zero(g);
	unit(dis);
	std::sort(e, e+m);
	if(e[0].d!=0) {
		puts("Impossible");
		return 0;
	}
	for(int i=0; i<m; ++i) {
		int cur=0, lim=(i+1==m)?n:(e[i+1].d-e[i].d);
		set(g[e[i].a], e[i].b);
		if(lim==0) continue;
		unit(sum[0]);
		for(int j=1; (1<<j)<=lim; ++j) {
			mul(lift[j], lift[j-1], lift[j-1]);
			mul(sum[j], sum[j-1], lift[j-1], sum[j-1]);
		}
		for(int j=31-__builtin_clz(lim); j>=0; --j)
			if(cur+(1<<j)<=lim && !singlemul(0, n-1, dis, sum[j])) {
				cur+=1<<j;
				mul(dis, dis, lift[j]);
			}
		if(cur<lim) {
			printf("%d\n", e[i].d+cur);
			return 0;
		}
	}
	puts("Impossible");
	return 0;
}