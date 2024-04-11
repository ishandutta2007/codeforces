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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
int n,a[100005],sum0[100005],sum1[100005];
void solve(){
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	int st=1;
	while(st<=n&&!a[st])st++;
	if(st>n){
		cout<<0<<"\n";RE;
	}
	FOR(i,1,n){
		sum1[i]=sum1[i-1]+(a[i]==1);
	}
	sum0[n+1]=0;
	for(int i=n;i>=1;i--)sum0[i]=sum0[i+1]+(a[i]==0);
	int ans=1e9;
	FOR(i,1,n+1){
		gmin(ans,max(sum1[i-1],sum0[i]));
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}