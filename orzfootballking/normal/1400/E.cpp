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
V<int> v[5005];
int l[5005],r[5005];
int cost[5005],cnt,a[5005],co[5005],c2[5005];
void dfs(int x){
	int mini=1e9;
	FOR(i,l[x],r[x])gmin(mini,a[i]),c2[x]+=a[i]!=0;
	co[x]+=mini;
	if(l[x]==r[x])RE;
	int lst=l[x]-1;
	FOR(i,l[x],r[x]){
		if(a[i]==mini&&lst<i-1){
			cnt++;
			l[cnt]=lst+1;r[cnt]=i-1;v[x].PB(cnt);co[cnt]=-mini;
			dfs(cnt);
		}
		if(a[i]==mini)lst=i;
	}
	if(lst<r[x]){
		cnt++;
		l[cnt]=lst+1;r[cnt]=r[x];v[x].PB(cnt);co[cnt]=-mini;
		dfs(cnt);
	}
}
void get(int x){
	cost[x]=co[x];
	for(auto u:v[x]){
		get(u);
		cost[x]+=cost[u];
	}
	gmin(cost[x],c2[x]);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	cnt++;
	l[1]=1;r[1]=n;
	dfs(1);
	get(1);
	cout<<cost[1];
	RE 0;
}