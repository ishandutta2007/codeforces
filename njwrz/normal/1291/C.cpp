#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int a[3505],n,m,k;
void solve(){
	cin>>n>>m>>k;m--;k=min(k,m);
	FOR(i,1,n)cin>>a[i];
	int maxi=0;
	FOR(i,0,k){
		int l=i+1,r=n-k+i;
		int mini=2147483647;
		FOR(j,0,m-k){
			mini=min(mini,max(a[l+j],a[r-m+k+j]));
		}
		maxi=max(maxi,mini);
	}
	cout<<maxi<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}