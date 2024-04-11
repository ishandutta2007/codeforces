/*

DP





ll int
 dp 










*/
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
int a[100005],b[100005],c[100005],ans[100005],tmp[100005];
V<int> v[100005];
void solve(){
	int n,m;
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i],v[i].clear(),tmp[i]=0;
	FOR(i,1,n){
		cin>>b[i];
		if(a[i]!=b[i]){
			v[b[i]].PB(i);
		}else tmp[a[i]]=i;
	}
	FOR(i,1,m)cin>>c[i];
	int lst=0;
	for(int i=m;i>=1;i--){
		if(v[c[i]].empty()){
			if(lst){
				ans[i]=lst;
			}else if(tmp[c[i]]){
				ans[i]=tmp[c[i]];
				lst=ans[i];
			}else{
				cout<<"NO\n";RE;
			}
		}else{
			ans[i]=v[c[i]].back();
			lst=ans[i];
			v[c[i]].pop_back();
		}
	}
	FOR(i,1,n){
		if(!v[i].empty()){
			cout<<"NO\n";RE;
		}
	}
	cout<<"YES\n";
	FOR(i,1,m){
		cout<<ans[i]<<' ';
	}
	cout<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}