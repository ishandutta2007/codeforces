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
bool f[100005];
string c;
void solve(){
	int n,x;
	cin>>c>>x;
	n=c.size();
	FOR(i,1,n)f[i]=0;
	FOR(i,1,n){
		int l=i-x,r=i+x;
		if(c[i-1]=='1')continue;
		if(l>0)f[l]=1;
		if(r<=n)f[r]=1;
	}
	FOR(i,1,n){
		int l=i-x,r=i+x;
		if(c[i-1]=='0')continue;
		if((l<=0||f[l])&&(r>n||f[r])){
			cout<<"-1\n";RE ;
		}
	}
	FOR(i,1,n){
		if(f[i]){
			cout<<0;
		}else cout<<1;
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