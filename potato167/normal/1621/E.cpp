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
int target;
bool f(F x){
	return (x%target==0);
}


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
	int n,m;
	cin>>n>>m;
	vector<ll> p(n);
	rep(i,n) cin>>p[i];
	vector<vector<ll>> q(m);
	vector<ll> sum(m);
	rep(i,m){
		int k;
		cin>>k;
		rep(j,k){
			ll a;
			cin>>a;
			q[i].push_back(a);
			sum[i]+=a;
		}
	}
	vector<tuple<ll,ll,ll>> order; 
	vector<int> rev(m);
	rep(i,n) order.push_back({p[i],1,i-n});
	rep(j,m) order.push_back({sum[j],q[j].size(),j});
	sort(order.begin(),order.end(),[](tuple<ll,ll,ll> l,tuple<ll,ll,ll> r){
		if( (get<0>(l)*get<1>(r))==(get<0>(r)*get<1>(l)) ){
			return get<2>(l) < get<2>(r);
		}
		return (get<0>(l)*get<1>(r)) > (get<0>(r)*get<1>(l));
	});
	int tmp=-1;
	int ind=0;
	segment_tree<F,op,e> seg(n+1);
	rep(i,n+m){
		if(get<2>(order[i])<0){
			tmp++;
			seg.set(ind,tmp);
			ind++;
		}else{
			rev[get<2>(order[i])]=ind;
			tmp--;
		}
		//cout<<tmp<<" "<<ind<<"\n";
	}
	tmp++;
	seg.set(n,tmp);
	Sore(p);
	string ans="";
	rep(i,m){
		for(auto x:q[i]){
			ll val=(sum[i]-x-2+(int)(q[i].size()))/((int)(q[i].size())-1);
			int l=-1,r=n;
			while(r-l>1){
				int med=(l+r)/2;
				if(p[med]<val) r=med;
				else l=med;
			}
			//cout<<val<<" "<<l<<" "<<p[0]<<"\n";
			l++;
			if(l==0){
				//cout<<0<<"\n";
				ans+='0';
				continue;
			}
			bool J=0;
			if(l==rev[i]){
				//cout<<1<<"\n";
				if(seg.query(0,n)>=0) J=1;
			}else if(l<rev[i]){
				//cout<<2<<"\n";
				if(seg.query(0,n)>=0&&seg.query(l,rev[i])>=1){
					J=1;
				}
			}else{
				//cout<<3<<"\n";
				if(seg.query(0,n)>=-1&&seg.query(0,rev[i])>=0&&seg.query(l,n)>=0){
					J=1;
				}
			}
			if(J) ans+='1';
			else ans+='0';
		}
	}
	//rep(i,n) cout<<seg.get(i);
	//cout<<"\n";
	cout<<ans<<"\n";
}