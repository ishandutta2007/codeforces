#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
const int N=1e6+5;
int pa[N], sb[N];
char s[N];
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar(), c-'0'>9&c!='-');
	for(a=(b=c=='-')?0:c-'0'; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
int main() {
	int n, a, b;
	assert(scanf("%s%d%d", s, &a, &b)==3);
	n=strlen(s);
	for(int i=1; i<=n; ++i) pa[i]=(pa[i-1]*10+s[i-1]-'0')%a;
	for(int i=n, p=1; i--; p=p*10%b) sb[i]=(sb[i+1]+(s[i]-'0')*p)%b;
	for(int i=1; i<n; ++i)
		if(s[i]!='0'&&pa[i]==0&&sb[i]==0) {
			printf("YES\n%.*s\n%s\n", i, s, s+i);
			return 0;
		}
	puts("NO");
	return 0;
}