#include <cassert>
#include <cstring>
#include <iostream>
class Remainder {
	static const unsigned P=998244353;
	unsigned v;
	public:
	Remainder(): v(0) {}
	Remainder(const char &orig) {v=orig<0?orig+P:orig;}
	Remainder(const short &orig) {v=orig<0?orig+P:orig;}
	Remainder(int orig) {v=(orig%=(signed)P)<0?orig+P:orig;}
	Remainder(long long orig) {v=(orig%=(signed)P)<0?orig+P:orig;}
	Remainder(const unsigned char &orig): v(orig) {}
	Remainder(const unsigned short &orig): v(orig) {}
	Remainder(const unsigned &orig): v(orig%P) {}
	Remainder(const unsigned long long &orig): v(orig%P) {}
	template<class Type> friend Remainder pow(Remainder base, Type index) {
		Remainder power=1;
		index%=(signed)P-1;
		if(index<0) index+=P-1;
		for(; index; base*=base, index>>=1) if(index&1) power*=base;
		return power;
	}
	Remainder operator-() const {return v?P-v:0;}
	friend Remainder operator*(Remainder a, const Remainder &b) {return a*=b;}
	friend Remainder operator/(Remainder a, const Remainder &b) {return a/=b;}
	friend Remainder operator+(Remainder a, const Remainder &b) {return a+=b;}
	friend Remainder operator-(Remainder a, const Remainder &b) {return a-=b;}
	template<class InputStream> friend InputStream &operator>>(InputStream &a, Remainder &b) {return a>>b.v;}
	template<class OutputStream> friend OutputStream &operator<<(OutputStream &a, const Remainder &b) {return a<<b.v;}
	bool operator==(const Remainder &o) const {return v==o.v;}
	bool operator!=(const Remainder &o) const {return v!=o.v;}
	Remainder &operator+=(const Remainder &o) {
		v+=o.v;
		if(v>P) v-=P;
		return *this;
	}
	Remainder &operator-=(const Remainder &o) {
		if(v<o.v) v+=P-o.v; else v-=o.v;
		return *this;
	}
	Remainder &operator*=(const Remainder &o) {
		v=(unsigned long long)v*o.v%P;
		return *this;
	}
	Remainder &operator/=(const Remainder &o) {return *this*=pow(o, -1);}
};
const int N=51;
int a[N];
Remainder w[N], f[N][N][N];
int main() {
	int n, m;
	Remainder sum, scol[2];
	std::cin>>n>>m;
	for(int i=1; i<=n; ++i) std::cin>>a[i];
	for(int i=1; i<=n; ++i) {
		std::cin>>w[i];
		scol[a[i]]+=w[i];
	}
	sum=scol[0]+scol[1];
	for(int t=1; t<=n; ++t) {
		Remainder ans;
		memset(f, 0, sizeof(f));
		f[0][0][0]=1;
		for(int i=0; i<m; ++i)
			for(int j=0; j<=i; ++j)
				for(int k=0; k<=(a[t]?j:i-j); ++k) {
					Remainder p=(w[t]+(a[t]?k:-k))/(sum+2*j-i), q[]={(scol[0]+j-i)/(sum+2*j-i), (scol[1]+j)/(sum+2*j-i)};
					f[i+1][j+a[t]][k+1]+=p*f[i][j][k];
					f[i+1][j+a[t]][k]+=(q[a[t]]-p)*f[i][j][k];
					f[i+1][j+!a[t]][k]+=q[!a[t]]*f[i][j][k];
				}
		for(int i=0; i<=m; ++i)
			for(int j=0; j<=(a[t]?i:m-i); ++j)
				ans+=f[m][i][j]*(w[t]+(a[t]?j:-j));
		std::cout<<ans<<std::endl;
	}
	return 0;
}