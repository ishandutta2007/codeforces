/*

DP





ll int
 dp 










*/
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
int n;
void solve(){
	int p,f,cnts,cntw,s,w;
	cin>>p>>f>>cnts>>cntw>>s>>w;
	if(s>w){
		swap(cnts,cntw);
		swap(s,w);
	}
	if(p/s+f/s<=cnts){
		cout<<p/s+f/s<<'\n';
	}else{
		int ans=cnts;
		FOR(i,0,cnts){
			if(i*s<=p&&(cnts-i)*s<=f){
				gmax(ans,cnts+(p-i*s)/w+(f-(cnts-i)*s)/w);
			}
		}
		cout<<min(ans,cnts+cntw)<<'\n';
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}