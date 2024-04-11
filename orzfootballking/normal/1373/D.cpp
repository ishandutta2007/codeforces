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
int n;
int a[200005];
void solve(){
	cin>>n;
	int cnt[2]={};
	rep(i,0,n)cin>>a[i],cnt[i&1]+=a[i];
	int maxi[2];
	maxi[1]=0;
	int l=0,ans=cnt[0];
	rep(i,0,n){
		l+=(i&1)?-a[i]:a[i];
		if(i==0){
			maxi[0]=l;continue;
		}
		gmax(ans,cnt[0]+(maxi[i&1]-l));
		gmax(maxi[i&1],l);
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