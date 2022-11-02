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
int a[1005],n,m;
void solve(){
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	if(n>m||n==2){
		cout<<"-1\n";RE;
	}
	int sum=0;
	FOR(i,1,n)sum+=a[i]*2;
	cout<<sum<<'\n';
	rep(i,1,n)cout<<i<<' '<<i+1<<'\n';
	cout<<n<<' '<<1<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}