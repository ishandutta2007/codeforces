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
char c[300005];
int l[300005],r[300005];
string s="LR";
void solve(){
	int n;
	cin>>n;
	FOR(i,1,n)cin>>c[i];
	FOR(i,1,n+1)l[i]=r[i]=0;
	int cnt=0;
	FOR(i,1,n){
		if(i==1||c[i]!=c[i-1]){
			cnt++;
		}else {
			cnt=1;
		}
		if(c[i]=='L')l[i+1]=cnt;else l[i+1]=0;
	}
	cnt=0;
	for(int i=n;i>=1;i--){
		if(i==n||c[i]!=c[i+1]){
			cnt++;
		}else{
			cnt=1;
		}
		if(c[i]=='R')r[i]=cnt;else r[i]=0;
	}
	FOR(i,1,n+1){
//		cout<<l[i]<<' '<<r[i]<<'\n';
		cout<<l[i]+r[i]+1<<' ';
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