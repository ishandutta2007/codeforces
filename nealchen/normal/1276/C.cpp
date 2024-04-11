#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
inline bool cmin(auto &a, const auto &b) {return b<a?(a=b, true):false;}
inline bool cmax(auto &a, const auto &b) {return a<b?(a=b, true):false;}
template<class Type> Type read() {
	Type a;
	bool b;
	unsigned char c;
	while(c=getchar()-'0', (c>9)&(c!=253));
	for(a=(b=c==253)?0:c; (c=getchar()-'0')<=9; a=a*10+c);
	return b?-a:a;
}
auto rd=read<int>;
const int N=4e5+1;
int a[N], b[N], s[N], v[N];
std::pair<int, int> pair[N];
int main() {
	int n=rd(), m=0, ans=0, h, w;
	std::generate(a, a+n, rd);
	std::sort(a, a+n);
	for(int l=0, r=0; l<n; l=r) {
		while(r<n&&a[l]==a[r]) ++r;
		pair[m++]={r-l, a[l]};
	}
	std::sort(pair, pair+m);
	for(int i=0; i<m; ++i) b[i]=pair[i].first;
	for(int i=1; i<=m; ++i) s[i]=s[i-1]+b[i-1];
	for(int i=1; i<=n/i; ++i) {
		int pos=std::lower_bound(b, b+m, i)-b, j=s[pos]/i+m-pos;
		if(i<=j&&cmax(ans, i*j)) h=i;
	}
	printf("%d\n%d %d\n", ans, h, w=ans/h);
	for(int i=m, j=0; j<ans&&i--; )
		for(int k=0; j<ans&&k<h&&k<b[i]; ++k)
			v[j++]=pair[i].second;
	for(int i=0; i<h; ++i) {
		for(int j=0; j<w; ++j) printf("%d ", v[i+(j+w-i)%w*h]);
		puts("");
	}
	return 0;
}