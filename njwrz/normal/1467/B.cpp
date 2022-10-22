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
int a[300005];
int f[300005];
int n;
bool check(int i){
	if(i==1||i==n)RE 0;
	if(a[i]>a[i-1]&&a[i]>a[i+1])RE 1;else if(a[i]<a[i-1]&&a[i]<a[i+1])RE 1;
	RE 0;
}
void solve(){
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	int ans=0;
	FOR(i,1,n)f[i]=0;
	FOR(i,2,n-1){
		if(a[i]>a[i-1]&&a[i]>a[i+1])f[i]=1;else if(a[i]<a[i-1]&&a[i]<a[i+1])f[i]=2;
		ans+=f[i]>0;
	}
	int mini=ans;
	FOR(i,2,n-1){
		int t=a[i];
		
		a[i]=a[i-1];
		gmin(mini,ans-(f[i]>0)-(f[i-1]>0)-(f[i+1]>0)+check(i)+check(i-1)+check(i+1));
		
		a[i]=a[i+1];
		gmin(mini,ans-(f[i]>0)-(f[i-1]>0)-(f[i+1]>0)+check(i)+check(i-1)+check(i+1));
		
		a[i]=t;
	}
	cout<<max(mini,0)<<'\n';
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}