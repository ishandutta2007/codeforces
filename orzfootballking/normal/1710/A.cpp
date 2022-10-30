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
int n,m,k,a[100005];
void solve(){
	cin>>n>>m>>k;
	FOR(i,1,k)cin>>a[i];
	int sum=0;
	bool f=1;
	FOR(i,1,k){
		if(a[i]/n>=2)sum+=a[i]/n;
		if(a[i]/n>2)f=0;
	}
	if(sum>=m&&(!(m&1)||!f)){
		cout<<"Yes\n";RE;
	}
	sum=0;f=1;
	FOR(i,1,k){
		if(a[i]/m>=2)sum+=a[i]/m;
		if(a[i]/m>2)f=0;
	}
	if(sum>=n&&(!(n&1)||!f)){
		cout<<"Yes\n";
	}else cout<<"No\n";
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}