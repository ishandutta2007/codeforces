#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
const int N=1e5;
int n, dis[200][200], e[200][200];
long long a[N];
long long read() {
	long long a=0;
	unsigned char c;
	while((c=getchar()-'0')>9);
	while(a=a*10+c, (c=getchar()-'0')<=9);
	return a;
}
int main() {
	assert(scanf("%d", &n)==1);
	for(register int i=0; i<n; ++i) {
		a[i]=read();
		if(a[i]==0) --i, --n;
	}
	if(n>128) {
		puts("3");
		return 0;
	}
	for(register int i=0; i<n; ++i)
		for(register int j=0; j<n; ++j)
			if(i==j) e[i][j]=0; else if(a[i]&a[j]) e[i][j]=1; else e[i][j]=1e8;
	memcpy(dis, e, sizeof(e));
	int ans=1e8;
	for(register int i=0; i<n; ++i) {
		for(register int j=0; j<n; ++j) if(i!=j)
			for(register int k=0; k<n; ++k) if(i!=k&&j!=k)
				cmin(ans, dis[j][k]+e[i][j]+e[i][k]);
		for(register int j=0; j<n; ++j) if(i!=j)
			for(register int k=0; k<n; ++k) if(i!=k&&j!=k)
				cmin(dis[j][k], dis[i][j]+dis[i][k]);
	}
	printf("%d\n", ans>n?-1:ans);
	return 0;
}