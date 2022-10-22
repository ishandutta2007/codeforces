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
int n,a[100005];
void solve(){
	cin>>n;
	FOR(i,1,n){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n,now=1,t=1;
	V<int> ans;
	FOR(i,1,n){
		ans.PB(now);
		if(t==1){
			l++;now=r;t=2;
		}else{
			r--;now=l;t=1;
		}
	}
	reverse(ALL(ans));
	for(auto u:ans)cout<<a[u]<<' ';
	cout<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}