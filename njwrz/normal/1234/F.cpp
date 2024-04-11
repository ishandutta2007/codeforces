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
int dp[1<<20];
bool f[1<<20];
string s;
int c[1000005];
int n;
int vis[30];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s;
	n=s.size();
	FOR(i,1,n){
		c[i]=s[i-1]-'a';
	}
	FOR(i,1,n){
		FILL(vis,0);
		int mask=0;
		FOR(j,i,n){
			if(vis[c[j]]){
				break;
			}
			vis[c[j]]=1;mask|=1<<c[j];
			f[((1<<20)-1)^mask]=1;
			dp[mask]=j-i+1;
		}
	}
	rep(i,1,1<<20){
		rep(j,0,20)if(!(i&(1<<j))){
			gmax(dp[i^(1<<j)],dp[i]);
		}
	}
	int ans=0;
	rep(i,0,1<<20)if(f[i]){
		int cnt=0;
		rep(j,0,20)if(!(i&(1<<j)))cnt++;
		cnt+=dp[i];
		gmax(ans,cnt);
	}
	cout<<ans;
	RE 0;
}