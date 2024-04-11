#include<bits/stdc++.h>
#define int long long
#define lb long double
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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
int n,m,a[55],b[55];
void solve(){
	cin>>n>>m;
	FOR(i,1,n){
		char c;
		cin>>c;
		a[i]=c-'0';
	}
	FOR(i,1,m){
		char c;
		cin>>c;
		b[i]=c-'0';
	}
	FOR(i,2,m)if(a[i+n-m]!=b[i]){
		cout<<"No\n";RE;
	}
	if(b[1]){
		FOR(i,1,n-m+1){
			if(a[i]==1){
				cout<<"Yes\n";RE;
			}
		}
		cout<<"No\n";
	}else{
		FOR(i,1,n-m+1){
			if(!a[i]){
				cout<<"Yes\n";RE;
			}
		}
			cout<<"No\n";
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}