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
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}

namespace po167{
struct UFtree
{
	std::vector<int> q;
	int component;
	int _n;
	UFtree(int n):component(n),_n(n/2),par(n){
		for(int i=0;i<n;i++){
			par[i]=i;
		}
	}
	void intialize(){
		for(auto x:q){
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
		if(b%_n<a%_n) std::swap(a,b);
		par[b]=a;
		q.push_back(b);
		component--;
		return true;
	}
	private:
	std::vector<int> par;
};
}
using po167::UFtree;


void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	ll n,m;
	cin>>n>>m;
	vector<int> t(m),x(m),y(m);
	vector<vector<pair<int,int>>> G(n);
	vector<vector<int>> p(2,vector<int>(n));
	UFtree T(n*2);
	rep(i,m){
		cin>>t[i]>>x[i]>>y[i];
		x[i]--,y[i]--,t[i]--;
		p[t[i]][x[i]]++;
		p[t[i]][y[i]]++;
		G[x[i]].push_back({y[i],t[i]});
		G[y[i]].push_back({x[i],t[i]});
		T.unite(x[i]+n,y[i]);
		T.unite(x[i],y[i]+n);
	}
	rep(i,n){
		if(T.same(i,i+n)){
			yneos(0);
			return ;
		}
	}
	vector<vector<int>> L(n),R(n);
	vector<int> ori(n),ox(n,0);
	rep(i,n){
		if(T.root(i)<n){
			L[T.root(i)%n].push_back(i);
			ori[i]=1;
		}else R[T.root(i)%n].push_back(i);
	}
	int Z=1;
	rep(i,n){
		//cout<<L[i].size()<<" "<<R[i].size()<<"\n";
		if(L[i].size()==0){
			continue;
		}
		if(R[i].size()==0){
			ox[i]=Z;
			Z+=2;
			continue;
		}
		int C=(int)(L[i].size())+(int)(R[i].size());
		int W=Z+2*C+5;
		int V=Z;
		queue<int> q;
		for(auto a:L[i]){
			if(p[0][a]==0){
				ox[a]=1;
				q.push(a);
			}else if(p[1][a]==0){
				ox[a]=-1;
				q.push(a);
			}
		}
		for(auto a:R[i]){
			if(p[0][a]==0){
				ox[a]=-1;
				q.push(a);
			}else if(p[1][a]==0){
				ox[a]=1;
				q.push(a);
			}
		}
		rep(roop,C){
			if(q.empty()){
				yneos(0);
				return ;
			}
			int a=q.front();
			q.pop();
			if(ox[a]==1){
				ox[a]=W;
				W-=2;
			}else ox[a]=V,V+=2;
			for(auto b:G[a]){
				p[b.second][b.first]--;
				if(p[b.second][b.first]==0&&ox[b.first]==0){
					int d=b.second*2-1;
					if(ori[b.first]) d*=-1;
					ox[b.first]=d;
					q.push(b.first);
				}
			}
		}
		Z+=C*2+9;
	}
	yneos(1);
	rep(i,n){
		if(ori[i]) cout<<"L ";
		else cout<<"R ";
		cout<<ox[i]<<"\n";
	}
}