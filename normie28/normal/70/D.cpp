/*
	Normie's Template v2.2
	Changes:
	Added modulo binpow and inverse.
*/
 
// Standard library in one include.
#include <bits/stdc++.h>
using namespace std;
 
// ordered_set library.
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set(el) tree<el,null_type,less<el>,rb_tree_tag,tree_order_statistics_node_update>
 
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
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

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
const double eps=1e-13;
struct point {
	ll x, y;
	ll d;
	double z;
	point(){};
	point(int _x,int _y):x(_x),y(_y){} 
	bool operator <(const point& v) const {
		return z<v.z||(fabs(z-v.z)<eps && d<v.d);
	}
	point operator -(const point u) const{
		return point(x-u.x,y-u.y);
	}
	ll operator ^(const point u) const{
		return x*u.y-y*u.x;
	}
	ll operator *(const point u) const{
		return x*u.x+y*u.y;
	}
	void print() const{
		cout<<x<<' '<<y;
	}
};
 
struct ConvexHull{
	point center;
	
	set <point> st;
	typedef set <point>:: iterator iter;
	iter L(iter x) {
		if(x == st.begin()) x = st.end();
		x--;
		return x;
	}
	iter R(iter x) {
		x++;
		if(x == st.end()) x = st.begin();
		return x;
	}
	
	bool insert(point a){  
		if(st.find(a)!=st.end()) return false; 
	    a.d =(a-center)*(a-center);
        a.z = atan2(a.y-center.y, a.x-center.x);
        
		if(st.size()>2){
			iter i = st.lower_bound(a), j;
			if(i == st.end()) i = st.begin();
			j = L(i);
			if( ((a-*j)^(*i-*j)) <= 0) return false;
		}
		if(st.size()==2){
			iter i=st.begin(); 
			iter j=R(i);
			if(((a-*j)^(*i-*j))==0){
				if(((a-*j)*(*i-*j))<0) return false; 
				st.insert(a);
				st.erase(R(st.begin()));
				return true; 
			}
		}
		
        st.insert(a);
        
        if(st.size()<=3) return true;
        
        iter cur = st.find(a),i,j;
        
        i = L(cur); j = L(i);
		while( ((*i-*j)^(*cur-*j)) <= 0) {
			st.erase(i);
			i = j;  j = L(j);
		}
 
		i = R(cur); j = R(i);
		while( ((*i-*j)^(*cur-*j)) >= 0) {
			st.erase(i);
			i = j; j = R(j);
		}
		return true;
	}
	
	bool Inhull(point a){ 
	    a.d = (a-center)*(a-center);
        a.z = atan2(a.y-center.y, a.x-center.x);
		
		iter i = st.lower_bound(a), j;
		if(i == st.end()) i = st.begin();
		j = L(i);
		
		return ((a-*j)^(*i-*j)) <=0;
	}
} CH;
 
point o, p,a[5];
int q, op;
int main() {
    fio;
    cin>>q;
	for(int i = 0; i < 3; i++) {
        cin>>op>>a[i].x>>a[i].y;
    	o.x += a[i].x;
    	o.y += a[i].y;
    	a[i].x *= 3; a[i].y *= 3;
	}
	CH.center=o;
	for(int i = 0; i < 3; i++) 	CH.insert(a[i]);
	q -= 3;
	while(q--) {
        cin>>op>>p.x>>p.y;
		p.x *= 3; p.y *= 3;
		if(op == 2) {
			if(CH.Inhull(p)) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
		else CH.insert(p);
	}
}