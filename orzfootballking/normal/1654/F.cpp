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
int n;
char c[1<<18],ans[1<<18];
int rnk[1<<18][20],val[1<<18];
P<int,int> p[1<<18];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	rep(i,0,1<<n)cin>>c[i],rnk[i][0]=c[i]-'a';
	int t=0;
	rep(i,0,n){
		rep(j,0,1<<n){
			val[j]=rnk[j][i]*((1<<n)+1)+rnk[j^(1<<i)][i];
			p[j]=MP(val[j],j);
		}
		sort(p,p+(1<<n));
		rnk[p[0].S][i+1]=1;
		rep(j,1,1<<n){
			rnk[p[j].S][i+1]=rnk[p[j-1].S][i+1]+(p[j].F!=p[j-1].F);
		}
//		rep(j,0,1<<n)cout<<rnk[j][i]<<' ';
//		cout<<'\n';
		if(i==n-1)t=p[0].S;
	}
	rep(i,0,1<<n)ans[i^t]=c[i];
	rep(i,0,1<<n)cout<<ans[i];
	RE 0;
}