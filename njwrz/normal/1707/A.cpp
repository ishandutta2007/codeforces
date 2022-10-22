#include<bits/stdc++.h>
#define int long long
#define lb long double
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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
map<int,int> mp;
int a[100005],n;
int ans[100005];
void solve(){
	int q;
	cin>>n>>q;
	FOR(i,1,n)cin>>a[i];
	int t=max(0ll,q-n);
	for(int i=n;i>=1;i--){
		if(t>=a[i])ans[i]=1;
		else if(t<q){
			ans[i]=1;t++;
		}else ans[i]=0;
	}
	FOR(i,1,n)cout<<ans[i];
	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}