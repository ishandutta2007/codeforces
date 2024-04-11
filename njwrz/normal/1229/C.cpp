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
V<int> in[100005];
int out[100005]; 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x,y,n,m;
	cin>>n>>m;
	FOR(i,1,m){
		cin>>x>>y;
		if(x>y)swap(x,y);
		in[x].PB(y);
		out[y]++;
	}
	int ans=0;
	FOR(i,1,n)ans=ans+in[i].size()*out[i];
	int q;
	cin>>q;
	cout<<ans<<'\n';
	FOR(i,1,q){
		cin>>x;
		ans=ans-in[x].size()*out[x];
		for(auto u:in[x]){
			ans=ans-in[u].size()*out[u];
			out[u]--;
			in[u].PB(x);
			ans=ans+in[u].size()*out[u];
		}
		out[x]+=in[x].size();in[x].clear();
		cout<<ans<<'\n';
	}
	RE 0;
}