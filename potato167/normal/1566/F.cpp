#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=167167167167167167;
const int INF=2100000000;
ll mod=1e9+7;
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
	T get(int ind){
		assert(0<=ind&&ind<_n);
		return seg[ind+size];
	}
	T query(int l,int r){
		if(l==_n) return e();
		assert(0<=l&&l<_n);
		assert(0<=r&&r<=_n);
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
};
}
using po167::segment_tree;

using F= ll;
F MIN(F a,F b){return min(a,b);}
F e(){return ILL;}



void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<ll> p(n);
	rep(i,n) cin>>p[i];
	So(p);
	p.push_back(ILL);
	vector<vector<pair<int,int>>> G(n-1);
	ll X=p[0],Y=p[n-1];
	rep(i,m){
		ll l,r;
		cin>>l>>r;
		int a=LB(p,l),b=UB(p,r);
		if(a==b){
			if(a==0) chmin(X,r);
			else if(a==n) chmax(Y,l);
			else G[a-1].push_back({l,r});
		}
	}
	vector<ll> dp_f={(p[0]-X),INF};
	segment_tree<F,MIN,e> twi(1),one(1);
	twi.set(0,2*(p[0]-X));
	one.set(0,p[0]-X);
	rep(i,n-1){
		vector<ll> A={},B={};
		sort(G[i].begin(),G[i].end(),[](auto l,auto r){
			if(l.second==r.second) return l.first>r.first;
			return l.second<r.second;
		});
		ll l_max=p[i];
		rep(j,G[i].size()){
			ll l,r;
			tie(l,r)=G[i][j];
			if(l_max>l) continue;
			A.push_back(l_max-p[i]);
			B.push_back(p[i+1]-r);
			l_max=l;
		}
		A.push_back(l_max-p[i]);
		B.push_back(0);
		int L=A.size();
		vector<ll> dp_n(L+1);
		segment_tree<F,MIN,e> twi_n(L),one_n(L);
		for(int j=L-1;j>=0;j--){
			int a=LB(dp_f,A[j]);
			ll tmp1=A[j]+twi.query(0,a);
			ll tmp2=A[j]*2+one.query(a,twi._n);
			chmin(tmp1,tmp2);
			twi_n.set(L-1-j,tmp1+B[j]*2);
			one_n.set(L-1-j,tmp1+B[j]);
			dp_n[L-1-j]=B[j];
			//cout<<tmp1<<" "<<A[j]<<" "<<B[j]<<" / ";
		}
		//cout<<"\n";
		twi=twi_n;
		one=one_n;
		dp_n[L]=ILL;
		dp_f=dp_n;
	}
	int b=LB(dp_f,Y-p[n-1]);
	ll tmp=Y-p[n-1]+twi.query(0,b);
	chmin(tmp,(Y-p[n-1])*2+one.query(b,twi._n));
	cout<<tmp<<"\n";
}