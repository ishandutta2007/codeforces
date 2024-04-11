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
	int N;
	cin>>N;
	struct edge
	{
		int to;
		ll len;
	};
	
	vector<vector<edge>> G(N);
	ll base=0;
	rep(i,N-1){
		int a,b,c;
		cin>>a>>b>>c;
		a--,b--;
		G[a].push_back({b,c});
		G[b].push_back({a,c});
		base+=2ll*c;
	}
	vector<ll> lower_dim(N),lower_path(N),upper_dim(N),upper_path(N);
	vector<int> order={0},pare(N,-1),pare_lenth(N);
	pare[0]=-2;
	rep(i,N){
		int a=order[i];
		for(auto x:G[a]){
			if(pare[x.to]==-1){
				pare[x.to]=a;
				pare_lenth[x.to]=x.len;
				order.push_back(x.to);
			}
		}
	}
	rep(i,N){
		int a=order[N-i-1];
		ll A=0,B=0;
		for(auto x:G[a]){
			if(pare[x.to]!=a) continue;
			if(chmax(B,lower_path[x.to]+x.len)){
				if(A<B) swap(A,B);
			}
			chmax(lower_dim[a],lower_dim[x.to]);
		}
		lower_path[a]=A;
		chmax(lower_dim[a],A+B);
	}
	ll ans=0;
	rep(i,N){
		int a=order[i];
		ll A=upper_path[a]+pare_lenth[a],B=0,C=0,D=upper_dim[a],E=0;
		for(auto x:G[a]){
			if(pare[x.to]!=a) continue;
			if(chmax(C,lower_path[x.to]+x.len)){
				if(B<C) swap(B,C);
				if(A<B) swap(A,B);
			}
			if(chmax(E,lower_dim[x.to])){
				if(D<E) swap(D,E);
			}
		}
		for(auto x:G[a]){
			if(pare[x.to]!=a) continue;
			vector<ll> q={A,B,C};
			rep(j,3){
				if(q[j]==lower_path[x.to]+x.len){
					q[j]=0;
					break;
				}
			}
			Sore(q);
			upper_path[x.to]=q[0];
			upper_dim[x.to]=q[0]+q[1];
			if(D==lower_dim[x.to]) chmax(upper_dim[x.to],E);
			else chmax(upper_dim[x.to],D);
		}
	}
	rep(i,N){
		if(i==0) continue;
		chmax(ans,pare_lenth[i]*2ll+lower_dim[i]+upper_dim[i]);
	}/*
	vec_out(lower_dim);
	vec_out(lower_path);
	vec_out(upper_dim);
	vec_out(upper_path);*/

	
	rep(i,N){
		vector<ll> q={upper_path[i]+pare_lenth[i],0,0,0};
		for(auto x:G[i]){
			if(pare[x.to]!=i) continue;
			ll tmp=x.len+lower_path[x.to];
			if(chmax(q[3],tmp)){
				for(int j=2;j>=0;j--){
					if(q[j]<q[j+1]) swap(q[j],q[j+1]);
				}
			}
		}
		chmax(ans,q[0]+q[1]+q[2]+q[3]);
	}
	cout<<base-ans<<"\n";
}