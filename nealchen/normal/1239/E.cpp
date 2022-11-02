#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
template<class T1, class T2> inline bool cmin(T1 &a, const T2 &b) {return b<a?(a=b, true):false;}
template<class T1, class T2> inline bool cmax(T1 &a, const T2 &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-'0', (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
auto rd=read<int>;
int a[50], b[2][25];
std::bitset<50*50000+1> f[51][25];
int main() {
	int n=rd(), sum=0;
	std::generate(a, a+2*n, rd);
	std::sort(a, a+2*n);
	for(int i=2; i<=2*n; ++i) f[i][0].set(0);
	for(int i=2; i<2*n; ++i) {
		sum+=a[i];
		for(int j=1; j<n; ++j) f[i+1][j]=f[i][j]|f[i][j-1]<<a[i];
	}
	for(sum/=2; !f[2*n][n-1].test(sum); --sum);
	b[0][0]=a[0];
	b[1][n-1]=a[1];
	for(int i=2*n, j=n-1, p=n, q=0; i-->2;)
		if(a[i]<=sum&&j&&f[i][j-1].test(sum-a[i])) {
			--j;
			sum-=a[i];
			b[0][--p]=a[i];
		} else {
			b[1][q++]=a[i];
		}
	for(int i=0; i<2; ++i)
		for(int j=0; j<n; ++j)
			printf("%d%c", b[i][j], " \n"[j==n-1]);
	return 0;
}