#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<unordered_set>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#include<cassert>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define rreps(X,S,Y) for (int (X) = (Y)-1;(X) >= (S);--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define Endl endl
#define NL <<"\n"

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
template<class T> using vv=vector<vector<T>>;
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
//#undef NUIP
#ifdef NUIP
#include "benri.h"
#else
#define out(args...)
#endif
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
const ll MOD=1e9+7; //998244353

using Double = long double;

void fft(vector<complex<Double>> &dst,
	 const vector<complex<Double>> &src, int n, bool inv = false){
  copy(all(src),dst.begin());
  for(int i = 0, j = 1; j < n - 1; ++j){
    for(int k = n >> 1; k > (i ^= k); k >>= 1){ }
    if(j < i){ swap(dst[i], dst[j]); }
  }
  Double theta = (inv ? -2.0 : 2.0) * 3.14159265358979 / n;
  for(int mh = 1; (mh << 1) <= n; mh <<= 1){
    const int m = (mh << 1);
    int irev = 0;
    for(int i = 0; i < n; i += m){
      const complex<Double> w = exp(complex<Double>(0, theta * irev));
      for(int k = n >> 2; k > (irev ^= k); k >>= 1){ }
      for(int j = i; j < mh + i; ++j){
	const int k = j + mh;
	const complex<Double> x = dst[j] - dst[k];
	dst[j] += dst[k];
	dst[k] = w * x;
      }
    }
  }
  if(inv){
    const Double r = 1.0 / n;
    for(int i = 0; i < n; ++i){ dst[i] *= r; }
  }
}
vector<Double> conv(const vector<Double> &a_,const vector<Double> &b_){
  int sz=a_.size()+b_.size()-1;
  int N=1;
  while(N<sz) N*=2; // eq?
  vector<complex<Double>> A(N),B(N),C(N),a(N),b(N),c(N);
  rep(i,a_.size()) a[i]=a_[i];
  rep(i,b_.size()) b[i]=b_[i];
  fft(A,a,N); fft(B,b,N);
  rep(i,N) C[i]=A[i]*B[i];
  fft(c,C,N,1);
  vector<Double> re(sz);
  rep(i,sz) re[i]=c[i].real();
  return re;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n,x;
	cin>>n>>x;
	vector<int> a(n);
	rep(i,n){
		int y;
		cin>>y;
		a[i]=(y<x);
	}
	out(a,1);
	vector<int> cnt{1};
	for(int x:a){
		if(x) cnt.eb();
		++cnt.back();
	}
	vector<Double> f(n+1);
	rep(i,cnt.size()) f[i]=cnt[i];
	auto g=f; reverse(all(g));
	auto h=conv(f,g);
	out(f,g,h,1);
	ll re=0;
	for(auto x:cnt) re+=x*(x-1ll)/2;
	cout<<re<<" ";
	reps(i,1,n+1) cout<<ll(h[n+i]+0.5)<<" \n"[i==n];
  return 0;
}