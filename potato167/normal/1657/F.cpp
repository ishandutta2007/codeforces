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


namespace po167{
struct SCC{
	std::vector<std::vector<int>> G;
	std::vector<std::vector<int>> G_rev;
	int size;
	SCC(int n):G(n),G_rev(n),size(n){}

	void add_edge(int from,int to){
		assert(0<=to&&to<size);
		assert(0<=from&&from<size);
		G[from].push_back(to);
		G_rev[to].push_back(from);
	}

	void dfs1(std::vector<int> &order,std::vector<int> &seen,int ind,int &now){
		if(seen[ind]!=0) return;
		seen[ind]=-1;
		for(auto x:G[ind]){
			dfs1(order,seen,x,now);
		}
		order[now]=ind;
		now++;
	}
	void dfs2(std::vector<int> &seen,int ind,int rank){
		if(seen[ind]!=-1) return;
		seen[ind]=rank;
		for(auto x:G_rev[ind]){
			dfs2(seen,x,rank);
		}
	}
	std::vector<std::vector<int>> tp_sort(){
		std::vector<int> seen(size,0),order(size);
		int now=0;
		for(int i=0;i<size;i++) dfs1(order,seen,i,now);
		now=0;
		for(int i=size-1;i>=0;i--){
			if(seen[order[i]]==-1){
				dfs2(seen,order[i],now);
				now++;
			}
		}
		std::vector<std::vector<int>> ans(now);
		for(int i=0;i<size;i++){
			ans[seen[i]].push_back(i);
		}
		return ans;
	}
	std::vector<int> for_two_sat(){
		std::vector<int> seen(size,0),order(size);
		int now=0;
		for(int i=0;i<size;i++) dfs1(order,seen,i,now);
		now=0;
		for(int i=size-1;i>=0;i--){
			if(seen[order[i]]==-1){
				dfs2(seen,order[i],now);
				now++;
			}
		}
		return seen;
	}
};

struct two_SAT{
	po167::SCC graph;
	std::vector<bool> ans;
	bool exists=false;
	int size;
	two_SAT(int n):graph(2*n),ans(n),size(n){}
	void add_clause(int i,bool f,int j,bool g){
		graph.add_edge(i+size*(!f),j+size*(g));
		graph.add_edge(j+size*(!g),i+size*(f));
	}
	bool build(){
		auto rank=graph.for_two_sat();
		exists=true;
		for(int i=0;i<size;i++){
			if(rank[i]==rank[i+size]){
				exists=false;
				break;
			}
			ans[i]=(rank[i]<rank[i+size]);
		}
		return exists;
	}
};
}
using po167::SCC;
using po167::two_SAT;

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
	//cin>>t;
	rep(i,t) solve();
}

void solve(){
	int N,Q;
	cin>>N>>Q;
	auto G=tree_in(N);
	vector<int> pare,order,depth;
	tie(order,pare,depth)=tree_order_pare_depth(G,0);
	two_SAT T(Q+N);
	vector<bool> seen(N);
	vector<vector<char>> q(N,vector<char>(2,'z'));
	rep(i,Q){
		int a,b;
		string S;
		cin>>a>>b>>S;
		a--,b--;
		vector<int> path;
		vector<int> path2;
		while(a!=b){
			bool c=(depth[a]>=depth[b]);
			bool d=(depth[a]<=depth[b]);
			if(c) path.push_back(a),a=pare[a];
			if(d) path2.push_back(b),b=pare[b];
		}
		reverse(all(path2));
		path.push_back(a);
		for(auto x:path2) path.push_back(x);
		assert(path.size()==S.size());
		int L=S.size();
		rep(j,L){
			char c1=S[j],c2=S[L-1-j];
			int ind=path[j];
			if(!seen[ind]){
				q[ind][0]=c1;
				if(c1!=c2) q[ind][1]=c2;
				else q[ind][1]='+';
				//cout<<ind<<" "<<c1<<" "<<c2<<"\n";
				seen[ind]=1;
			}
			if(c1!=q[ind][0]&&c1!=q[ind][1]){
				T.add_clause(i,0,i,0);
			}
			if(c2!=q[ind][0]&&c2!=q[ind][1]){
				T.add_clause(i,1,i,1);
			}
			rep(k,2){
				if(c1==q[ind][k]){
					T.add_clause(i,0,ind+Q,k);
				}if(c2==q[ind][k]){
					T.add_clause(i,1,ind+Q,k);
				}
			}
		}
	}
	auto ans=T.build();
	/*rep(i,N){
		rep(j,M) cout<<q[i][j];
		cout<<"\n";
	}*/
	if(!ans){
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
	rep(i,N){
		cout<<q[i][T.ans[Q+i]];
	}
	cout<<"\n";
}