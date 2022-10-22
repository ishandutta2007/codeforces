#pragma GCC optimize(2)
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
int n,a[10];
int p[9];
bool check(int x,int to){
	if(x==n-1)RE to==0;
	RE check(x+1,to)||check(x+1,to+p[x])||check(x+1,to-p[x]);
}
void solve(){
	cin>>n;
	rep(i,0,n)cin>>a[i];
	rep(i,0,n){
		rep(j,0,i)p[j]=a[j];
		rep(j,i,n-1)p[j]=a[j+1];
		if(check(0,a[i])){
			cout<<"YES\n";RE;
		}
	}
	cout<<"NO\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}