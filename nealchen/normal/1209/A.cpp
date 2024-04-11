#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
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
	bool vis[101]={};
	int n=read<int>(), a[100], ans=0;
	std::generate(a, a+n, read<int>);
	std::sort(a, a+n);
	for(int i=0; i<n; ++i) {
		if(vis[a[i]]) continue;
		for(int j=a[i]; j<=100; j+=a[i]) vis[j]=true;
		++ans;
	}
	printf("%d\n", ans);
	return 0;
}