#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
const int N=2005;
int n, a[N], b[N];
bool vis[N], viz[N];
int main() {
	assert(scanf("%d", &n)==1);
	for(int i=0; i<n; ++i) assert(scanf("%d", a+i)==1);
	memcpy(b, a, n*sizeof(int));
	std::sort(b, b+n);
	int m=std::unique(b, b+n)-b;
	for(int i=0; i<n; ++i) a[i]=std::lower_bound(b, b+m, a[i])-b;
	int ans=n-1;
	for(int l=0, r; l<n; ++l) {
		memcpy(viz, vis, m);
		for(r=n-1; r>=l&&!viz[a[r]]; --r) viz[a[r]]=true;
		cmin(ans, r-l+1);
		if(vis[a[l]]) break;
		vis[a[l]]=true;
	}
	printf("%d\n", ans);
	return 0;
}