#pragma GCC optimize("Ofast")
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
using namespace std;
bool f[300005][2]; 
string s;
void solve(){
	int n,k;
	cin>>n>>k>>s;
	rep(i,0,n)f[i][0]=f[i][1]=0;
	rep(i,0,n){
		if(s[i]=='0'){
			f[i%k][0]=1;
		}else if(s[i]=='1')f[i%k][1]=1;
	}
	int cnt=0,t=0;
	rep(i,0,k){
		if(f[i][0]&&f[i][1]){
			cout<<"NO\n";RE;
		}
		if(f[i][0])cnt++;else if(f[i][1])cnt--;else t++;
	}
	if(abs(cnt)<=t){
		cout<<"YES\n";
	}else cout<<"NO\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}