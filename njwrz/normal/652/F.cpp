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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
using namespace std;
int n,m,t;
P<P<int,char> ,int> p[300005];
int pos[300005],ans[300005],out[300005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>t;
	FOR(i,1,n)cin>>p[i].F.F>>p[i].F.S,p[i].F.F--,p[i].S=i;
	sort(p+1,p+n+1);
	int tr=0;
	FOR(i,1,n){
		int now=p[i].F.F;
		if(p[i].F.S=='L'){
			now-=t;
			if(now<0){
				int tv=-now;
				tr-=(tv+m-1)/m;
			}
		}else {
			now+=t;
			tr+=now/m;
		}
		now=(now%m+m)%m;
		pos[i]=now;
	}
	sort(pos+1,pos+n+1);
	tr=(tr%n+n)%n;
	FOR(i,1,n){
		int to=(i+tr);
		to%=n;if(to==0)to=n;
		ans[p[i].S]=pos[to];
	}
	FOR(i,1,n)cout<<ans[i]+1<<' ';
	RE 0;
}