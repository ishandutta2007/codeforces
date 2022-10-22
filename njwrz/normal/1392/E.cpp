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
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int a[55][55];
signed main(){
	int n;
	cin>>n;
	FOR(i,2,n){
		a[i][1]=1ll<<(i-2);
	}
	FOR(j,2,n){
		rep(i,1,n){
			a[i][j]=a[i+1][j-1]+(1ll<<(i+j-3));
		}
	}
	FOR(i,1,n){
		FOR(j,1,n)cout<<a[i][j]<<' ';
		cout<<'\n';
	}
	fflush(stdout);
	int q;
	cin>>q;
	FOR(i,1,q){
		int x=1,y=1,t;
		cin>>t;
		cout<<x<<' '<<y<<'\n';
		rep(i,0,n+n-2){
			if(t&(1ll<<i)){
				x++;
			}else y++;
			cout<<x<<' '<<y<<'\n';
		}
		fflush(stdout);
	}
	RE 0;
}