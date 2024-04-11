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
int n,m,k,a[105];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m>>k;
	FOR(i,1,k)cin>>a[i];
	int ans=0;
	FOR(i,1,n){
		FOR(j,1,m){
			int x;
			cin>>x;
			FOR(t,1,k){
				if(a[t]==x){
					ans+=t;
					for(int p=t;p>=2;p--)a[p]=a[p-1];
					a[1]=x;
					break;
				}
			}
		}
	}
	cout<<ans;
	RE 0;
}