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
struct UFtree
{
	std::vector<int> wei;
	int component;
	UFtree(int n):par(n),wei(n),component(n){
		for(int i=0;i<n;i++){
			wei[i]=1,par[i]=i;
		}
	}
	void intialize(){
		for(int i=0;i<(int) par.size();i++){
			wei[i]=1,par[i]=i;
		}
		component=(int)par.size();
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
		wei[a]+=wei[b];
		component--;
		return true;
	}
	private:
	std::vector<int> par;
};
}
using po167::UFtree;

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
		assert(n!=1);
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
		for(int i=0;i<m;i++){
			if(dif&(1<<i)){
				var_2=parent[var_2][i];
			}
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
	int distance(int var_1,int var_2){
		int ascent=lca(var_1,var_2);
		return deep[var_1]+deep[var_2]-2*deep[ascent];
	}
};
}
using po167::LCA;

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,m;
	cin>>n>>m;
	vector<vector<int>> G(n);
	vector<vector<int>> tree(n);
	UFtree T(n);
	rep(i,m){
		int a,b;
		cin>>a>>b;
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
		if(T.unite(a,b)){
			tree[a].push_back(b);
			tree[b].push_back(a);
		}
	}
	auto lca=LCA(0,tree);
	int Q;
	cin>>Q;
	vector<int> x(Q),y(Q),cou(n);
	rep(i,Q){
		cin>>x[i]>>y[i];
		x[i]--,y[i]--;
		cou[x[i]]++;
		cou[y[i]]++;
	}
	int J=0;
	rep(i,n){
		J+=(cou[i]%2);
	}
	if(J==0){
		cout<<"YES\n";
		rep(i,Q){
			int a=lca.lca(x[i],y[i]);
			vector<int> p;
			stack<int> s;
			while(x[i]!=a){
				p.push_back(x[i]);
				x[i]=lca.parent[x[i]][0];
			}
			p.push_back(a);
			while(y[i]!=a){
				s.push(y[i]);
				y[i]=lca.parent[y[i]][0];
			}
			while(!s.empty()){
				p.push_back(s.top());
				s.pop();
			}
			cout<<p.size()<<"\n";
			rep(i,p.size()){
				if(i!=0) cout<<" ";
				cout<<p[i]+1;
			}
			cout<<"\n";
		}
		return 0;
	}
	cout<<"NO\n";
	cout<<J/2<<"\n";
}