#pragma GCC optimize(2)
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
#define lc (x<<1)
#define rc ((x<<1)^1)
using namespace std;
int dp[11][2][2];
void solve(){
	string s;
	cin>>s;
	reverse(ALL(s));
	FILL(dp,0);
	dp[0][0][0]=1;
	rep(i,0,s.size()){
		rep(t1,0,2){
			rep(t2,0,2){
				FOR(j,0,9){
					FOR(k,0,9)if((j+k+t1)%10==s[i]-'0'){
						dp[i+1][t2][j+k+t1>=10]+=dp[i][t1][t2];
					}
				}
			}
		}
	}
	cout<<dp[s.size()][0][0]-2<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}