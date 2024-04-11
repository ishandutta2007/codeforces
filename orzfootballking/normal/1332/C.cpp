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
int n,k,cnt[200005][30];
char c[200005];
void solve(){
	cin>>n>>k;
	int t;
	FOR(i,1,k)FOR(j,0,25)cnt[i][j]=0;
	FOR(i,1,n){
		cin>>c[i];
		t=i%k;
		if(!t)t=k;
		cnt[t][c[i]-'a']++;
	}
	int ans=0;
	FOR(i,1,k/2){
		t=1e9;
		FOR(j,0,25)gmin(t,n/k*2-cnt[i][j]-cnt[k+1-i][j]);
		ans+=t;
	}
	if(k&1){
		t=1e9;
		FOR(i,0,25)gmin(t,n/k-cnt[(k+1)/2][i]);
		ans+=t;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}