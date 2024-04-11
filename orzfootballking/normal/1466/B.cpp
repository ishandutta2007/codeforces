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
int n,a[100005];
int cnt[200005];
void solve(){
	cin>>n;
	FOR(i,0,2*n+1)cnt[i]=0;
	FOR(i,1,n)cin>>a[i],cnt[a[i]]++;
	bool f=0;
	int ans=0;
	FOR(i,1,2*n+1){
		if(!cnt[i]){
			ans+=f;
			f=0;
		}else{
			if(cnt[i]>1){
				f=1;
			}
			ans++;
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