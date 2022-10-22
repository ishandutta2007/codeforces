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
int to[100005][34],sum[100005][34],mini[100005][34];
int w[100005],p[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	FOR(i,1,n)cin>>p[i],p[i]++;
	FOR(i,1,n)cin>>w[i];
	FOR(i,1,n){
		to[i][0]=p[i];
		mini[i][0]=sum[i][0]=w[i];
	}
	rep(i,1,34){
		FOR(j,1,n){
			to[j][i]=to[to[j][i-1]][i-1];
			sum[j][i]=sum[j][i-1]+sum[to[j][i-1]][i-1];
			mini[j][i]=min(mini[j][i-1],mini[to[j][i-1]][i-1]);
		}
	}
	FOR(i,1,n){
		int now=i,mi=1e9,anss=0;
		rep(j,0,34){
			if(k&(1ll<<j)){
				anss+=sum[now][j];
				gmin(mi,mini[now][j]);
				now=to[now][j];
			}
		}
		cout<<anss<<' '<<mi<<'\n';
//		cout<<'\n';
	} 
	RE 0;
}