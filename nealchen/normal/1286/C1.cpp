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

std::vector<std::string> query(int l, int r) {
	int n=(r-l+1)*(r-l+2)/2;
	std::vector<std::string> res(n);
	std::cout << "? " << l << " " << r << std::endl;
	for (int i = 0; i < n; ++i) {
		std::cin >> res[i];
		std::sort(res[i].begin(), res[i].end());
	}
	std::sort(res.begin(), res.end());
	return res;
}
int main() {
	int n;
	std::vector<std::string> all, bf, dif;
	std::cin >> n;
	all=query(1, n);
	if(n==1) {
		std::cout << "! " << all.front() << std::endl;
		return 0;
	}
	bf=query(2, n);
	dif.reserve(n);
	for(int i=0, j=0; i<all.size(); ++i) {
		if(j==bf.size()||all[i]!=bf[j])
			dif.push_back(all[i]);
		else
			++j;
	}
	auto cmp=[](auto s, auto t) {return s.size()<t.size();};
	std::sort(dif.begin(), dif.end(), cmp);
	std::cout << "! " << dif[0][0];
	for(int i=1; i<n; ++i) {
		const auto &p=dif[i-1], &q=dif[i];
		int lcp=0;
		while(lcp<i && p[lcp]==q[lcp]) ++lcp;
		std::cout << q[lcp];
	}
	std::cout << std::endl;
	return 0;
}