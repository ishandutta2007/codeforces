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
int a[5005],b[5005],p[5005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	int x,y;
	cin>>n;
	FOR(i,1,n){
		cin>>a[i]>>b[i];
		p[i]=i;
	}
	rep(i,1,n){
		int maxi=-1e9,it=0;
		FOR(j,i+1,n){
			x=a[p[i]]-a[p[j]];
			y=b[p[i]]-b[p[j]];
			int t=x*x+y*y;
			if(t>maxi){
				maxi=t;
				it=j;
			}
		}
		swap(p[i+1],p[it]);
	} 
	FOR(i,1,n)cout<<p[i]<<' ';
	RE 0;
}