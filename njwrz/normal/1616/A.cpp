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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int n,a[105];
void solve(){
	cin>>n;
	FOR(i,1,n)cin>>a[i],a[i]=abs(a[i]);
	sort(a+1,a+n+1);
	int ans=0,len=0;
	FOR(i,1,n){
		if(i>1&&a[i]>a[i-1]){
			ans+=min(len,((a[i-1]>0)?2:1));
			len=1;
		}else len++;
	}
	ans+=min(len,((a[n]>0)?2:1));
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