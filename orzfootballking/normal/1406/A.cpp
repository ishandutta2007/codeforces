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
int a[105],b[105];
void solve(){
	int n;
	FILL(b,0);
	cin>>n;
	int x=0;
	FOR(i,1,n){
		cin>>x;
		b[x]++;
	}
	int ans=0;
	int now=0;
	while(b[now]){
		b[now]--;now++;
	}
	ans=now;
	now=0;
	while(b[now]){
		b[now]--;now++;
	}
	ans+=now;
	cout<<ans<<'\n';
} 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}