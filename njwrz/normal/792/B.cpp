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
int n,k,a[105];
bool f[105];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	FOR(i,1,k)cin>>a[i];
	int now=0;
	FOR(i,1,k){
		a[i]%=(n-i+1); 
		FOR(j,1,a[i]){
			now=(now+1)%n;
			while(f[now])now=(now+1)%n;
		}
		f[now]=1;
		cout<<now+1<<' ';
		now=(now+1)%n;
		while(f[now])now=(now+1)%n;
	}
	RE 0;
}