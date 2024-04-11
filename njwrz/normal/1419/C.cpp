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
int a[1005];
void solve(){
	int n,x;
	cin>>n>>x;
	int sum=0;
	int cnt=0;
	FOR(i,1,n)cin>>a[i],sum+=a[i]-x;
	FOR(i,1,n)cnt+=a[i]==x;
	if(cnt==n)cout<<0<<'\n';
	else if(cnt)cout<<1<<'\n';
	else if(!sum)cout<<1<<'\n';
	else cout<<2<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}