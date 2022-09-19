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
void yneos(bool a){if(a) cout<<"YES\n"; else cout<<"NO\n";}

namespace po167{
struct UFtree
{
	std::vector<int> wei;
	std::vector<int> q;
	int component;
	UFtree(int n):par(n),wei(n),component(n){
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

//  rainy ~  ~
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> G(n);
	vector<tuple<int,int,int>> edge(n-1);
	vector<vector<pair<int,int>>> H(n);
	vector<tuple<int,int,int>> p(m);
	rep(i,n-1){
		int a,b,c;
		cin>>a>>b>>c;
		a--,b--;
		edge[i]={a,b,c};
		G[a].push_back(b);
		G[b].push_back(a);
		int tmp=0;
		if(c==-1) continue;
		while(c){
			if(c&1) tmp^=1;
			c>>=1;
		}
		H[a].push_back({b,tmp});
		H[b].push_back({a,tmp});
	}
	int J=0;
	rep(i,m){
		int a,b,c;
		cin>>a>>b>>c;
		a--,b--;
		p[i]={a,b,c};
		H[a].push_back({b,c});
		H[b].push_back({a,c});
	}
	vector<int> q(n,-1);
	rep(i,n){
		if(q[i]!=-1) continue;
		queue<int> que;
		que.push(i);
		q[i]=0;
		while(!que.empty()){
			int a=que.front();
			que.pop();
			for(auto x:H[a]){
				int b,c;
				tie(b,c)=x;
				if(q[b]==-1){
					q[b]=(q[a]^c);
					que.push(b);
				}else if(q[b]!=(q[a]^c)){
					J=1;
					break;
				}
			}
		}
	}
	if(J) yneos(0);
	else{
		yneos(1);
		rep(i,n-1){
			int a,b,c;
			tie(a,b,c)=edge[i];
			if(c==-1){
				c=(q[a]^q[b]);
			}
			cout<<a+1<<" "<<b+1<<" "<<c<<"\n";
		}
	}
}