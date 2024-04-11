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
const ll mod=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
void yneos(bool a){if(a) cout<<"Yes\n"; else cout<<"No\n";}

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
F op(F a,F b){return min(a,b);}
F e(){return INF;}


void solve();
//  rainy ~  ~
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
    vector<vector<int>> G(n);
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        a--,b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<int> order={0},A(n),B(n),pare(n,-1),C(n),D(n),R(n);
    pare[0]=-2;
    rep(i,n){
        int a=order[i];
        for(auto x:G[a]){
            if(pare[x]==-1){
                pare[x]=a;
                C[x]=C[a]+1;
                order.push_back(x);
            }
        }
    }
    rep(i,n){
        int a=order[n-1-i];
        int b=pare[a];
        if(b==-2) continue;
        if(A[b]<A[a]+1) B[b]=A[b],A[b]=A[a]+1;
        else chmax(B[b],A[a]+1);
    }
    rep(i,n){
        int a=order[i];
        int Y=0,Z=0;
        Y=max(C[a],D[a]);
        for(auto x:G[a]){
            if(pare[a]==x) continue;
            if(chmax(Z,A[x]+C[x])){
                if(Y<Z) swap(Y,Z);
            }
        }
        for(auto x:G[a]){
            if(pare[a]==x) continue;
            if(Y==A[x]+C[x]) D[x]=Z;
            else D[x]=Y;
        }
    }
    vector<tuple<int,int,int>> p(n);
    rep(i,n){
        int a=order[n-1-i];
        chmax(R[a],(1+A[a]+B[a])/2);
        if(a) chmax(R[pare[a]],R[a]);
        p[i]={D[a]-R[a],D[a],R[a]};
        //cout<<a<<" "<<D[a]<<" "<<R[a]<<"\n";
    }
    So(p);
    p.push_back({INF,INF,INF});
    segment_tree<F,op,e> seg_d(n);
    segment_tree<F,op,e> seg_x(n);
    rep(i,n){
        seg_d.set(i,get<1>(p[i]));
        seg_x.set(i,get<2>(p[i]));
    }
    for(int x=1;x<=n;x++){
        if(x!=1) cout<<" ";
        int b=LB(p,{x,0,0});
        int a=seg_x.query(0,b);
        int c=seg_d.query(b,n);
        cout<<min(A[0],min(c,a+x));
    }
    cout<<"\n";
}