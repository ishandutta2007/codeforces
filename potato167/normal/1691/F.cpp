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
const ll mod=1e9+7;
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
struct combination{
	int upper;
	long long MOD;
	std::vector<long long> fact;
	std::vector<long long> rev;
	std::vector<long long> fact_rev;
	combination(int max,long long mod):upper(max),MOD(mod),fact(max+1),rev(max+1),fact_rev(max+1){
		for(long long i=0;i<=max;i++){
			if(i<2){
				fact[i]=1;
				fact_rev[i]=1;
				rev[i]=1;
				continue;
			}
			fact[i]=(fact[i-1]*i)%mod;
			rev[i]=mod-((mod/i)*rev[mod%i])%mod;
			fact_rev[i]=(fact_rev[i-1]*rev[i])%mod;
		}
	}
	long long Comb(int x,int y){
		assert(upper>=x);
		if (x<y||y<0||x<0) return 0;
		return (((fact_rev[y]*fact_rev[x-y])%MOD)*fact[x])%MOD;
	}
};
}
using po167::combination;

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
	ll n,k;
	cin>>n>>k;
	combination table(n,mod);
	auto G=tree_in(n);
	vector<int> order,pare,depth;
	tie(order,pare,depth)=tree_order_pare_depth(G,0);
	vector<ll> lower_dp(n),upper_dp(n),sum_dp(n),size(n);
	for(int i=n-1;i>=0;i--){
		int a=order[i];
		ll tmp=0;
		for(auto x:G[a]){
			if(pare[x]==a){
				tmp-=table.Comb(size[x],k);
				size[a]+=size[x];
				lower_dp[a]=(lower_dp[a]+lower_dp[x]);
			}
		}
		size[a]++;
		tmp=(tmp+table.Comb(size[a],k))%mod;
		lower_dp[a]=(lower_dp[a]+(tmp*size[a])%mod);
	}
	ll ans=0;
	for(int i=0;i<n;i++){
		int a=order[i];
		ll tmp=0;
		for(auto x:G[a]){
			if(pare[x]==a){
				tmp-=table.Comb(size[x],k);
				sum_dp[a]=(sum_dp[a]+lower_dp[x])%mod;
			}
		}
		tmp-=table.Comb(n-size[a],k);
		tmp=(tmp+table.Comb(n,k))%mod;
		sum_dp[a]=((tmp*n)%mod+upper_dp[a]+sum_dp[a])%mod;
		ans=(sum_dp[a]+ans)%mod;
		ll sum=upper_dp[a];
		tmp=-table.Comb(n-size[a],k);
		for(auto x:G[a]){
			if(pare[x]==a){
				sum=(sum+lower_dp[x])%mod;
				tmp=(tmp-table.Comb(size[x],k))%mod;
			}
		}for(auto x:G[a]){
			if(pare[x]==a){
				upper_dp[x]=(sum-lower_dp[x])%mod;
				ll D=(tmp+table.Comb(size[x],k)+table.Comb(n-size[x],k))%mod;
				upper_dp[x]=(upper_dp[x]+(D*(n-size[x]))%mod)%mod;
			}
		}
	}/*
	vec_out(lower_dp);
	vec_out(upper_dp);
	vec_out(sum_dp);*/
	cout<<(ans+mod)%mod<<"\n";
}