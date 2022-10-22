#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define int long long
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
void solve(){
	int a1,a2,b1,b2;
	a1=a2=b1=b2=0;
	int n,m,x;
	cin>>n;
	FOR(i,1,n){
		cin>>x;
		if(x&1)a1++;else a2++;
	} 
	cin>>m;
	FOR(i,1,m){
		cin>>x;
		if(x&1)b1++;else b2++;
	}
	cout<<a1*b1+a2*b2<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}