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
int n,a[55],k;
void solve(){
	cin>>n>>k;
	FOR(i,1,n)cin>>a[i];
	if(k>1){
		FOR(i,1,n){
			if(a[i]){
				cout<<"YES\n";RE;
			}
		}
		cout<<"NO\n";
	}else{
		FOR(i,1,n){
			if(!a[i]){
				cout<<"NO\n";RE;
			}
		}
		cout<<"YES\n";
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