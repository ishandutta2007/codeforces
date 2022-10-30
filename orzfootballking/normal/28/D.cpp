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
const int MAXN=1e5+5,MAX=1e5;
map<int,int> dp[MAXN];
int lst[MAXN],ans[MAXN];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int v,c,l,r;
	int n;
	cin>>n;
	FOR(i,1,n){
		cin>>v>>c>>l>>r;
		if(!l||dp[l].count(r+c)){
			ans[i]=ans[dp[l][r+c]]+v;
			lst[i]=dp[l][r+c];
			if(ans[dp[l+c][r]]<ans[i]){
				dp[l+c][r]=i;
			}
		}
	}
	int maxi=0;
	FOR(i,1,100000){
		if(ans[dp[i][0]]>ans[maxi]){
			maxi=dp[i][0];
		}
	}
	V<int> d;
	while(maxi){
		d.PB(maxi);
		maxi=lst[maxi];
	}
	reverse(ALL(d));
	cout<<d.size()<<'\n';
	for(auto u:d)cout<<u<<' ';
	RE 0;
}