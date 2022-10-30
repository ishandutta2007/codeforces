#pragma GCC optimize("Ofast")
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
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
int m[1000005],mt[1000005];
int a[1000005],mod=1e9+7;
int POW(int x,int y){
	if(!y)RE 1;
	int t=POW(x,y/2);
	t=t*t%mod;
	if(y&1){
		RE t*x%mod;
	}else RE t;
}
void solve(){
	int n,p;
	cin>>n>>p;
	V<int> v;
	FOR(i,1,n)cin>>a[i],v.PB(a[i]);
	if(p==1){
		cout<<(n&1)<<'\n';RE;
	}
	FOR(i,1,n)m[a[i]]++,mt[a[i]]++;
	sort(ALL(v));
	v.erase(unique(ALL(v)),v.end());
	for(int i=v.size()-1;i>=0;i--){
		if(m[v[i]]&1){
			int last=1;
			FOR(j,1,v[i]){
				last*=p;
				if(m[v[i]-j]<last){
					last-=m[v[i]-j];
					m[v[i]-j]=0;
				}else{
					m[v[i]-j]-=last;last=0;
					break;
				}
				if(last>=1000000)break;
			}
			if(last){
				int ans=POW(p,v[i]);
				rep(j,0,i){
					ans=(ans-POW(p,v[j])*mt[v[j]]%mod+mod)%mod;
				}
				cout<<ans<<'\n';
				for(auto u:v)m[u]=mt[u]=0;
				RE;
			}
		}
	}
	for(auto u:v)m[u]=mt[u]=0;
	cout<<0<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}