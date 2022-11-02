/*

DP





ll int
 dp 










*/
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
char c[105];
string s;
void solve(){
	cin>>s;
	int n=s.size();
	FOR(i,1,n)c[i]=s[i-1];
	if(n&1){
		cout<<"NO\n";RE ;
	}
	int cnt=0;
	FOR(i,1,n){
		if(c[i]=='('||c[i]=='?'){
			cnt++;
		}else cnt--;
		if(cnt<0){
			cout<<"NO\n";RE ;
		}
	}
	cnt=0;
	for(int i=n;i>=1;i--){
		if(c[i]==')'||c[i]=='?'){
			cnt++;
		}else cnt--;
		if(cnt<0){
			cout<<"NO\n";RE;
		}
	}
	cout<<"YES\n";
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}