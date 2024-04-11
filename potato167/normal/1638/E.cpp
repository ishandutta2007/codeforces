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
const ll mod=998244353;
#define rep(i,a) for (int i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}

template <class S, class T = int> struct IntervalManager {
    struct node {
        T l, r;
        S x;
        node(const T &l, const T &r, const S &x) : l(l), r(r), x(x) {}
        constexpr bool operator<(const node &rhs) const {
            if(l != rhs.l) return l < rhs.l;
            return r < rhs.r;
        }
    };
    set<node> s;
    IntervalManager() {}
    IntervalManager(const vector<T> &a) {
        vector<node> setter;
        for(int l = 0; l < a.size(); l++) {
            int r = l;
            for(; r < a.size() and a[l] == a[r]; r++) {}
            setter.emplace_back(l, r, a[l]);
            l = r - 1;
        }
        s = set<node>(all(setter));
    }
    S get(T x) {
        auto it = s.lower_bound(node(x, numeric_limits<T>::max(), 0));
        it = prev(it);
        return it->x;
    }
    S operator[](T k) const { return get(k); }
    void update(T l, T r, const S &x) {
        auto it = s.lower_bound(node(l, numeric_limits<T>::max(), 0));
        while(it != s.end()) {
            if(r <= it->l) break;
            if(it->r <= r) {
                it = s.erase(it);
            } else {
                node n = *it;
                it = s.erase(it);
                if(x == n.x) {
                    r = n.r;
                } else {
                    if(r < n.r) {
                        n.l = max(r, n.l);
                        it = s.emplace(n).first;
                    }
                }
                break;
            }
        }
        if(it != s.begin()) {
            it = prev(it);
            node n = *it;
            s.erase(it);
            if(n.x == x) {
                l = n.l;
                r = max(r, n.r);
            } else if(n.r < l) {
                s.emplace(n);
            } else {
                int memr = n.r;
                n.r = l;
                if(n.l < n.r) { s.emplace(n); }
                if(r < memr) { s.emplace(r, memr, n.x); }
            }
        }
        s.emplace(l, r, x);
    }
    template <class ADD, class DEL> void update(T l, T r, const S &x, const ADD &add, const DEL &del) {
        auto it = s.lower_bound(node(l, numeric_limits<T>::max(), 0));
        while(it != s.end()) {
            if(r <= it->l) break;
            if(it->r <= r) {
                del(it->l, it->r, it->x);
                it = s.erase(it);
            } else {
                node n = *it;
                del(it->l, it->r, it->x);
                it = s.erase(it);
                if(x == n.x) {
                    r = n.r;
                } else {
                    if(r < n.r) {
                        n.l = max(r, n.l);
                        add(n.l, n.r, n.x);
                        it = s.emplace(n).first;
                    }
                }
                break;
            }
        }
        if(it != s.begin()) {
            it = prev(it);
            node n = *it;
            del(it->l, it->r, it->x);
            s.erase(it);
            if(n.x == x) {
                l = n.l;
                r = max(r, n.r);
            } else if(n.r < l) {
                add(n.l, n.r, n.x);
                s.emplace(n);
            } else {
                int memr = n.r;
                n.r = l;
                if(n.l < n.r) {
                    add(n.l, n.r, n.x);
                    s.emplace(n);
                }
                if(r < memr) {
                    add(r, memr, n.x);
                    s.emplace(r, memr, n.x);
                }
            }
        }
        add(l, r, x);
        s.emplace(l, r, x);
    }
    void dump() {
        for(auto e : s) {
            cerr << "("
                 << "[" << e.l << ", " << e.r << "): " << e.x << ") ";
        }
        cerr << endl;
    }
};

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

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push(r >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
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

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
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
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

}  // namespace atcoder
using namespace atcoder;


using lazy_S=ll;

using lazy_F = ll;

lazy_S op(lazy_S l, lazy_S r) {
    return l+r;
}

lazy_S e() { return 0ll; }

lazy_S mapping(lazy_F l, lazy_S r) {
    return l+r;
}

lazy_F composition(lazy_F l, lazy_F r) { return l+r; }

lazy_F id(){return 0;}

#define lazy_calc lazy_S,op,e,lazy_F,mapping,composition,id

using S=int;

void solve();


//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t=1;
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n,q;
	cin>>n>>q;
	lazy_segtree<lazy_calc> seg(n);
	vector<ll> p(n+1);
	auto add = [&](int l, int r, S x) {
        seg.apply(l,r,-p[x]);
    };
    auto del = [&](int l, int r, S x){
		seg.apply(l,r,p[x]);
	};
	IntervalManager<S,int> s;
	s.update(0,n,1);
	rep(i,q){
		string S;
		cin>>S;
		if(S[0]=='C'){
			int l,r,c;
			cin>>l>>r>>c;
			s.update(l-1,r,c,add,del);
		}
		else if(S[0]=='A'){
			int c;
			ll x;
			cin>>c>>x;
			p[c]+=x;
		}else{
			int ind;
			cin>>ind;
			ind--;
			cout<<seg.get(ind)+p[s.get(ind)]<<"\n";
		}/*
		rep(j,n){
			cout<<seg.get(j)+p[s.get(j)]<<" ";
		}*/
		//cout<<"\n";
	}
}