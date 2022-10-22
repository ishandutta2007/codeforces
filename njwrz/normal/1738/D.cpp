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
int n,a[100005],ans[100005];
V<int> v[100005];
void solve(){
	cin>>n;
	FOR(i,0,n+1)v[i].clear();
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,n){
		if(a[i]>=1&&a[i]<=n){
			v[a[i]].PB(i);
		}
	}
	int k=0;
	FOR(i,1,n)if(a[i]>i){
		gmax(k,i);
	}
	cout<<k<<'\n';
	V<int> hav;
	int it=0;
	FOR(i,1,n){
		if(a[i]<=0||a[i]>n)hav.PB(i);
	}
	while(!hav.empty()){
		int t=-1;
		for(auto u:hav){
			if(!v[u].empty()){
				t=u;break;
			}
		}
		for(auto u:hav)if(u!=t)ans[++it]=u;
		if(t==-1)break;
		ans[++it]=t;
		hav.clear();
		for(auto u:v[t])hav.PB(u);
	}
	FOR(i,1,n)cout<<ans[i]<<' ';
	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}