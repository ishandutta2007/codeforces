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
int n,m,a[100005],p[100005];
void solve(){
	cin>>n>>m;
	FOR(i,1,m)cin>>a[i];
	sort(a+1,a+m+1);
	int cnt=0;
	FOR(i,2,m)p[++cnt]=a[i]-a[i-1]-1;
	p[++cnt]=a[1]+n-a[m]-1;
	sort(p+1,p+m+1);reverse(p+1,p+m+1);
	int ans=m;
	FOR(i,1,m){
		int t=(i-1)*2;
		t*=2;
		t++;
		if(p[i]==t){
			ans+=t-1;
		}
		else ans+=min(p[i],t);
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