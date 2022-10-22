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
int a[3005],cnt[3005];
void solve(){
	int n;
	cin>>n;
	FOR(i,1,n){
		cin>>a[i];
	}
	int ans=0;
	FOR(i,3,n-1){
		FILL(cnt,0);
		FOR(j,i+1,n)cnt[a[j]]++;
		int sum=0;
		for(int j=i-1;j>=1;j--){
			if(a[j]==a[i]){
				ans+=sum;
			}
			sum+=cnt[a[j]];
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}