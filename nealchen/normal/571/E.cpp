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

typedef long long s64;
typedef std::valarray<s64> Vector;

void gg() {
	puts("-1");
	exit(0);
}

s64 exgcd(s64 a, s64 b, s64 &x, s64 &y) {
	if(b==0) {
		x=1, y=0;
		return a;
	}
	s64 d=exgcd(b, a%b, y, x);
	y-=a/b*x;
	return d;
}
struct Rem {
	s64 r, d;
	Rem &operator&=(const Rem &o) {
		s64 x, y, g=exgcd(d, o.d, x, y), rhs=o.r-r;
		if(rhs%g!=0) gg();
		r+=rhs*x%o.d*(d/g);
		d*=o.d/g;
		if(r<0) r+=d;
		return *this;
	}
};

const int N=100;
int m, aval[N], bval[N];
Vector a[N], b[N];
std::vector<int> prime;
void gl(Vector x) {
	typedef unsigned u32;
	typedef unsigned long long u64;
	const u32 P=1e9+7;
	u32 ans=1;
	for(int i=0; i<m; ++i) {
		u64 b=prime[i];
		for(int e=x[i]%(P-1); e; b=b*b%P, e>>=1) if(e&1) ans=ans*b%P;
	}
	printf("%u\n", ans);
	exit(0);
}
s64 ddiv(s64 a, s64 b) {
	if(b==0) {
		if(a!=0) gg();
		return -1;
	}
	if(a%b!=0) gg();
	a/=b;
	if(a<0) gg();
	return a;
}
s64 ddiv(Vector a, Vector b) {
	s64 res=-1;
	for(int i=0; i<m; ++i) {
		s64 v=ddiv(a[i], b[i]);
		if(v==-1) continue;
		if(res!=v&&res!=-1) gg();
		res=v;
	}
	return res;
}
void extract(int n) {
	for(auto p: prime) while(n%p==0) n/=p;
	for(int p=2; 1ll*p*p<=n; ++p)
		if(n%p==0) {
			while(n%p==0) n/=p;
			prime.push_back(p);
		}
	if(n>1) prime.push_back(n);
}
Vector factor(int n) {
	Vector res(m);
	for(int i=0; i<m; ++i) {
		int p=prime[i];
		while(n%p==0) ++res[i], n/=p;
	}
	return res;
}
int main() {
	int n=rd();
	for(int i=0; i<n; ++i) extract(aval[i]=rd()), extract(bval[i]=rd());
	m=prime.size();
	for(int i=0; i<n; ++i) a[i]=factor(aval[i]), b[i]=factor(bval[i]);
	for(int i=0; i<m; ++i)
		for(int j=0; j<n; ++j)
			if(b[j][i]==0) {
				for(int k=0; k<n; ++k) {
					s64 nk=ddiv(a[j][i]-a[k][i], b[k][i]);
					if(nk!=-1) {
						Vector x=a[k]+nk*b[k];
						for(int l=0; l<n; ++l) ddiv(x-a[l], b[l]);
						gl(x);
					}
				}
				break;
			}
	int k=0;
	while(k<m&&b[0][k]==0) ++k;
	if(k==m) gl(a[0]);
	for(int i=k+1; i<m; ++i)
		if(b[0][i]!=0)
			for(int j=1; j<n; ++j) {
				s64 n0=ddiv((a[j][i]-a[0][i])*b[j][k]-(a[j][k]-a[0][k])*b[j][i], b[0][i]*b[j][k]-b[0][k]*b[j][i]);
				if(n0!=-1) {
					Vector x=a[0]+n0*b[0];
					for(int l=0; l<n; ++l) ddiv(x-a[l], b[l]);
					gl(x);
				}
			}
	Rem ans={0, 1};
	for(int i=0; i<n; ++i) ans&={a[i][k]%b[i][k], b[i][k]};
	for(int i=0; i<n; ++i) if(ans.r<a[i][k]) ans.r+=((a[i][k]-ans.r-1)/ans.d+1)*ans.d;
	gl(a[0]+(ans.r-a[0][k])/b[0][k]*b[0]);
	return 0;
}