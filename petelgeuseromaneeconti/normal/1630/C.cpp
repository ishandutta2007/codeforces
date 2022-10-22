#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define each(x,v) for(auto&x:v)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
namespace fenwick_helper{

template<class T>
T plus(const T&x,const T&y){
	return x+y;
}
template<class T>
T multiplies(const T&x,const T&y){
	return x*y;
}
template<class T>
T bit_xor(const T&x,const T&y){
	return x^y;
}
template<class T>
T min(const T&x,const T&y){
	return x<y?x:y;
}
template<class T>
T max(const T&x,const T&y){
	return x<y?y:x;
}
template<class T>
T e(){
	return T();
}

}
template<class T,T (*op)(const T&,const T&)=fenwick_helper::plus<T>,T (*e)()=fenwick_helper::e<T> >
struct fenwick{
	int n;
	vector<T>t;
	fenwick():n(0),t(0){}
	fenwick(int n):n(n),t(n,e()){}
	void assign(int n_){n=n_,t.assign(n_,e());}
	void add(int x,const T&y){ // 0<=x
		++x;
		for(int i=x;i<=n;i+=i&-i)t[i-1]=op(t[i-1],y);
	}
	void add(int l,int r,const T&x){ // [l,r]
		add(l,x);
		add(r+1,-x);
	}
	T query(int x){ // x<n
		++x;
		T y=e();
		for(int i=x;i>0;i&=i-1)y=op(y,t[i-1]);
		return y;
	}
	T query(int l,int r){ // [l,r]
		return op(query(r),-query(l-1)); // operator-()
	}
	void add2(int x,const T&y){ // x<n
		++x;
		for(int i=x;i>0;i&=i-1)t[i-1]=op(t[i-1],y);
	}
	T query2(int x){ // 0<=x
		++x;
		T y=e();
		for(int i=x;i<=n;i+=i&-i)y=op(y,t[i-1]);
		return y;
	}
};
/*
T unite(const T&x,const T&y){
	
}
fenwick_helper::plus<T>
fenwick_helper::multiplies<T>
fenwick_helper::bit_xor<T>
fenwick_helper::min<T>
fenwick_helper::max<T>

T zero(){
	
}

unite=plus<T>
zero=T()
fenwick<T,unite,zero>
*/
#ifndef ATCODER_INTERNAL_BITOP_HPP
#define ATCODER_INTERNAL_BITOP_HPP 1

#ifdef _MSC_VER
#include <intrin.h>
#endif

namespace atcoder {

namespace internal {

// @param n 
// @return minimum non-negative  s.t. 
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

// @param n 
// @return minimum non-negative  s.t. 
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}

// @param n 
// @return minimum non-negative  s.t. 
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

}  // namespace atcoder

#endif  // ATCODER_INTERNAL_BITOP_HPP

#ifndef ATCODER_SEGTREE_HPP
#define ATCODER_SEGTREE_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
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

    void add(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = op(d[p], x);
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
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

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
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

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
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

#endif  // ATCODER_SEGTREE_HPP

int unite(int x,int y){
	return max(x,y);
}
int get_e(){
	return -1e9;
}
const int N=200005;
int n,a[N],m,b[N],last[N],mate[N];
vector<int>v[N];
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	scanf("%d",&n);
	rep(i,1,n)scanf("%d",&a[i]),v[a[i]].pb(i);
	int maxr=0,base=0;
	rep(i,1,n){
		if(SZ(v[a[i]])==1){
			if(maxr>i)++base;
		}else if(i!=v[a[i]][0]&&i!=v[a[i]].back()&&maxr>i){
			++base;
		}else{
			b[++m]=a[i];
		}
		maxr=max(maxr,v[a[i]].back());
	}
	D("base=%d\n",base);
	rep(i,1,m)D("%d ",b[i]);
	D("\n");
	rep(i,1,m){
		if(!last[b[i]]){
			last[b[i]]=i;
		}else{
			assert(!mate[last[b[i]]]);
			mate[i]=last[b[i]];
			mate[last[b[i]]]=i;
		}
	}
	fenwick<int,fenwick_helper::max<int> >tr(m+1);
	atcoder::segtree<int,unite,get_e>tr2(m+1);
	vector<int>dp(m+1);
	int ans=0;
	rep(i,1,m){
		if(i>mate[i]){
			dp[i]=tr.query(mate[i]-1)+i-mate[i]-1;
			dp[i]=max(dp[i],tr2.prod(mate[i]+1,i)+i-1);
			tr.add(i,dp[i]);
			tr2.set(i,dp[i]-i);
			ans=max(ans,dp[i]);
		}
	}
	printf("%d\n",ans+base);
	return 0;
}