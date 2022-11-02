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
bool f[100005];int a[100005],b[100005];
void solve(){
	int n,mini=1e9;
	cin>>n;
	FOR(i,1,n)cin>>a[i],gmin(mini,a[i]),f[i]=0,b[i]=a[i];
	FOR(i,1,n)f[i]=a[i]%mini==0;
	sort(b+1,b+n+1);
	FOR(i,1,n){
		if(a[i]!=b[i]&&!f[i]){
			cout<<"NO\n";RE;
		}
	}
	cout<<"YES\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}