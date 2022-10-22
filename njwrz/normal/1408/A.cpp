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
int a[3][105],ans[105],n;
void solve(){
	cin>>n;
	FOR(i,0,2){
		FOR(j,1,n)cin>>a[i][j];
	}
	ans[1]=0;
	FOR(i,2,n){
		rep(j,0,3){
			if(a[j][i]!=a[ans[i-1]][i-1]){
				ans[i]=j;break;
			}
		}
	}
	if(a[ans[n]][n]==a[ans[1]][1]){
		rep(j,0,3){
			if(a[j][n]!=a[ans[n-1]][n-1]&&a[j][n]!=a[ans[1]][1]){
				ans[n]=j;break;
			}
		}
	}
	FOR(i,1,n)cout<<a[ans[i]][i]<<' ';
	cout<<'\n'; 
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}