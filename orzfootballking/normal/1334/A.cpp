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
P<int,int> p[105];
void solve(){
	int n,x,y;
	cin>>n;
	int lost=0;
	bool f=1;
	FOR(i,1,n)cin>>p[i].F>>p[i].S;
	FOR(i,1,n){
		if(p[i].F<p[i-1].F||p[i].S<p[i-1].S)f=0;
		x=p[i].F;y=p[i].S;
		if(y+lost>x)f=0;
		gmax(lost,x-y);
	}
	if(f){
		cout<<"YES\n";
	}else cout<<"NO\n";
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--)solve(); 
	RE 0;
}