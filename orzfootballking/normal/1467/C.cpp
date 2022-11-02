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
int l[3],a[3][300005];
int mini[3],s[3];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	rep(i,0,3)cin>>l[i];
	rep(i,0,3)mini[i]=1e9;
	int maxi=0;
	rep(i,0,3){
		s[i]=0;
		FOR(j,1,l[i]){
			cin>>a[i][j];maxi+=a[i][j];
			gmin(mini[i],a[i][j]);
			s[i]+=a[i][j];
		}
	}
	int sum=maxi;
	sort(mini,mini+3);
	maxi=sum-2*(mini[0]+mini[1]);
	rep(i,0,3){
		gmax(maxi,sum-s[i]*2);
	}
	cout<<maxi<<'\n';
	RE 0;
}