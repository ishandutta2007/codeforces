/*
	Normie's Template v2.2
	Changes:
	Added modulo binpow and inverse.
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 

// AtCoder library. (Comment out these two lines if you're not submitting in AtCoder.) (Or if you want to use it in other judges, run expander.py first.)
//#include <atcoder/all>
//using namespace atcoder;
 
//Pragmas (Comment out these three lines if you're submitting in szkopul.)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast,unroll-loops,tree-vectorize")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
 
//File I/O.
#define FILE_IN "cseq.inp"
#define FILE_OUT "cseq.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
 
//Fast I/O.
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define endl "\n"
 
//Order checking.
#define ord(a,b,c) ((a>=b)and(b>=c))
 
//min/max redefines, so i dont have to resolve annoying compile errors.
// Fast min/max assigns to use with AVX.
// Requires g++ 9.2.0.
template<typename T>
__attribute__((always_inline)) void chkmin(T& a, const T& b) {
    a=(a<b)?a:b;
}
 
template<typename T>
__attribute__((always_inline)) void chkmax(T& a, const T& b) {
    a=(a>b)?a:b;
}
 
//Constants.
#define MOD (ll(998244353))
#define MAX 300001
#define mag 320
const long double PI=3.14159265358979;
 
//Pairs and 3-pairs.
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pii(element_type) pair<element_type,element_type>
#define piii(element_type) pair<element_type,pii(element_type)>
 
//Quick power of 2.
#define pow2(x) (ll(1)<<x)
 
//Short for-loops.
#define ff(i,__,___) for(int i=__;i<=___;i++)
#define rr(i,__,___) for(int i=__;i>=___;i--)
 
//Typedefs.
#define bi BigInt
typedef long long ll;
typedef long double ld;
typedef short sh;
 
// Binpow and stuff
ll BOW(ll a, ll x, ll p)
{
	if (!x) return 1;
	ll res=BOW(a,x/2,p);
	res*=res;
	res%=p;
	if (x%2) res*=a;
	return res%p;
}
ll INV(ll a, ll p)
{
	return BOW(a,p-2,p);
}
//---------END-------//
const ll INF = 1LL<<61;
bool type_;
struct Line {
	ll a, b;
	mutable long double xl;
	bool operator < (const Line &l) const { if (type_) return a < l.a; else return xl < l.xl; }
};
struct Hull : multiset<Line> {
	bool bad (iterator y) {
		iterator z = next(y), x;
		if (y == begin()) {
			if (z == end()) return 0;
			return y->a == z->a && y->b <= z->b;
		}
		x = prev(y);
		if (z == end()) return y->a == x->a && y->b <= x->b;
		return 1.0L * (x->b - y->b) * (z->a - y->a) >= 1.0L * (y->b - z->b) * (y->a - x->a);
	}
	void add (ll a, ll b) {
		type_ = 1;
		iterator y = insert((Line){-a,-b,-INF});
		if (bad(y)) { erase(y); return; }
		while (next(y) != end() && bad(next(y))) erase(next(y));
		while (y != begin() && bad(prev(y))) erase(prev(y));
		if (next(y) != end()) next(y)->xl = 1.0L * (y->b - next(y)->b) / (next(y)->a - y->a);
		if (y != begin()) y->xl = 1.0L * (y->b - prev(y)->b) / (prev(y)->a - y->a);
	}
	ll query (ll x) {
		if (empty()) return 1e18;
		type_ = 0;
		iterator it = prev(lower_bound((Line){0,0,1.0L*x}));
		return -(it->a * x + it->b);
	}
} tree [ 262145 ] ;
int a [ 100003 ] , n ;
ll s [ 100003 ] ;
int main(){
    fio;
	cin >> n ; n ++ ;
	for ( int i = 1 ; i < n ; i ++ ) {
		cin >> a [ i ] ;
		s [ i ] = s [ i - 1 ] + a [ i ] ;
		for ( int j = i + n ; j > 0 ; j >>= 1 ) tree [ j ].add ( a [ i ] , - s [ i ] + i * a [ i ] ) ;
	}
	int q ; 
	cin >> q ; 
	while ( q -- ) {
		int x , y , l , r ;
		cin >> x >> y ;
		r = y , l = y - x + 1 ;
		y = x - y ;	x = r ;
		swap ( x , y ) ;
		ll ans = 1e18 ;
		for ( l += n , r += n + 1 ; l < r ; l >>= 1 , r >>= 1 ) {
			if ( l & 1 ) ans = min ( ans , tree [ l ++ ].query ( x ) + s [ y ] ) ;
			if ( r & 1 ) ans = min ( ans , tree [ -- r ].query ( x ) + s [ y ] ) ;
		}
		cout << ans << '\n' ;
	}
}