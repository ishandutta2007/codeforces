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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int dp[505][505],p[505];
int n,a[505];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	FILL(dp,-1);
	cin>>n;
	FOR(i,1,n)cin>>a[i],dp[i][i]=a[i];
	int r;
	FOR(i,2,n){
		FOR(l,1,n-i+1){
			r=l+i-1;
			rep(k,l,r){
				if(dp[l][k]!=-1&&dp[l][k]==dp[k+1][r]){
					dp[l][r]=dp[l][k]+1;
				}
			} 
		}
	}
	FOR(i,1,n){
		p[i]=2147483647;
		FOR(j,1,i){
			if(dp[j][i]!=-1){
				gmin(p[i],p[j-1]+1);
			}
		}
	}
	cout<<p[n];
	RE 0;
}