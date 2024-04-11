#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
const int N=1e5+5;
int fa[N];
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
int find(int x) {return x==fa[x]?x:(fa[x]=find(fa[x]));}
int main() {
	int (*rd)()=read<int>, n=rd(), k=rd(), ans=0;
	for(int i=0; i<n; ++i) fa[i]=i;
	while(k--) {
		int x=rd()-1, y=rd()-1;
		if(find(x)==find(y)) ++ans; else fa[find(x)]=find(y);
	}
	printf("%d\n", ans);
	return 0;
}