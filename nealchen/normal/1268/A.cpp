#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-48, (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-48)<=9; a=a*10+c);
	return b?-a:a;
}
auto rd=read<int>;
const int N=2e5+5;
int n, k;
char s[N];
int main() {
	bool ok=true;
	assert(scanf("%d%d%s", &n, &k, s)==3);
	for(int i=0; i<n; i+=k) {
		int r=strncmp(s, s+i, k);
		if(r>0) break;
		if(r<0) ok=false;
	}
	if(!ok) {
		ok=true;
		for(int i=k; i--; ) {
			s[i]+=ok;
			ok=s[i]>'9';
			if(ok) s[i]='0';
		}
		if(ok) {
			++n;
			s[0]='1';
			for(int i=1; i<k; ++i) s[i]='0';
		}
	}
	printf("%d\n", n);
	for(int i=k; i<n; ++i) s[i]=s[i%k];
	puts(s);
	return 0;
}