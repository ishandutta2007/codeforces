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
	int n=rd();
	long long b[2]={};
	for(int i=0; i<n; ++i) {
		int a=rd();
		b[i&1]+=(a+1)/2;
		b[~i&1]+=a/2;
	}
	std::cout<<std::min(b[0], b[1])<<"\n";
	return 0;
}