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
F op(F a,F b){return max(a,b);}
F e(){return -1;}

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	vector<vector<bool>> p(n,vector<bool>(m));
	rep(i,n) rep(j,m){
		char a;
		cin>>a;
		if(a=='.') p[i][j]=1;
	}
	vector<vector<int>> dp(n,vector<int>(m));
	segment_tree<int,op,e> seg(m);
	rep(j,m){
		int tmp=-1;
		rep(i,n){
			if(!p[i][j]){
				dp[i][j]=INF;
				if(i!=0&&!p[i-1][j]&&j!=0&&!p[i][j-1]){
					tmp=j;
				}
				continue;
			}
			if(i==0){
				dp[i][j]=0;
				continue;
			}
			dp[i][j]=j;
			if(i!=0) chmin(dp[i][j],dp[i-1][j]);
			if(j!=0) chmin(dp[i][j],dp[i][j-1]);
			chmax(tmp,dp[i][j]);
		}
		seg.set(j,tmp);
	}
	int Q;
	cin>>Q;
	rep(i,Q){
		int a,b;
		cin>>a>>b;
		a--;
		yneos(seg.query(a,b)<=a);
	}
}