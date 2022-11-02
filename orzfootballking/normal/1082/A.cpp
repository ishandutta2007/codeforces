#pragma GCC optimize("Ofast")
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
void solve(){
	int n,l,r,d;
	cin>>n>>l>>r>>d;
	int len=abs(r-l);
	if(len%d==0){
		cout<<len/d<<'\n';RE;
	}
	int ans=2147483647;
	if((r-1)%d==0){
		ans=min(ans,(l-1)/d+1+(r-1)/d);
	}
	if((n-r)%d==0){
		ans=min(ans,(n-l)/d+1+(n-r)/d);
	}
	if(ans!=2147483647)cout<<ans<<'\n';else cout<<"-1\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}