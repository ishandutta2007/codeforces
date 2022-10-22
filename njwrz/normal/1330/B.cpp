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
int a[200005];
bool fl[200005],fr[200005],vis[200005];
int n;
void solve(){
	cin>>n;
	FOR(i,1,n)cin>>a[i],fl[i]=fr[i]=vis[i]=0;
	V<P<int,int> > ans;
	int last=0;
	FOR(i,1,n){
		if(vis[a[i]])break;
		gmax(last,a[i]);
		if(last==i)fl[i]=1;
		vis[a[i]]=1;
	}
	FOR(i,1,n)vis[i]=0;
	last=0;
	for(int i=n;i>=1;i--){
		if(vis[a[i]])break;
		gmax(last,a[i]);
		if(last==n-i+1)fr[i]=1;
		vis[a[i]]=1;
	}
	rep(i,1,n){
		if(fl[i]&&fr[i+1]){
			ans.PB(MP(i,n-i));
		}
	}
	cout<<ans.size()<<'\n';
	for(auto u:ans)cout<<u.F<<' '<<u.S<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}