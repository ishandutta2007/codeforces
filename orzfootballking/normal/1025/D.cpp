#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,a[705];bool f[705][705],dp1[705][705],dp2[705][705];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n){
		FOR(j,1,n)if(__gcd(a[i],a[j])!=1)f[i][j]=1;
	}
	FOR(i,1,n)dp1[i][i]=dp2[i][i]=1;
	int j;
	rep(l,0,n-1){
		FOR(i,1,n-l){
			j=i+l;
			FOR(k,i,j){
				if(dp1[i][k]&&dp2[k][j]){
					if(f[k][j+1])dp1[i][j+1]=1;
					if(f[k][i-1])dp2[i-1][j]=1;
				}
			}
		}
	}
	FOR(i,1,n){
		if(dp1[1][i]&&dp2[i][n]){
			cout<<"Yes";RE 0;
		}
	}
	cout<<"No";
	RE 0;
}