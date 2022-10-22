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
int a[200005],h[200005],cnt,it[200005];
void solve(){
	int n;
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	cnt=0;
	int ans=0;
	FOR(i,1,n){
		if(!cnt||h[cnt]<=a[i]){
			h[++cnt]=a[i],it[cnt]=i;
		}else{
			if(cnt)ans-=a[i]-h[cnt];
			int now;
			while(cnt&&h[cnt]<a[i]){
				now=it[cnt];
				cnt--;
			}
			h[++cnt]=a[i];it[cnt]=now;
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