#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=1167167167167167167;
const int INF=2100000000;
ll mod=998244353;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}


namespace atcoder {


namespace internal {

// @param n `0 <= n`
// @return minimum non-negative `x` s.t. `n <= 2**x`
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n `1 <= n`
// @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

}  // namespace internal


template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    segtree(int n) : segtree(std::vector<S>(n, e())) {}
    segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  // namespace atcoder


namespace po167{
struct combination{
	std::vector<long long> fact;
	std::vector<long long> rev;
	std::vector<long long> fact_rev;
	long long MOD;
	combination(int max,long long mod):MOD(mod),fact(max+1),rev(max+1),fact_rev(max+1){
		for(long long i=0;i<=max;i++){
			if(i<2){
				fact[i]=1;
				fact_rev[i]=1;
				rev[i]=1;
				continue;
			}
			fact[i]=(fact[i-1]*i)%mod;
			rev[i]=mod-((mod/i)*rev[mod%i])%mod;
			fact_rev[i]=(fact_rev[i-1]*rev[i])%mod;
		}
	}
	long long Comb(int x,int y){
		if (x<y||y<0) return 0;
		return (((fact_rev[y]*fact_rev[x-y])%MOD)*fact[x])%MOD;
	}
};
}
using po167::combination;
using atcoder::segtree;
int op(int a,int b){return a+b;}
int e(){return 0;}
int target;
bool f(int v){
	return v<target;
}

void solve(combination &C,segtree<int,op,e> &seg);

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	combination C(400400,mod);
	int t;
	cin>>t;
	int MAX_N=200200;
	vector<int> p(MAX_N,1);
	segtree<int,op,e> seg(p);
	rep(i,t) solve(C,seg);
}

void solve(combination &C,segtree<int,op,e> &seg){
	int n,m;
	cin>>n>>m;
	vector<int> y(m);
	rep(i,m){
		int a,b;
		cin>>a>>b;
		y[i]=b;
	}
	vector<bool> q(n,true);
	vector<int> re(m);
	int ans=2*n-1;
	for(int i=m-1;i>=0;i--){
		target=y[i];
		int a=seg.max_right<f>(0);
		target=1;
		int b=seg.max_right<f>(a+1);
		if(b!=n){
			if(q[b])ans--;
			q[b]=false;
		}
		seg.set(a,0);
		re[i]=a;
	}
	cout<<C.Comb(ans,n)<<"\n";
	rep(i,m) seg.set(re[i],1);
}