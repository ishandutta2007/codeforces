/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
map<int,int> mp;
int x1,x2;
int dfs(int x){
	if(x==1)RE x1;
	if(mp[x]){
		RE mp[x];
	}
	if(x&1){
		RE mp[x]=min(dfs((x+1)/2)+x1+x2,dfs(x-1)+x1);
	}else RE mp[x]=dfs(x/2)+min(x1*(x/2),x2);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n>>x1>>x2;
	cout<<dfs(n);
	RE 0;
}