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
int main() {
	int r=rd(), c=rd();
	if(r==1&&c==1) {
		puts("0");
		return 0;
	}
	if(c>=2) {
		for(int i=1; i<=r; ++i) {
			for(int j=1; j<=c; ++j) printf("%d ", i*(r+j));
			puts("");
		}
	} else {
		for(int i=1; i<=r; ++i) printf("%d\n", i+1);
	}
	return 0;
}