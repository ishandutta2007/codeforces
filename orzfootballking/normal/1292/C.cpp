#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int dp[3005][3005],fa[3005][3005],tree[3005][3005];
int n;
V<int> v[3005];
inline void dfs(int root,int p){
	tree[root][p]=1;
	for(int i=0;i<v[p].size();i++){
		if(v[p][i]!=fa[root][p]){
			fa[root][v[p][i]]=p;
			dfs(root,v[p][i]);
			tree[root][p]+=tree[root][v[p][i]];
		}
	}
}
inline int get(int i,int j){
	if(dp[i][j]!=-1)RE dp[i][j];
	if(i==j)RE dp[i][j]=0;
	RE dp[i][j]=max(get(i,fa[i][j]),get(j,fa[j][i]))+tree[i][j]*tree[j][i];
}
signed main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>n;int x,y;
	FOR(i,1,n-1){
		cin>>x>>y;
		v[x].PB(y);v[y].PB(x); 
	}
	FOR(i,1,n)dfs(i,i);
	int ans=0;
	FILL(dp,-1);
	FOR(i,1,n-1)FOR(j,i+1,n)ans=max(ans,get(i,j));
	cout<<ans;
	return 0;
}