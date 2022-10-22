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
int a[1<<19];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;cin>>n;
	rep(i,0,n)cin>>a[i];
	rep(i,0,19){
		rep(j,0,n)if(j&(1<<i))a[j]^=a[j-(1<<i)];
	}
	rep(i,0,19){
		rep(j,0,n)if(j&(1<<i))a[j-(1<<i)]^=a[j];
	}
	reverse(a,a+n);
	rep(i,0,n)cout<<a[i]<<' ';
	RE 0;
}