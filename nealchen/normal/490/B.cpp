#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
const int N=1e6+5;
int n, next[N];
bool as_f[N], as_b[N];
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar(), c-'0'>9&c!='-');
	for(a=(b=c=='-')?0:c-'0'; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
int main() {
	int (*rd)()=read<int>, n=rd(), l[2];
	for(int i=0; i<n; ++i) {
		int f=rd(), b=rd();
		next[f]=b;
		as_f[f]=as_b[b]=true;
	}
	for(int i=1; i<=1e6; ++i) if(as_f[i]&&!as_b[i]) l[0]=i;
	l[1]=next[0];
	for(int i=0; i<n; ++i) {
		printf("%d ", l[i&1]);
		l[i&1]=next[l[i&1]];
	}
	puts("");
	return 0;
}