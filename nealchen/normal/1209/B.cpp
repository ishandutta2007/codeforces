#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
int a[100], b[100];
char s[105];
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar(), c-'0'>9&c!='-');
	for(a=(b=c=='-')?0:c-'0'; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
int main() {
	int n, ans=0;
	assert(scanf("%d%s", &n, s)==2);
	for(int i=0; i<n; ++i) assert(scanf("%d%d", a+i, b+i)==2);
	for(int i=0; i<=2520; ++i) {
		for(int j=0; j<n; ++j) if(i>=b[j]&&(i-b[j])%a[j]==0) s[j]^=1;
		cmax(ans, std::count(s, s+n, '1'));
	}
	printf("%d\n", ans);
	return 0;
}