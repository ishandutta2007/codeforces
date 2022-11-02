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
P<int,int> p[105];
bool f[105][105];
void solve(){
	int n,k;
	cin>>n>>k;
	FOR(i,1,n){
		cin>>p[i].F>>p[i].S;
	}
	FILL(f,0);
	FOR(i,1,n){
		FOR(j,i+1,n){
			if(abs(p[i].F-p[j].F)+abs(p[i].S-p[j].S)<=k){
				f[i][j]=f[j][i]=1;
			}
		}
		f[i][i]=1;
	} 
	FOR(i,1,n){
		int cnt=0;
		FOR(j,1,n)cnt+=f[i][j];
		if(cnt==n){
			cout<<"1\n";RE ;
		}
	}
	cout<<-1<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}