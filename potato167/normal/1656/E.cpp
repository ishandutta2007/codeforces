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
	int n;
	cin>>n;
	auto G=tree_in(n);
	int root=0;
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
	rep(i,n){
		if(i) cout<<" ";
		int c=G[i].size();
		if(depth[i]&1) c*=-1;
		cout<<c;
	}
	cout<<"\n";
}