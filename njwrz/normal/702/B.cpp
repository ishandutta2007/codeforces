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
map<int,int> mp;
int a[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,1,n)cin>>a[i],mp[a[i]]++;
	int ans=0;
	sort(a+1,a+n+1);
	rep(i,0,31){
		int t=(1<<i);
		FOR(j,1,n){
			if(a[j]<t/2){
				int s=mp[t-a[j]];
				ans+=s;
			}
			if(a[j]==t/2&&a[j]!=a[j-1]){
				int s=mp[a[j]];
				ans+=s*(s-1)/2;
			}
		}
	}
	cout<<ans;
	RE 0;
}