#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define ll long long
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
int n,a[3005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int ans=0;
	FOR(i,1,n)cin>>a[i];
	rep(i,1,n){
		FOR(j,i+1,n)if(a[i]>a[j])ans++;
	}
	if(ans&1)cout<<ans*2-1;else cout<<ans*2;
	RE 0;
}