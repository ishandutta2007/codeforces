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
	std::vector<int> wei;
	std::vector<int> q;
	int component;
	UFtree(int n):wei(n),component(n),par(n){
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
		if(a==par[a]) return a;
		return par[a]=root(par[a]);
	}
	//true1,false0
	int same(int a,int b){
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
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> x(m),y(m),w(m);
	rep(i,m) cin>>x[i]>>y[i]>>w[i],x[i]--,y[i]--;
	int Q;
	cin>>Q;
	vector<int> s(Q),t(Q),ans(Q,2);
	rep(i,Q) cin>>s[i]>>t[i],s[i]--,t[i]--;
	rep(i,30){
		UFtree Tr(n);
		rep(j,m){
			if(w[j]&(1<<i)){
				Tr.unite(x[j],y[j]);
			}
		}
		rep(j,Q){
			if(Tr.same(s[j],t[j])) ans[j]=0;
		}
		if(i==0) continue;
		rep(j,m){
			if(w[j]%2==0){
				Tr.wei[Tr.root(x[j])]=-1;
				Tr.wei[Tr.root(y[j])]=-1;
			}
		}
		//vec_out(Tr.wei);
		rep(j,Q){
			if(Tr.wei[Tr.root(s[j])]==-1) chmin(ans[j],1);
		}
	}
	rep(i,Q){
		cout<<ans[i]<<"\n";
	}
}