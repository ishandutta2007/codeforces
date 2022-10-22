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
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
P<int,int> p[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int r,n; 
	cin>>n;
	FOR(i,1,n)cin>>p[i].F>>p[i].S;
	sort(p+1,p+n+1);
	r=0;
	int ans=0;
	FOR(i,1,n){
		ans+=(r>p[i].S);
		gmax(r,p[i].S);
	}
	cout<<ans;
	RE 0;
}