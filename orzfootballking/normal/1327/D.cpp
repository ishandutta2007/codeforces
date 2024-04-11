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
bool vis[200005];int n,p[200005],c[200005];
V<int> fac[200005];
void solve(){
	cin>>n;
	FOR(i,1,n)cin>>p[i];
	FOR(i,1,n)cin>>c[i];
	fill(vis+1,vis+n+1,0);
	int t,s,ans=n;bool f;
	V<int> v;
	FOR(i,1,n){
		t=i;
		while(!vis[t]){
			v.PB(t);
			vis[t]=1;
			t=p[t];
		}
		if(!v.size())continue;
		s=v.size();
		for(auto u:fac[s]){
			rep(start,0,u){
				f=1;
				for(int j=start+u;j<s;j+=u){
					if(c[v[j]]!=c[v[start]]){
						f=0;break;
					}
				}
				if(f){
					gmin(ans,u);
				}
			}
		}
		v.clear();
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	FOR(i,1,200000){
		for(int j=i;j<=200000;j+=i)fac[j].PB(i);
	}
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}