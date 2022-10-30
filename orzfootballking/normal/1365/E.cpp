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
int n,a[505];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	if(n==1){
		cout<<a[1];RE 0;
	}else if(n==2){
		cout<<(a[1]|a[2]);RE 0;
	}
	int maxi=0;
	FOR(i,1,n-2){
		FOR(j,i+1,n-1){
			FOR(k,j+1,n){
				gmax(maxi,(a[i]|a[j]|a[k]));
			}
		}
	}
	cout<<maxi;
	RE 0;
}