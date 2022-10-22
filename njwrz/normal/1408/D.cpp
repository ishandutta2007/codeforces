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
P<int,int> pa[2005],pb[2005];
int maxi[1000005];
int main(){
	int n,m;
	cin>>n>>m;
	FOR(i,1,n)cin>>pa[i].F>>pa[i].S;
	FOR(i,1,m)cin>>pb[i].F>>pb[i].S;
	FOR(i,1,n){
		FOR(j,1,m){
			if(pa[i].F<=pb[j].F&&pa[i].S<=pb[j].S){
				gmax(maxi[pb[j].F-pa[i].F],pb[j].S-pa[i].S+1);
			}
		}
	}
	int ans=1e9;
	for(int i=1000000;i>=0;i--){
		gmax(maxi[i],maxi[i+1]);
		gmin(ans,i+maxi[i]);
	}
	cout<<ans;
	RE 0;
}