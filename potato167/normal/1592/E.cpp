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
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}

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
};
}
using po167::segment_tree;

using F= int;
int E=(1<<20)-1;
F op(F a,F b){return (a&b);}
F e(){return E;}

segment_tree<int,op,e> seg(1e6+10);

int ans=0;
vector<int> value;


void f(vector<int> &p,int base){
	if(base<0) return ;
	if(p.size()<2) return ;
	vector<vector<int>> q(2);
	int tmp=p[0];
	rep(i,p.size()){
		if(value[p[i]]&(1<<base)){
			q[0].push_back(p[i]);
		}else{
			q[1].push_back(p[i]);
		}
		if(i==0) continue;
		if(seg.query(p[i-1],p[i])&(1<<base)){
			chmax(ans,p[i]-tmp);
		}
		else tmp=p[i];
	}
	f(q[0],base-1);
	f(q[1],base-1);
}
void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	rep(i,t) solve();
}

void solve(){
	int n;
	cin>>n;
	value.resize(n+1);
	vector<int> p={0},q;
	rep(i,n){
		cin>>value[i+1];
		seg.set(i,value[i+1]);
		value[i+1]^=value[i];
		if(i%2) p.push_back(i+1);
		else q.push_back(i+1);
	}
	f(p,20);
	f(q,20);
	cout<<ans<<"\n";
}