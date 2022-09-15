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

/*

#include<vector>
#include<cassert>
#include<math.h>

*/

namespace po167{
struct LCA{
	std::vector<int> deep;
	std::vector<std::vector<int>> parent;
	int n;
	int m;
	LCA(int root_node,std::vector<std::vector<int>> &G):n((int)G.size()),m((int)(2+std::log(n)/std::log(2))){
		deep.resize(n),parent.assign(n,std::vector<int>(m));
		for(int i=0;i<n;i++){
			parent[i][0]=-1;
			deep[i]=-1;
		}
		deep[root_node]=0;
		parent[root_node][0]=-2;
		std::vector<int> order(n);
		order[0]=root_node;
		int look=1;
		for(int i=0;i<n;i++){
			for(auto x:G[order[i]]){
				if(deep[x]==-1){
					deep[x]=deep[order[i]]+1;
					parent[x][0]=order[i];
					order[look]=x;
					look++;
				}
			}
		}
		assert(look==n);//when G is not connected
		for(int i=0;i<n;i++) for(int j=1;j<m;j++){
			int var=order[i];
			if(parent[var][j-1]==-2) parent[var][j]=-2;
			else{
				parent[var][j]=parent[parent[var][j-1]][j-1];
			}
		}
	}
	int lca(int var_1,int var_2){
		if(deep[var_1]>deep[var_2]){
			std::swap(var_1,var_2);
		}
		int dif=deep[var_2]-deep[var_1];
		int ind=0;
		while(dif){
			if(dif&1){
				var_2=parent[var_2][ind];
			}
			ind++;
			dif>>=1;
		}
		if(var_1==var_2) return var_1;
		for(int i=m-1;i>=0;i--){
			if(parent[var_1][i]!=parent[var_2][i]){
				var_1=parent[var_1][i];
				var_2=parent[var_2][i];
			}
		}
		return parent[var_1][0];
	}
	int back(int var_1,int dif){
		for(int i=0;i<m;i++){
			if(dif==0) break;
			if(dif&1){
				var_1=parent[var_1][i];
			}
			dif>>=1;
		}
		return var_1;
	}
	int distance(int var_1,int var_2){
		int ascent=lca(var_1,var_2);
		return deep[var_1]+deep[var_2]-2*deep[ascent];
	}
};
}
using po167::LCA;


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
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	int N,M;
	cin>>N>>M;
	vector<int> X(M),Y(M),U(M);
	UFtree T(N);
	vector<vector<int>> G(N);
	rep(i,M){
		int a,b;
		cin>>a>>b;
		a--,b--;
		X[i]=a,Y[i]=b;
		if(T.unite(a,b)){
			U[i]=1;
			G[a].push_back(b);
			G[b].push_back(a);
		}
	}
	LCA L(0,G);
	vector<int> ans(N,-1),dp(N);
	int base=0;
	rep(i,M){
		if(U[i]==0){
			base++;
			int p=L.lca(X[i],Y[i]);
			if(p==X[i]){
				dp[Y[i]]++;
				int b=L.back(Y[i],L.deep[Y[i]]-L.deep[X[i]]-1);
				dp[b]--;
				dp[0]++;
			}else if(p==Y[i]){
				dp[X[i]]++;
				int b=L.back(X[i],L.deep[X[i]]-L.deep[Y[i]]-1);
				dp[b]--;
				dp[0]++;
			}else{
				dp[X[i]]++;
				dp[Y[i]]++;
			}
		}
	}
	vector<int> order={0};
	rep(i,N){
		int a=order[i];
		if(dp[a]==base) ans[a]=1;
		else ans[a]=0;
		for(auto x:G[a]){
			if(ans[x]==-1){
				dp[x]+=dp[a];
				order.push_back(x);
			}
		}
	}
	rep(i,N) cout<<ans[i];
	cout<<"\n";
}