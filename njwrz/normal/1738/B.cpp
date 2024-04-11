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
#define sz(x) ((int)x.size())
using namespace std;
int s[100005];
void solve(){
	int n,k;
	cin>>n>>k;
	FOR(i,1,k)cin>>s[n-k+i];
	if(n==k){
		rep(i,1,n){
			if(s[i+1]-s[i]<s[i]-s[i-1]){
				cout<<"No\n";RE;
			}
		}	
		cout<<"Yes\n";
	}else{
	rep(i,n-k+2,n){
	if(s[i+1]-s[i]<s[i]-s[i-1]){
				cout<<"No\n";RE;
			}
		
	}
	if(k>1){
		int t=s[n-k+2]-s[n-k+1];
		if(t*(n-k+1)<s[n-k+1]){
			cout<<"No\n";RE;
		}
	}
	cout<<"Yes\n";
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