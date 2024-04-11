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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
void solve(){
	int n,m,ct[65]={},rt[65]={};
	char c;
	bool c1,c2;
	c1=c2=1;
	int ans=4;
	cin>>n>>m;
	FOR(i,1,n){
		FOR(j,1,m){
			cin>>c;
			if(c=='A')c1=0;else {
				c2=0;continue;
			}
			ct[i]++;
			rt[j]++;
			if(i==1||j==1||i==n||j==m)gmin(ans,3);
			if((i==1||i==n)&&(j==1||j==m))gmin(ans,2);
		}
	}
	if(c2){
		cout<<"0\n";RE;
	}
	if(c1){
		cout<<"MORTAL\n";RE;
	}
	FOR(i,1,n){
		if(ct[i]==m){
			if(i==1||i==n)gmin(ans,1);else gmin(ans,2);
		}
	}
	FOR(i,1,m){
		if(rt[i]==n){
			if(i==1||i==m)gmin(ans,1);else gmin(ans,2);
		}
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}