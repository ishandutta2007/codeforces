#include <bits/stdc++.h>
#define meow(args...) fprintf(stderr, args)
typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;
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
int (*rd)()=read<int>;
//const u32 P=;
//inline u32 &inc(u32 &a, u32 b) {return (a+=b)<P?a:(a-=P);}
//inline u32 &dec(u32 &a, u32 b) {return (a-=b)&0x80000000?(a+=P):a;}
//inline u32 sum(u32 a, u32 b) {return (a+=b)<P?a:a-P;}
//inline u32 dif(u32 a, u32 b) {return (a-=b)&0x80000000?a+P:a;}
//u64 power(u64 a, int b) {
//	u64 ans=1;
//	for(; b; a=a*a%P, b/=2) if(b&1) ans=ans*a%P;
//	return ans;
//}

std::valarray<int> f[101];
std::vector<std::string> query(int l, int r) {
	if(l>r) return {};
	int n=(r-l+1)*(r-l+2)/2;
	std::vector<std::string> res(n);
	std::cout<<"? "<<l<<" "<<r<<std::endl;
	for(int i=0; i<n; ++i) {
		std::cin>>res[i];
		std::sort(res[i].begin(), res[i].end());
	}
	std::sort(res.begin(), res.end());
	return res;
}
int main() {
	int n, m;
	std::cin >> n;
	m=(n+1)/2;
	auto half=query(1, m), bf=query(2, m);
	std::vector<std::string> dif(m);
	std::set_difference(half.begin(), half.end(), bf.begin(), bf.end(), dif.begin());
	auto cmp=[](auto s, auto t) {return s.size()<t.size();};
	std::sort(dif.begin(), dif.end(), cmp);
	std::string ans(n, '?');
	for(int i=0; i<m; ++i) {
		int lcp=0;
		while(lcp<i&&dif[i-1][lcp]==dif[i][lcp]) ++lcp;
		ans[i]=dif[i][lcp];
	}

	auto all=query(1, n);
	for(int i=1; i<=n; ++i) f[i].resize(26);
	for(const auto &s: all) {
		for(char c: s) ++f[s.size()][c-'a'];
	}
	f[0]=f[1];
	for(int i=1; i<m; ++i) f[i]=f[i+1]-f[i];
	for(int i=0; i<m-1; ++i) f[i]-=f[i+1];
	for(int i=0; i<m; ++i) {
		if(2*i<n-1) --f[i][ans[i]-'a'];
		ans[n-i-1]=std::find(begin(f[i]), end(f[i]), 1)-begin(f[i])+'a';
	}
	std::cout<<"! "<<ans<<std::endl;
	return 0;
}