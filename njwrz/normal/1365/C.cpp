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
int ans[200005],n;
int a[200005],b[200005],f[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n)cin>>b[i],f[b[i]]=i;
	FOR(i,1,n){
		int t=f[a[i]];
		if(t>=i){
			ans[t-i]++;
		}else {
			ans[t-i+n]++;
		}
	}
	int maxi=0;
	rep(i,0,n)gmax(maxi,ans[i]);
	cout<<maxi;
	RE 0;
}