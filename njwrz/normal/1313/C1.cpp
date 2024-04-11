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
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int n,a[1005],ans[1005],t[1005];
int maxi;
void solve(int mid){
	int re=a[mid];t[mid]=a[mid];
	for(int i=mid-1;i>=1;i--){
		t[i]=min(t[i+1],a[i]);
		re+=t[i];
	}
	FOR(i,mid+1,n){
		t[i]=min(t[i-1],a[i]);
		re+=t[i];
	}
	if(re>maxi){
		FOR(i,1,n)ans[i]=t[i];
		maxi=re;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n)solve(i);
	FOR(i,1,n)cout<<ans[i]<<' ';
	RE 0;
}