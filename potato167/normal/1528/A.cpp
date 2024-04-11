#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
using std::cout;
using std::cin;
using std::endl;
using ll=long long;
using ld=long double;
ll I=1167167167167167167;
ll Q=1e9+7;
#define rep(i,a) for (ll i=0;i<a;i++)
template<class T> using _pq = priority_queue<T, vector<T>, greater<T>>;
template<class T> ll LB(vector<T> &v,T a){return lower_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> ll UB(vector<T> &v,T a){return upper_bound(v.begin(),v.end(),a)-v.begin();}
template<class T> bool chmin(T &a,const T &b){if(a>b){a=b;return 1;}else return 0;}
template<class T> bool chmax(T &a,const T &b){if(a<b){a=b;return 1;}else return 0;}
template<class T> void So(vector<T> &v) {sort(v.begin(),v.end());}
template<class T> void Sore(vector<T> &v) {sort(v.begin(),v.end(),[](T x,T y){return x>y;});}
template<class T> void print_tate(vector<T> &v) {rep(i,v.size()) cout<<v[i]<<"\n";}
void yneos(bool a){if(a) cout<<"Yes"<<"\n"; else cout<<"No"<<"\n";}



using F=ll;

void DFS(int a,int b,vector<ll> &dpl,vector<ll> &dpr,vector<vector<int>> &G,vector<ll> &R,vector<ll> &L){
	for(auto x:G[a]){
		if(x!=b){
			DFS(x,a,dpl,dpr,G,R,L);
			dpl[a]+=max(abs(L[a]-L[x])+dpl[x],abs(L[a]-R[x])+dpr[x]);
			dpr[a]+=max(abs(R[a]-L[x])+dpl[x],abs(R[a]-R[x])+dpr[x]);	
		}
	}
	return ;
}

F solve(){
	int N;
	cin>>N;
	vector<ll> L(N),R(N);
	rep(i,N) cin>>L[i]>>R[i];
	vector<vector<int>> G(N);
	rep(i,N-1){
		int a,b;
		cin>>a>>b;
		a--,b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	/*vector<int> oya(N,-1);
	oya[0]=-2;
	vector<int> jyun={0};
	for(int i=0;i<N;i++){
		ll a=jyun[i];
		for(auto y:G[a]){
			auto x=y; //T
			if(oya[x]==-1) jyun.push_back(x),oya[x]=a;
		}
	}*/
	vector<ll> dpl(N),dpr(N);
	DFS(0,-1,dpl,dpr,G,R,L);
	/*for(int i=N-1;i>=0;i--){
		int a=jyun[i];
		for(auto x:G[a]){
			if(oya[a]!=x){
				dpl[a]+=max(abs(L[a]-L[x])+dpl[x],abs(L[a]-R[x])+dpr[x]);
				dpr[a]+=max(abs(R[a]-L[x])+dpl[x],abs(R[a]-R[x])+dpr[x]);	
			}
		}
	}*/
	return max(dpl[0],dpr[0]);
}

//main
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin>>T;
	vector<F> ans(T);
	rep(i,T) ans[i]=solve();
	print_tate(ans);
}