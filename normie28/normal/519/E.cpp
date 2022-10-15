#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define rep(i,n) for(int64_t i=0;i < (int64_t)(n);i++)
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define FILE_IN "exp.inp"
#define FILE_OUT "exp.out"
#define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout)
#define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nfio cin.tie(0);cout.tie(0)
#define max(x,y) (((x)>(y))?(x):(y))
#define min(x,y) (((x)<(y))?(x):(y))
#define ord(a,b,c) ((a>=b)and(b>=c))
#define MOD (ll(111539768))
#define MAX 300001
#define mag 320
#define p1 first
#define p2 second.first
#define p3 second.second
#define fi first
#define se second
#define pow2(x) (ll(1)<<x)
#define pii pair<int,int>
#define piii pair<int,pii>
#define For(i,__,___) for(int i=__;i<=___;i++)
#define Rep(i,__,___) for(int i=__;i>=___;i--)
#define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>
#define endl "\n"
typedef long long ll;
 
int N;
vector<int> adjList[100010];
int L[100010];
int C[100010];
int A[100010][20];
 
int dfs(int u,int p,int l){
	A[u][0] = p;
	L[u] = l;
	C[u] = 1;
	for(auto v: adjList[u]) if(v != p) C[u] += dfs(v,u,l+1);
	return C[u];
}
 
int lca(int x,int y){
	if(L[x] < L[y]) swap(x,y);
	
	for(int i=19;i>=0;i--) if(L[x]-(1<<i) >= L[y]) x = A[x][i];
	if(x == y) return x;
 
	for(int i=19;i>=0;i--) if(A[x][i] != A[y][i]){
		x = A[x][i];
		y = A[y][i];
	}
	return A[x][0];
}
 
int solve(int x,int y){
	if(x == y) return N;
	
	//cout<<x+1<<" "<<y+1<<" "<<L[x]<<" "<<L[y]<<endl;
	if(L[x] == L[y]){
		for(int i=19;i>=0;i--) if(A[x][i] != A[y][i]){
			x = A[x][i];
			y = A[y][i];
		}
		return N - C[x] - C[y];
	}
	
	if(L[x] < L[y]) swap(x,y);
	int p = lca(x,y);
	//L[x] - L[np] = L[y] - L[p] + L[np] - L[p];
	int reql = L[x] + 2*L[p] - L[y];
	if(reql&1) return 0;
	reql >>= 1;
	
	assert(reql != L[x]);
	for(int i=19;i>=0;i--) if(L[x] - (1<<i) > reql) x = A[x][i];
	return C[A[x][0]] - C[x];
}
 
int main(){
	cin>>N;
	for(int i=1;i<N;i++){
		int x,y;cin>>x>>y;x--;y--;
		adjList[x].push_back(y);
		adjList[y].push_back(x);
	}
	dfs(0,-1,0);
	for(int j=1;j<20;j++) for(int i=0;i<100010;i++) A[i][j] = (A[i][j-1] != -1?A[A[i][j-1]][j-1]:-1);
	int M;cin>>M;
	for(int i=0;i<M;i++){
		int x,y;cin>>x>>y;x--;y--;
		cout<<solve(x,y)<<endl;		
	}
}