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
int ch[100005][2],a[100005],n,in[100005],ans;
map<int,int> mp;
void dfs(int x,int mini,int maxi){
	if(a[x]>=mini&&a[x]<=maxi){
		mp[a[x]]=1;
	}
	if(ch[x][0]!=-1)dfs(ch[x][0],mini,min(maxi,a[x]-1));
	if(ch[x][1]!=-1)dfs(ch[x][1],max(mini,a[x]+1),maxi);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n){
		cin>>a[i]>>ch[i][0]>>ch[i][1];
		if(ch[i][0]!=-1)in[ch[i][0]]++;
		if(ch[i][1]!=-1)in[ch[i][1]]++;
	}
	FOR(i,1,n)if(!in[i])dfs(i,0,1e9);
	FOR(i,1,n)ans+=mp[a[i]]==0;
	cout<<ans;
	RE 0;
}