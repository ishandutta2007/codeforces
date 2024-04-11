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
	cin>>t;
	rep(i,t) solve();
}

void solve(){
	int N;
	cin>>N;
	vector<vector<string>> S(N,vector<string>(N));
	rep(i,N){
		rep(j,N-i-1){
			cin>>S[i][i+j+1];
		}
	}
	auto f=[&](int a,int b)->int{
		if(a>b) swap(a,b);
		return b-a-1+((2*N-a-1)*a)/2;
	};
	vector<pair<int,int>> order;
	rep(i,N) for(int j=i+1;j<N;j++) order.push_back({i,j});
	int L=(N*(N+1))/2;
	UFtree T(L);
	rep(i,N){
		for(int j=i+1;j<N;j++){
			rep(k,N){
				if(S[i][j][k]=='1'){
					if(i==k||j==k){
						cout<<"No\n";
						return ;
					}
					T.unite(f(i,k),f(j,k));
				}
			}
		}
	}
	vector<bool> seen(L);
	rep(roop,L){
		if(seen[roop]) continue;
		if(T.wei[T.root(roop)]!=N-1) continue;
		vector<vector<int>> G(N);
		UFtree sub(N);
		for(int j=roop;j<L;j++){
			if(T.same(roop,j)){
				seen[j]=1;
				sub.unite(order[j].first,order[j].second);
				G[order[j].first].push_back(order[j].second);
				G[order[j].second].push_back(order[j].first);
			}
		}
		if(sub.component!=1) continue;
		int ju=1;
		vector<vector<int>> q(N,vector<int>(N,INF));
		rep(j,N){
			q[j][j]=0;
			vector<int> r={j};
			rep(k,N){
				int a=r[k];
				for(auto x:G[a]){
					if(q[j][x]==INF){
						q[j][x]=q[j][a]+1;
						r.push_back(x);
					}
				}
			}
		}
		for(int i=0;i<N;i++){
			for(int j=i+1;j<N;j++){
				for(int k=0;k<N;k++){
					if((q[i][k]==q[j][k])^(S[i][j][k]=='1')){
						ju=0;
						break;
					}
				}
				if(ju==0) break;
			}
			if(ju==0) break;
		}
		if(ju==1){
			cout<<"Yes\n";
			rep(i,N) rep(j,i){
				if(q[i][j]==1){
					cout<<i+1<<" "<<j+1<<"\n";
				}
			}
			return ;
		}
	}
	cout<<"No\n";
}