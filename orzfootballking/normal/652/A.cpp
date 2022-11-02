/*

DP





ll int
 dp 










*/
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
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int h1,h2,a,b;
	cin>>h1>>h2>>a>>b;
	h1+=8*a;
	FOR(i,0,1000000){
		if(h1>=h2){
			cout<<i;RE 0;
		}
		h1-=b*12;
		h1+=a*12;
	}
	cout<<-1;
	RE 0;
}