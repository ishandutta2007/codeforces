#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define ii pair<int,int>
#define vii vector<pair<int,int>>
#define vi vector<int>
 
int dp[100010] , n , m , visited[100010];
vii adj[100010];
 
void dfs(int x , int t){
	visited[x] = 1;
	int res = 0 ;
	ii v;
	for(int i=0;i<adj[x].size();i++){
		v = adj[x][i];
		if(v.se > t) continue;
		if(!visited[v.fi]) dfs(v.fi,t);
		res = max(res , dp[v.fi]);
	}
	dp[x] = res+1 ;
}
 
int chk(int tme){
	int res = 0;
	for(int i=1;i<=n;i++) dp[i] = visited[i] = 0 ;
	for(int i=1;i<=n;i++){
		if(!visited[i]) dfs(i,tme);
		if(dp[i] > res) res = dp[i];
	}
	return res;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int aa , bb;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		cin>>aa>>bb;
		adj[aa].push_back({bb,i});
	}
	int f = 1, l = m , mid , ans ;
	while(f<=l){
		mid = (f+l)/2;
		ans = chk(mid);
		if(ans == n){
			if(f == l) break;
			l = mid;
		}
		else{
			if(f == l)break;
			f = mid+1;
		}
	}
	if(ans == n) cout<<mid;
	else cout<<-1;
}