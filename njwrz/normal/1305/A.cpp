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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int a[1005],b[1005],n;
void solve(){
	cin>>n;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n)cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	FOR(i,1,n)cout<<a[i]<<' ';cout<<'\n';
	FOR(i,1,n)cout<<b[i]<<' ';cout<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}