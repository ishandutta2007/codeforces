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
int n;
V<int> v[21];
void solve(){
	cin>>n;
	FOR(i,1,n)cin>>c[i];
	FOR(i,1,n)cin>>s[i];
	rep(i,0,21)v[i].clear();
	FOR(i,1,n){
		if(c[i]>s[i]){
			cout<<-1<<'\n';RE;
		}
	}
	FOR(i,1,n){
		v[c[i]-'a'].PB(i);
	}
	int ans=0;
	rep(i,0,20){
		bool f=1;
		for(auto u:v[i]){
			if(s[u]!='a'+i){
				f=0;break;
			}
		}
		if(f){
			continue;
		}
		int mini=20;
		for(auto u:v[i]){
			if(s[u]!='a'+i)gmin(mini,s[u]-'a');
		}
		for(auto u:v[i])if(s[u]!='a'+i)v[mini].PB(u);
		ans++;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	RE 0;
}