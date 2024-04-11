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
double p1[100005],p2[100005];int a[100005];
void solve(){
	int n,l;
	cin>>n>>l;
	FOR(i,1,n)cin>>a[i];
	a[n+1]=l;
	FOR(i,1,n+1){
		p1[i]=p1[i-1]+1.0*(a[i]-a[i-1])/i;
	}
	p2[n+1]=0;
	for(int i=n;i>=0;i--){
		p2[i]=p2[i+1]+1.0*(a[i+1]-a[i])/(n-i+1);
	}
	FOR(i,0,n){
		if(p1[i]<=p2[i]&&p1[i+1]>=p2[i+1]){
			double ans;
			if(p1[i]>p2[i+1]){
				ans=p1[i]+1.0*(a[i+1]-a[i]-(p1[i]-p2[i+1])*(n-i+1))/(n+2);
			}else ans=p2[i+1]+1.0*(a[i+1]-a[i]-(p2[i+1]-p1[i])*(i+1))/(n+2);
			printf("%.10f",ans);
			cout<<'\n';
			RE;
		}
	}
}
signed main(){
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}