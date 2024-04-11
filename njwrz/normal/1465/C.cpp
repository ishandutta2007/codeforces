/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
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
int n;
int x[100005],y[100005];
V<int> v[100005];
bool vis[100005];
void solve(){
	int m;
	cin>>n>>m;
	int cnt=0;
	FOR(i,1,n)v[i].clear(),vis[i]=0;
	FOR(i,1,m){
		cin>>x[i]>>y[i];
		if(x[i]!=y[i])cnt++,v[x[i]].PB(y[i]);
	}
	int p=0;
	FOR(i,1,n){
		if(!vis[i]&&!v[i].empty()){
			int t=i;
			vis[t]=1;
			t=v[t].back();
			while(t!=i){
				if(v[t].empty()||vis[t]){
					p--;break;
				}
				vis[t]=1;
				t=v[t].back();
			}
			p++;
		}
	}
	cout<<p+cnt<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}