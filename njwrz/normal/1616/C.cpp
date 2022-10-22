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
int a[75],n;
void solve(){
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	int ans=n-1;
	FOR(i,1,n){
		FOR(j,i+1,n){
			int cnt=2;
			FOR(k,1,n)if(k!=i&&k!=j){
				double dif=1.0*(a[i]-a[k])/(i-k);
				if(abs(a[k]+(j-k)*dif-a[j])<1e-8){
					cnt++;
				}
			}
			gmin(ans,n-cnt);
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	while(n--)solve();
	RE 0;
}