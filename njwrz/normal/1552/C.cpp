#pragma GCC optimize(2)
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
P<int,int> p[105];
bool f[205];
void solve(){
	int n,k;
	cin>>n>>k;
	FOR(i,0,2*n)f[i]=0;
	FOR(i,1,k){
		cin>>p[i].F>>p[i].S;f[p[i].F]=1;f[p[i].S]=1;
		if(p[i].F>p[i].S)swap(p[i].F,p[i].S);
	}
	V<int> v;
	FOR(i,1,2*n)if(!f[i])v.PB(i);
	rep(i,0,v.size()/2){
		p[++k]=MP(v[i],v[i+v.size()/2]);
	}
	int ans=0;
	sort(p+1,p+n+1);
	FOR(i,1,n){
		FOR(j,i+1,n){
			if(p[j].F<p[i].S&&p[i].S<p[j].S)ans++;
		}
	}
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