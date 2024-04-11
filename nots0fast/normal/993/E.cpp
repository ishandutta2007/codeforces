#include <bits/stdc++.h>

using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(x) setprecision(x)<<fixed
#define ss second
#define fori(v) for(lli i=0; i<v; i++)
#define forj(v) for(int j=0; j<v; j++)
#define fork(v) for(int k=0; k<v; k++)
#define forl(v) for(int l=0; l<v; l++)
#define fort(v) for(int t=0; t<v; t++)
#define forz(v) for(int z=0; z<v; z++)
#define lli long long int
#define MAX 200010
#define ld double
#define M_PI acos(-1.0)
lli inf = pow(10,9)+10;
lli modulo = pow(10,9)+7;
double eps = 1e-11;
ifstream in;
ofstream out;
//#define cin in
//#define cout out

namespace custom_complex {
//*/

template<class T> struct cplx {
  T x, y; cplx() {x = 0.0; y = 0.0;}
  cplx(T nx, T ny=0) {x = nx; y = ny;}
  cplx operator+(const cplx &c) const {return {x + c.x, y + c.y};}
  cplx operator-(const cplx &c) const {return {x - c.x, y - c.y};}
  cplx operator*(const cplx &c) const {return {x*c.x - y*c.y, x*c.y + y*c.x};}
  cplx& operator*=(const cplx &c) { return *this={x*c.x-y*c.y, x*c.y+y*c.x}; }
  // Only supports right scalar multiplication like p*c
  template<class U> cplx operator*(const U &c) const {return {x*c,y*c};}
  template<class U> cplx operator/(const U &c) const {return {x/c,y/c};} };
#define polar(r,a)  (pt){r*cos(a),r*sin(a)}
typedef cplx<ld> pt;
typedef vector<pt> pol;
pt operator*(ld c, const pt p) { return {p.x*c,p.y*c};} // for left mult. c*p
// useful for debugging
ostream&operator<<(ostream &o,const pt &p){o<<"("<<p.x<<","<<p.y<<")";return o;}
ld cp(const pt& a, const pt& b) { return a.x*b.y - b.x*a.y; }
ld dp(const pt& a, const pt& b) { return a.x*b.x + a.y*b.y; }
inline ld abs(const pt &a) {return sqrt(a.x*a.x + a.y*a.y);}
inline ld arg(const pt &a) {return atan2(a.y,a.x);}
ld ang(pt &a, pt &b, pt &c) { return atan2(cp(a-b,b-c),dp(a-b,b-c)); }
namespace std{
template<class T>inline bool operator<(const cplx<T>& a,const cplx<T>& b){
  return a.x<b.x || (a.x == b.x && a.y<b.y); } };
inline bool cmp_lex(const pt& a, const pt& b) {
  return a.x<b.x-eps||(a.x<b.x+eps&&a.y<b.y-eps);}
inline bool cmp_lex_i(const pt& a, const pt& b) {
  return a.y<b.y-eps||(a.y<b.y+eps&&a.x<b.x-eps);}
//*!
}
using namespace custom_complex;
typedef cplx<ld> Complex;
// Forward Transform - If using this for convolution, make sure to
// add n leading zeros to a vector of length n
vector<Complex> rfft(vector<Complex> a, int dir=1) {
  int n = a.size(); if (n == 1) return a;
  Complex wn = polar( (ld)1, (ld)dir*2*M_PI/n ), w = 1;
  vector<Complex> a_[2], y_[2], y(n);
  for (int i = 0; i < n; ++i) a_[i&1].push_back(a[i] / (ld)(dir>0 ? 1 : 2));
  y_[0] = rfft(a_[0], dir); y_[1] = rfft(a_[1], dir);
  for (int k = 0; k < n/2; ++k, w*=wn) {
    y[k] = y_[0][k] + w*y_[1][k];
    y[k + n/2] = y_[0][k] - w*y_[1][k];
  } return y; }
// Inverse Transform - this time you don't care about adding zeros
vector<Complex> ifft(vector<Complex> a) { return rfft(a, -1); }
// *** Fast Fourier Transform (Iterative) ***
// Reverse-bitmasking adder. rev_incr(a,n) returns REV(REV(a)+1)
inline int rev_incr(int a, int n) { int msk = n/2, cnt=0;
  while ( a&msk ) { cnt++; a<<=1; }
  a &= msk-1; a |= msk;
  while ( cnt-- ) a >>= 1;
  return a; }
// Compute in V the discrete fourier transform of v
// dir=1: forward transform, evaluates polynomial at complex roots of unity
// dir=-1: inverse transform, interpolates point-value form to coefficients
vector<Complex> FFT(vector<Complex> v, int dir=1) {
  Complex wm,w,u,t; int n = v.size(); vector<Complex> V(n);
  for (int k=0,a=0; k<n; ++k, a=rev_incr(a,n))
    V[a] = v[k] / (ld)(dir>0 ? 1 : n);
  for (int m=2; m<=n; m<<=1) {
    wm = polar( (ld)1, (ld)dir*2*M_PI/m );
    for (int k=0; k<n; k+=m) {
      w = 1;
      for (int j=0; j<m/2; ++j, w*=wm) {
        u = V[k + j];
        t = w * V[k + j + m/2];
        V[k + j] = u + t;
        V[k + j + m/2] = u - t;
      } } } return V; }
//! See problem 30-6 in CLRS for more details on the integer FFT
//! hints for integer version:
//! 440564289 and 1713844692 are inverses and 2^27th roots of 1 mod p=(15<<27)+1
//! Precompute inverses for integer FFT, otherwise it will be very slow.
// Multiply two polynomials sum_i a[i]x^i and sum_i b[i]x^i
vector<ld> convolution(vector<ld> &a, vector<ld> &b) {
  int sz = a.size()+b.size()-1;
  int n  = 1<<int(ceil(log2(sz)));
  vector<Complex> av(n,0), bv(n,0), cv;
  for (int i=0; i<a.size(); i++) av[i] = a[i];
  for (int i=0; i<b.size(); i++) bv[i] = b[i];
  cv = FFT(bv); bv = FFT(av);
  for (int i=0; i<n; i++) av[i] = bv[i]*cv[i];
  cv = FFT(av, -1);
  // cv is now the convolution of a and b: cv[k] = sum_(i+j=k) a[i]*b[j]
  vector<ld> c(sz);
  for (int i=0; i<sz; i++)
    c[i] = cv[i].x + 0.5; // if result should be int, use int(cv[i].real()+0.5)
  return c; }
lli sums[MAX] = {};
int arr[MAX];
int eded;
void add(vector<ld> &a){
	fori(a.size())
		sums[i]+=a[i];
}
void div_conquer(int l, int r){
	if(l==r){
		if(arr[l]>=eded)
			++sums[0];
		else
			++sums[1];
		return ;
	}
	div_conquer(l,(l+r)/2);  div_conquer((l+r)/2+1,r);
	vector<ld> a , b;
	int i = (l+r)/2;
	a.push_back(0); b.push_back(0);
	for( ; i>=l; i--){
		if(arr[i] < eded)	a.push_back(1);
		else 				a[a.size()-1]++;
	}
	for( i=(l+r)/2+1; i<=r; i++){
		if(arr[i] < eded)	b.push_back(1);
		else 				b[b.size()-1]++;
	}
	vector<ld> ans = convolution(a,b);
//	cout<<"l r :  "<<l<<" "<<r<<endl;
//	fori(ans.size()){
//		cout<<i<<" "<<ans[i]<<endl;
//	}
//	cout<<endl;
	add(ans);
}
void deal(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n>>eded;
	fori(n)		cin>>arr[i];
	div_conquer(0,n-1);
	fori(n+1)
		cout<<sums[i]<<' ';
}
int main() {
//	while(1)
	deal();
}