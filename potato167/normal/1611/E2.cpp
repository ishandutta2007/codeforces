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
	int back(int var_1,int dif){
		for(int i=0;i<m;i++){
			if(dif&(1<<i)){
				var_1=parent[var_1][i];
			}
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

void solve();

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t=1;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> p(m);
	rep(i,m) cin>>p[i],p[i]--;
	vector<vector<int>> G(n);
	rep(i,n-1){
		int a,b;
		cin>>a>>b;
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	LCA L(0,G);
	stack<int> s;
	s.push(0);
	int ans=0,J=0;
	int tmp=-1;
	vector<int> q(n);
	rep(i,m){
		q[L.back(p[i],L.distance(0,p[i])/2)]++;
	}
	while(!s.empty()){
		int a=s.top();
		s.pop();
		if(a>=n){
			a-=n;
			if(tmp==a) tmp=-1;
			continue;
		}
		s.push(a+n);
		for(auto x:G[a]){
			if(x==L.parent[a][0]) continue;
			s.push(x);
		}
		if(q[a]&&tmp==-1) tmp=a;
		if(s.top()==a+n){
			if(tmp==-1) J=1;
			else if(q[tmp]){
				q[tmp]=0;
				ans++;
			}
		}
	}
	if(J){
		cout<<"-1\n";
	}else cout<<ans<<"\n";
}