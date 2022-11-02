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
int gcd(int x,int y){
	if(!y)RE x;
	RE gcd(y,x%y);
}
void solve(){
	int m,d,w;
	cin>>m>>d>>w;
	int t=d-1;
	int f=gcd(t,w);
	w/=f;
	int mi=min(m,d);
	mi--;
	t=mi%w;
	int p=mi/w;
	int ans=0;
	ans=ans+p*(p+1)*(t+1);
	ans=ans+p*(p-1)*(w-t-1);
	cout<<ans/2<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve();
	RE 0;
}