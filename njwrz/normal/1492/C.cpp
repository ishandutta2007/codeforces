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
char a[200005],b[200005];
int l[200005],r[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int m,n;
	cin>>m>>n;
	FOR(i,1,m)cin>>a[i];
	FOR(i,1,n)cin>>b[i];
	FOR(i,1,n){
		l[i]=l[i-1]+1;
		while(l[i]<=m&&a[l[i]]!=b[i])l[i]++;
	}
	r[n+1]=m+1;
	for(int i=n;i>=1;i--){
		r[i]=r[i+1]-1;
		while(r[i]>0&&a[r[i]]!=b[i])r[i]--;
	}
	int ans=0;
	rep(i,1,n){
		if(l[i]<r[i+1]){
			gmax(ans,r[i+1]-l[i]);
		}
	}
	cout<<ans;
	RE 0;
}