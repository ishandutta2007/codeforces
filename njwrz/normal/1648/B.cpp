#pragma GCC optimize("Ofast", "inline", "-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
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
int n,a[1000005],sum[1000005],p[1000005];
void solve(){
	int c;
	cin>>n>>c;
	FOR(i,0,c)sum[i]=0,p[i]=0;
	FOR(i,1,n)cin>>a[i],sum[a[i]]++,p[a[i]]=1;
	FOR(i,1,c)sum[i]+=sum[i-1];
	sort(a+1,a+n+1);
	FOR(i,1,c)if(p[i]){
		for(int l=i,now=1;l<=c;l+=i,now++){
			int r=min(c,l+i-1);
			if(sum[r]-sum[l-1]>0&&p[now]==0){
				cout<<"No\n";RE ;
			}
		}
	}
	cout<<"Yes\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}