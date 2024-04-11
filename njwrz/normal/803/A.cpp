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
int n,tk; 
int a[105][105]; 
V<int> ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>tk;
	FOR(i,1,n*n)ans.PB(0);
	if(tk>n*n){
		cout<<-1;RE 0;
	}else{
		FOR(i,0,min(n,tk)){
			if((i&1)==(tk&1)){
				int t=tk;t-=i;
				FILL(a,0);
				FOR(j,1,i)a[j][j]=1;
				FOR(j,1,n){
					FOR(k,1,n){
						if(j!=k&&!a[j][k]&&t){
							a[j][k]=a[k][j]=1;
							t-=2;
						}
					}
				}
				V<int> now;
				FOR(i,1,n){
					FOR(j,1,n)now.PB(a[i][j]);
				}
				gmax(ans,now);
			}
		}
	}
	int cnt=0;
	for(auto u:ans){
		++cnt;
		cout<<u<<' ';
		if(cnt%n==0)cout<<'\n';
	}
	RE 0;
}