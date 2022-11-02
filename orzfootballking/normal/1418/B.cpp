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
int n,a[105],b[105],l[105],p[105];
void solve(){
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n)cin>>b[i];
	int cnt=0;
	FOR(i,1,n){
		if(!b[i]){
			p[++cnt]=a[i];
			l[cnt]=i;
		}
	}
	sort(p+1,p+cnt+1,greater<int>());
	FOR(i,1,cnt){
		a[l[i]]=p[i];
	}
	int sum=0;
	FOR(i,1,n)cout<<a[i]<<' ';
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