#pragma GCC optimize("Ofast,unroll-loops")
#include<bits/stdc++.h>
#define int long long
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
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	if(n&1){
		cout<<"NO";RE 0;
	}
	FOR(i,1,n)cin>>p[i].F>>p[i].S;
	int x,y; 
	x=p[1].F+p[1+(n>>1)].F;y=p[1].S+p[1+(n>>1)].S;
	FOR(i,2,(n>>1)){
		if(x!=p[i].F+p[i+(n>>1)].F||y!=p[i].S+p[i+(n>>1)].S){
			cout<<"NO";RE 0;
		}
	}
	cout<<"YES";
	RE 0;
}