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

//in[i] -> p[i]
//out[i] -> p[i+N]
std::vector<int> Euler_Tour(std::vector<std::vector<int>> &G,int root){
	std::stack<int> s;
	int n=G.size();
	std::vector<int> p(n*2),seen(n);
	s.push(root);
	seen[root]=1;
	for(int i=0;i<2*n;i++){
		int a=s.top();
		p[a]=i;
		s.pop();
		if(a<n){
			s.push(a+n);
			for(auto x:G[a]){
				if(seen[x]==0){
					s.push(x);
					seen[x]=1;
				}
			}
		}
	}
	return p;
}

std::vector<std::vector<int>> tree_in(int N){
	std::vector<std::vector<int>> G(N);
	for(int i=0;i<N-1;i++){
		int a;int b;
		cin>>a>>b; 
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	return G;
}
std::tuple<std::vector<int>,std::vector<int>,std::vector<int>> tree_order_pare_depth(std::vector<std::vector<int>> &G,int root){
	int n=G.size();
	std::vector<int> order={root},pare(n,-1),depth(n);
	pare[root]=-2;
	for(int i=0;i<n;i++){
		int a=order[i];
		for(auto x:G[a]){
			if(pare[x]==-1){
				pare[x]=a;
				depth[x]=depth[a]+1;
				order.push_back(x);
			}
		}
	}
	return {order,pare,depth};
}
std::vector<int> tree_diameter_path(std::vector<std::vector<int>> &G){
	int n=G.size();
	auto r=(std::get<0>(tree_order_pare_depth(G,0))).at(n-1);
	std::vector<int> order,pare,depth,ans;
	tie(order,pare,depth)=tree_order_pare_depth(G,r);
	int ind=order[n-1];
	while(ind!=-2){
		ans.push_back(ind);
		ind=pare[ind];
	}
	return ans;
}


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
	int n,k;
	cin>>n>>k;
	int X,Y;
	cin>>X>>Y;
	X--,Y--;
	vector<int> p={X,Y};
	rep(i,k){
		int a;
		cin>>a;
		p.push_back(a-1);
	}
	auto G=tree_in(n);
	auto E=Euler_Tour(G,0);
	sort(all(p),[&](int l,int r){
		return E[l]<E[r];
	});
	int ans=0;
	p.push_back(p[0]);
	LCA L(0,G);
	rep(i,k+2){
		ans+=L.distance(p[i],p[i+1]);
	}
	ans-=L.distance(X,Y);
	cout<<ans<<"\n";
}