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
V<P<int,int> > v[100005];
int n,x[100005],y[100005],ans[100005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	if(n==2){
		cout<<"0\n";RE 0;
	}
	if(n==3){
		cout<<"0\n1\n";RE 0;
	}
	rep(i,1,n){
		cin>>x[i]>>y[i];
		v[x[i]].PB(MP(y[i],i));
		v[y[i]].PB(MP(x[i],i));
	}
	FILL(ans,-1);
	bool f=0;
	FOR(i,1,n){
		if(v[i].size()>2){
			ans[v[i][0].S]=0;
			ans[v[i][1].S]=1;
			ans[v[i][2].S]=2;
			f=1;break;
		}
	}
	if(!f){
		rep(i,1,n)cout<<i-1<<'\n';RE 0;
	}
	int t=2;
	rep(i,1,n){
		if(ans[i]==-1)ans[i]=++t;
	}
	rep(i,1,n)cout<<ans[i]<<'\n';
	RE 0;
}