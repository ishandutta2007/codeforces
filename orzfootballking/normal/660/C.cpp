/*

DP





ll int
 dp 










*/
#pragma GCC optimize("Ofast")
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
using namespace std;
bool f[300005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	FOR(i,1,n)cin>>f[i];
	int ans=0,it=0,il=0,l=1,cnt=0;
	FOR(i,1,n){
		if(f[i]==0){
			cnt++;
			if(cnt>m){
				while(f[l]&&l<=i)l++;
				cnt--;
				l++;
			}
		}
		if(i-l+1>ans){
			ans=i-l+1;
			it=i;il=l;
		}
	}
	cout<<ans<<'\n';
	FOR(i,1,n){
		if(i>=il&&i<=it){
			cout<<1<<' ';
		}else cout<<f[i]<<' ';
	}
	RE 0;
}