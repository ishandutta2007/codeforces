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
	int add_ver(){
		G.push_back({});
		G_rev.push_back({});
		size++;
		return size-1;
	}
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
		graph.add_edge(i*2+(!f),j*2+(g));
		graph.add_edge(j*2+(!g),i*2+(f));
	}
	void one_true_in_group(std::vector<std::pair<int,int>> &p){
		int ind;
		for(int i=0;i<(int)(p.size())-1;i++){
			ind=graph.add_ver();
			graph.add_ver();
			ind/=2;
			add_clause(ind,1,p[i].first,p[i].second^1);
			add_clause(ind,0,p[i+1].first,p[i+1].second^1);
			if(i){
				add_clause(ind-1,0,ind,1);
			}
			ans.push_back(false);
			size++;
		}
	}
	bool build(){
		auto rank=graph.for_two_sat();
		exists=true;
		for(int i=0;i<size;i++){
			if(rank[i*2]==rank[i*2+1]){
				exists=false;
				break;
			}
			ans[i]=(rank[i*2]<rank[i*2+1]);
		}
		return exists;
	}
};
}
using po167::SCC;
using po167::two_SAT;


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
	vector<int> p(n),q(n);
	rep(i,n) cin>>p[i],p[i]--;
	rep(i,n) cin>>q[i],q[i]--;
	vector<int> use(n);
	int ind=0;
	rep(i,n){
		use[p[i]]++;
		if(use[ind]<use[p[i]]) ind=p[i];
	}
	SCC G(n);
	rep(i,n){
		if(p[i]!=ind&&q[i]!=ind){
			if(p[i]==q[i]){
				cout<<"WA\n";
				return ;
			}
			G.add_edge(p[i],q[i]);
		}
	}
	auto tp=G.tp_sort();
	if((int)tp.size()==n) cout<<"AC\n";
	else cout<<"WA\n";
}