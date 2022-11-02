#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#define meow(args...) fprintf(stderr, args)
const int N=2e5+5;
int last[10], first[10];
char s[N], ans[N];
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
	int t;
	assert(scanf("%d", &t)==1);
	while(t--) {
		int n;
		assert(scanf("%d%s", &n, s)==2);
		for(int i=0; i<10; ++i) first[i]=n;
		for(int i=n; i--; ) first[s[i]-'0']=i;
		for(int i=0; i<10; ++i) last[i]=-1;
		for(int i=0; i<n; ++i) last[s[i]-'0']=i;
		strcpy(ans, "-");
		for(int i=0; i<=10; ++i) {
			int min=n, max=-1;
			bool ok;
			ok=true;
			for(int j=0; j<i; ++j)
				for(int k=0; k<j; ++k)
					ok&=last[k]<=first[j];
			if(!ok) continue;
			ok=true;
			for(int j=i+1; j<10; ++j)
				for(int k=i+1; k<j; ++k)
					ok&=last[k]<=first[j];
			if(!ok) continue;
			for(int j=0; j<i; ++j) cmax(max, last[j]);
			for(int j=i+1; j<10; ++j) cmin(min, first[j]);
			ok=true;
			for(int j=min+1; j<max; ++j) ok&=s[j]-'0'!=i;
			if(!ok) continue;
			for(int j=0; j<n; ++j) ans[j]='1'+(s[j]-'0'>i||s[j]-'0'==i&&j<max);
			ans[n]=0;
			break;
		}
		puts(ans);
	}
	return 0;
}