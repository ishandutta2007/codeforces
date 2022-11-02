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
void solve(){
	int p,f,cs,cw,s,w;
	cin>>p>>f>>cs>>cw>>s>>w;
	if(s>w){
		swap(cs,cw);
		swap(s,w);
	}
	if(p>f)swap(p,f);
	int t=p/s+f/s;
	if(t<=cs){
		cout<<t<<'\n';RE;
	}
	int maxi=0;
	FOR(i,0,cs){
		int t1=i*s,t2=(cs-i)*s;
		if(t1>p)continue;
		if(t2>f)continue;
		int t=(p-t1)/w+(f-t2)/w;
		gmin(t,cw);
		gmax(maxi,t+cs);
	}
	cout<<maxi<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}