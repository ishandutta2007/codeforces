#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#define _GLIBCXX_DEBUG
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll ILL=2167167167167167167;
const int INF=2100000000;
const ll mod=998244353;
#define rep(i,a) for (ll i=0;i<a;i++)
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

namespace po167{
struct UFtree
{
	int _n;
	std::vector<int> wei;
	std::vector<int> q;
	int component;
	UFtree(int n):_n(n),wei(n),component(n),par(n){
		for(int i=0;i<n;i++){
			wei[i]=1,par[i]=i;
		}
	}
	void intialize(){
		for(auto x:q){
			wei[root(x)]=1;
			par[x]=x;
		}
		component=(int)par.size();
		q={};
	}
	//
	int root(int a){
		assert(0<=a&&a<_n);
		if(a==par[a]) return a;
		return par[a]=root(par[a]);
	}
	//true1,false0
	int same(int a,int b){
		assert(0<=a&&a<_n);
		assert(0<=b&&b<_n);
		if(root(a)==root(b)) return 1;
		else return 0;
	}
	//a,b,true
	bool unite(int a,int b){
		a=root(a),b=root(b);
		if(a==b) return false;
		if(wei[a]<wei[b]) std::swap(a,b);
		par[b]=a;
		q.push_back(b);
		wei[a]+=wei[b];
		component--;
		return true;
	}
	private:
	std::vector<int> par;
};
}
using po167::UFtree;


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
	UFtree T(n);
	vector<int> c(n),l(n),r(n);
	rep(i,n) cin>>c[i]>>l[i]>>r[i];
	vector<_pq<pair<int,int>>> pq(2);
	vector<int> order(n);
	rep(i,n) order[i]=i;
	sort(all(order),[&](int a,int b){return l[a]<l[b];});
	rep(roop,n){
		int a=order[roop];
		rep(i,2){
			while(!pq[i].empty()){
				//if(l[a]==13) cout<<pq[i].top().first<<"\n";
				if(pq[i].top().first<l[a]) pq[i].pop();
				else break;
			}
		}
		pq[c[a]].push({r[a],a});
		//cout<<pq[0].size()<<" "<<pq[1].size()<<"\n";
		if(!(pq[0].empty()||pq[1].empty())){
			rep(i,2){
				while(true){
					T.unite(pq[i].top().second,pq[i^1].top().second);
					if((int)(pq[i].size())==1) break;
					pq[i].pop();
				}
			}
		}
	}
	cout<<T.component<<"\n";
}