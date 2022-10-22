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
int check(int n,int x){
	if(x==1)RE 0;
	__int128 now=x;
	now=now*(now+1)/2;
	RE (n%x==now%x&&now<=n);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		if(n&1){
			cout<<2<<'\n';
		}else {
			int t=1,tt=n;
			while(tt%2==0){
				tt/=2;
				t*=2;
			}
			int ans=-1;
			if(check(n,t*2))ans=t*2;
			if(check(n,tt))ans=tt;
			cout<<ans<<'\n';
		}
	}
	RE 0;
}