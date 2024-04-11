#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=2167167167167167167;
const int INF=1050000000;
const ll mod=1e9+7;
#define rep(i,a) for (int i=0;i<a;i++)
#define all(p) p.begin(),p.end()
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}
template<class T> void vec_out(vector<T> &p){for(int i=0;i<(int)(p.size());i++){if(i) cout<<" ";cout<<p[i];}cout<<"\n";}
template<class T> T min(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmin(ans,x);return ans;}
template<class T> T max(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmax(ans,x);return ans;}

namespace po167{
template <class T,T (*op)(T,T),T(*e)()>
struct segment_tree{
	int _n,size;
	std::vector<T> seg;
	int ceil_pow2(int a){
		int b=1;
		while(a>b){
			b<<=1;
		}
		return b;
	}
	void update(int k){seg[k]=op(seg[k*2],seg[k*2+1]);};
	segment_tree(int n) :_n(n){
		size=ceil_pow2(n);
		seg=std::vector<T>(size*2,e());
	}
	segment_tree(std::vector<T> &p) :_n((int) p.size()){
		size=ceil_pow2(_n);
		seg=std::vector<T>(size*2,e());
		for(int i=0;i<_n;i++) seg[i+size]=p[i];
		for(int i=size-1;i>0;i--) update(i);
	}
	void set(int ind,T val){
		assert(0<=ind&&ind<_n);
		ind+=size;
		seg[ind]=val;
		while(ind!=1){
			ind>>=1;
			update(ind);
		}
	}
    void addl(int ind,T val){
        set(ind,op(get(ind),val));
    }
    void addr(int ind,T val){
        set(ind,op(val,get(ind)));
    }
	T get(int ind){
		assert(0<=ind&&ind<_n);
		return seg[ind+size];
	}
	T query(int l,int r){
		assert(0<=l&&l<=r&&r<=_n);
		T l_val=e();
		T r_val=e();
		l+=size,r+=size;
		while(l<r){
			if(l&1) l_val=op(l_val,seg[l]),l+=1;
			if(r&1) r-=1,r_val=op(seg[r],r_val);
			r>>=1;
			l>>=1;
		}
		return op(l_val,r_val);
	}
	template <bool (*f)(T)> int max_right(int l) {
        return max_right(l, [](T x) { return f(x); });
    }
	template <class F> int max_right(int l, F f) {
		assert(0<=l&&l<=_n);
		assert(f(e()));
		if(f(query(l,_n))) return _n;
		T val=e();
		l+=size;
		while(true){
			while(l%2==0) l>>=1;
			if(!f(op(val,seg[l]))){
				while(l<size){
					l*=2;
					if(f(op(val,seg[l]))){
						val=op(val,seg[l]);
						l++;
					}
				}
				return l-size;
			}
			val=op(val,seg[l]);
			l++;
		}
	}
	template <bool (*f)(T)> int min_left(int r) {
        return min_left(r, [](T x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        T sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(seg[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(seg[r], sm))) {
                        sm = op(seg[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(seg[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

};
}
using po167::segment_tree;


using F= int;
F op(F a,F b){return max(a,b);}
F e(){return -INF;}


void solve();
// oddloop
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n;
	cin>>n;
	vector<int> X(n*2),C(n);
	rep(i,n){
		cin>>X[i]>>X[i+n]>>C[i];
		C[i]--;
	}
	vector<int> ans(n,INF);
	auto f=[&]()->void{
		segment_tree<F,op,e> seg(n);
		vector<int> order(n*2);
		rep(i,n*2){
			order[i]=i;
		}
		sort(all(order),[&](int l,int r){
			if(X[l]==X[r]) return l<r;
			return X[l]<X[r];
		});
		vector<int> p(n);
		vector<int> q(n);
		vector<int> r(n);
		int sum_p=0;
		int sum_q=0;
		rep(i,n*2){
			int a=order[i];
			if(a<n){
				chmin(ans[a],X[a]-op(seg.query(C[a]+1,n),seg.query(0,C[a])));
				if(sum_p!=p[C[a]]) ans[a]=0;
				sum_p++;
				p[C[a]]++;
				sum_q++;
				q[C[a]]++;
				r[a]=sum_q-q[C[a]];
			}else{
				seg.set(C[a-n],X[a]);
				p[C[a-n]]--;
				sum_p--;
				sum_q++,q[C[a-n]]++;
				if(r[a-n]!=sum_q-q[C[a-n]]) ans[a-n]=0;
			}
		}
	};
	f();
	rep(i,n*2){
		X[i]=INF-X[i];
	}
	rep(i,n) swap(X[i],X[i+n]);
	f();
	vec_out(ans);
}