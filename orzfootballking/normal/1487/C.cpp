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
bool a[105][105];
void solve(){
	int n;
	cin>>n;
	int x=n/2;
	FOR(i,1,n){
		FOR(j,1,n){
			if(i==j)continue;
			if(j>i&&j-i<=x||j<i&&j+n-i<=x){
				a[i][j]=1;
			}else a[i][j]=0;
		}
	}
	FOR(i,1,n){
		FOR(j,i+1,n){
			if(!(n&1)&&abs(i-j)==x){
				cout<<0<<' ';
			}else{
				if(a[i][j]==0){
					cout<<-1<<' ';
				}else cout<<1<<' ';
			}
		}
	}
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