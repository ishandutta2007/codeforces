#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
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
template<class T> T min(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmin(ans,x);return ans;}
template<class T> T max(vector<T> &a){assert(!a.empty());T ans=a[0];for(auto &x:a) chmax(ans,x);return ans;}

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
	long long P(int x,int y){
		assert(upper>=x);
		if (x<y||y<0||x<0) return 0;
		return (fact_rev[x-y]*fact[x])%MOD;
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
	ll N;
	cin>>N;
	combination table(N,mod);
	int L=2e5+167;
	vector<vector<int>> p(L);
	for(int i=2;i<L;i++){
		if(!p[i].empty()) continue;
		for(int j=i;j<L;j+=i) p[j].push_back(i);
	}
	vector<map<int,int>> m(N);
	vector<ll> val(N);
	vector<int> base(L);
	vector<int> A(N);
	rep(i,N){
		cin>>A[i];
		for(auto x:p[A[i]]) base[x]++;
	}
	ll ans=0;
	auto G=tree_in(N);
	vector<int> pare,depth,order;
	tie(order,pare,depth)=tree_order_pare_depth(G,0);
	ll ini=0;
	for(auto x:base) ini=(ini+table.Comb(x,3))%mod;
	for(int i=N-1;i>=0;i--){
		int a=order[i];
		val[a]=ini;
		int ind=-1;
		for(auto x:G[a]){
			if(pare[x]!=a) continue;
			if(ind==-1) ind=x;
			else if(m[ind].size()<m[x].size()) ind=x;
		}
		ll tmp=ini;
		if(ind!=-1){
			swap(val[ind],val[a]);
			swap(m[ind],m[a]);
			tmp=val[a];
		}
		for(auto x:G[a]){
			if(pare[x]!=a) continue;
			if(ind==x) continue;
			for(auto y:m[x]){
				val[a]-=table.Comb(base[y.first]-m[a][y.first],3);
				val[a]-=table.Comb(m[a][y.first],3);
				tmp   -=table.Comb(base[y.first]-m[a][y.first],3);
				m[a][y.first]+=y.second;
				val[a]+=table.Comb(base[y.first]-m[a][y.first],3);
				val[a]+=table.Comb(m[a][y.first],3);
				tmp+=table.Comb(y.second,3);
				tmp+=table.Comb(base[y.first]-m[a][y.first],3);
				val[a]%=mod;
			}
		}
		for(auto x:p[A[a]]){
			val[a]-=table.Comb(base[x]-m[a][x],3);
			val[a]-=table.Comb(m[a][x],3);
			tmp-=table.Comb(base[x]-m[a][x],3);
			tmp+=table.Comb(base[x]-m[a][x]-1,3);
			m[a][x]++;
			val[a]+=table.Comb(base[x]-m[a][x],3);
			val[a]+=table.Comb(m[a][x],3);
		}
		tmp%=mod;
		val[a]%=mod;
		ans=(ans-tmp)%mod;
	}
	for(auto x:base){
		ans=(ans+table.Comb(x,3)*(N-1))%mod;
	}
	cout<<(ans+mod)%mod<<"\n";
}