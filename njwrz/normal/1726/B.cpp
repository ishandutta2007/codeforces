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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
using namespace std;
void solve(){
	int n,m;
	cin>>n>>m;
	if(n>m){
		cout<<"No\n";RE;
	}
	if(n&1){
		cout<<"Yes\n";
		rep(i,1,n)cout<<1<<' ';
		cout<<m-n+1<<'\n';
		RE;
	}
	if(!(m&1)){
		cout<<"Yes\n";
		FOR(i,1,n-2){
			cout<<1<<' ';
		}
		int now=m-(n-2);
		cout<<now/2<<' '<<now/2<<'\n';
		RE;
	}
	cout<<"No\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}