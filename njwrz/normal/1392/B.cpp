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
int t[200005];
void solve(){
	int n,k;
	cin>>n>>k;
	FOR(i,1,n)cin>>t[i];
	int maxi=1,mini=1;
	FOR(i,1,n){
		if(t[i]>t[maxi])maxi=i;
		if(t[i]<t[mini])mini=i;
	}
	if(k&1){
		FOR(i,1,n){
			cout<<t[maxi]-t[i]<<' ';
		}
		cout<<'\n';
	}else{
		FOR(i,1,n){
			cout<<t[maxi]-t[mini]-(t[maxi]-t[i])<<' ';
		}
		cout<<'\n';
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}