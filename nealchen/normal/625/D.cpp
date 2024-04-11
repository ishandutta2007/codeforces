#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
const int N=1e5+1;
char str[N];
int s[N], t[N];
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
void construct(int s, int *a, int *b) {
	if(s<10) {
		*a=s;
		*b=0;
	} else {
		*a=9;
		*b=s-9;
	}
}
bool solve(int n, int up) {
	for(int i=0, j=n; i<j--; ++i) {
		s[i]+=up*10;
		up=0;
		if(i==j) {
			if(s[i]%2==1||s[i]==-1) return false;
			t[i]=s[i]/2;
			break;
		}
		if(s[i]-s[j]>=10) {
			s[j]+=10;
			--s[j-1];
		}
		if(i!=j-1&&s[i]==s[j]+1) --s[i], up=1;
		if(s[i]==19||s[j]==-1||s[i]!=s[j]) return false;
		construct(s[i], t+i, t+j);
		if(i==j-1) break;
	}
	for(int i=0; i<n; ++i) meow("%d ", s[i]);
	meow("\n");
	return t[0];
}
int main() {
	int n;
	assert(scanf("%s", str)==1);
	n=strlen(str);
	for(int i=0; i<n; ++i) s[i]=str[i]-'0';
	if(solve(n, 0)) {
		for(int i=0; i<n; ++i) str[i]=t[i]+'0';
		puts(str);
	} else if(str[0]=='1'&&n>1) {
		for(int i=1; i<n; ++i) s[i-1]=str[i]-'0';
		if(solve(n-1, 1)) {
			for(int i=1; i<n; ++i) str[i]=t[i-1]+'0';
			puts(str+1);
		} else puts("0");
	} else puts("0");
	return 0;
}