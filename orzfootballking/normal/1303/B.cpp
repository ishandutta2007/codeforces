#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define int long long
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
	int n,g,b;
	cin>>n>>g>>b;
	if(b<=g){
		cout<<n<<'\n';RE;
	}
	int t=(n+1)/2;
	int s=t/g+(t%g!=0)-1;
	if(n-t>s*b){
		cout<<n<<'\n';
	}
	else cout<<n+s*b-n+t<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}