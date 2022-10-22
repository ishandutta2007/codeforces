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
#define lc (x<<1)
#define rc ((x<<1)^1)
#define y1 yyyy1111
using namespace std;
char c[100005];
void solve(){
	int n;
	cin>>n;
	FOR(i,1,n)cin>>c[i];
	if(n>1&&c[1]==c[2]){
		cout<<c[1]<<c[1]<<'\n';RE ;
	}
	rep(i,1,n)if(c[i]<c[i+1]){
		FOR(j,1,i)cout<<c[j];
		for(int j=i;j>=1;j--)cout<<c[j];
		cout<<'\n';RE ;
	}
	FOR(i,1,n)cout<<c[i];
	for(int i=n;i>=1;i--)cout<<c[i];
	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}