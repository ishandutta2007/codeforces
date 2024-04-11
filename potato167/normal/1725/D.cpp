#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=2167167167167167167;
const int INF=2100000000;
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


using F= ll;
F op(F a,F b){return a+b;}
F e(){return 0;}
int target;
bool f(F x){
	return x<target;
}


void solve();
// oddloop
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	ll N,Q;
	cin>>N>>Q;
	if(N<6){
		vector<int> ans={1,2,3,3,4,4};
		vector<int> sum={1,3,6,9,13,17};
		cout<<sum[N-1]<<"\n";
		rep(i,Q){
			int a;
			cin>>a;
			cout<<ans[a-1]<<"\n";
		}
		return;
	}
	ll ans=0;
	ll M=0;
	ll ind=1;
	while(M<N){
		ans+=ind*min((ind+1)/2,N-M);
		if(M+(ind+1)/2>N) break;
		M+=(ind+1)/2;
		ind++;
	}
	cout<<ans<<endl;
	ll X=1+2*((ind-2)/2);
	ll R=(N-M);
	vector<ll> p((X+1)/2);
	vector<ll> val((X+1)/2);
	rep(i,(X+1)/2){
		val[i]=i*2+1;
		p[i]=ind-1-i*2;
		if(R){
			R--;
			p[i]++;
		}
	}
	//vec_out(p),vec_out(val);
	auto tmp=val;
	for(auto &x:tmp){
		while(0==(x&(1<<20))) x<<=1;
	}
	vector<int> order((X+1)/2),start((X+1)/2);
	rep(i,(X+1)/2){
		order[i]=i;
		while((1<<(1+start[i]))<val[i]) start[i]++;
	}

	sort(all(order),[&](int a,int b){
		return tmp[a]<tmp[b];
	});
	ll len=(X+1)/2;
	vector<int> rev(len);
	rep(i,len) rev[order[i]]=i;
	segment_tree<F,op,e> seg(len);
	vector<ll> P(Q);
	rep(i,Q) cin>>P[i];
	ind=0;
	P.push_back(ILL);
	int l=0,r=len-1;
	int s=0;
	ll sum=0;
	while(ind!=Q){
		//cout<<sum<<endl;
		while(l!=len){
			if(s==start[l]){
				seg.set(rev[l],1);
				l++;
			}else{
				break;
			}
		}
		while(r!=-1){
			if(s==start[r]+p[r]){
				seg.set(rev[r],0);
				r--;
			}else{
				break;
			}
		}
		ll po=seg.query(0,len);
		while(ind!=Q&&sum+po>=P[ind]){
			target=P[ind]-sum;
			ans=seg.max_right<f>(0);
			ind++;
			ans=order[ans];
			cout<<val[ans]+s-start[ans]<<"\n";
		}
		sum+=po;
		s++;
	}
}