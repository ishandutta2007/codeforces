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
P<int,int> p[500005];
bool cmp(P<int,int> x,P<int,int> y){
	RE MP(max(x.F,x.S),min(x.F,x.S))<MP(max(y.F,y.S),min(y.F,y.S));
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,d;
	cin>>n>>d;
	FOR(i,1,n)cin>>p[i].S>>p[i].F;
	sort(p+1,p+n+1,cmp);
	int cnt=0;
	FOR(i,1,n){
		if(p[i].S>=d){
			gmax(d,p[i].F);
			cnt++;
		}
	}
	cout<<cnt;
	RE 0;
}