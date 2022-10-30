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
char c[100005],s[100005];
void solve(){
	int n;
	cin>>n;
	FOR(i,1,n){
		cin>>c[i];
	}
	FOR(i,1,n)cin>>s[i];
	V<int> ans;
	FOR(i,1,n){
		if(c[i]!=c[i-1]){
			if(i>1)ans.PB(i-1);
		}
	}
	int now=c[n];
	for(int i=n;i>=1;i--){
		if(now!=s[i]){
			ans.PB(i);
			now='0'+((now-'0')^1);
		}
	}
	cout<<ans.size()<<' ';
	for(auto u:ans)cout<<u<<' ';
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}