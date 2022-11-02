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
V<P<int,P<int,bool > > > v;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	FOR(i,0,19){
		v.PB(MP(n<<i,MP(n<<i,0)));
	}
	int now=n;
	FOR(i,1,19){
		if(now&(1<<i)){
			v.PB(MP(n<<i,MP(now,1)));
			now^=(n<<i);
		}
	}
	int x=n;
	v.PB(MP(x,MP(now,0)));
	v.PB(MP(x+now,MP(now,1)));
	int y=(x+now)^now;
	v.PB(MP(y,MP(now,0)));
	v.PB(MP(y+now,MP(now,1)));
	int z=(y+now)^now;
	v.PB(MP(x,MP(y,1)));
	v.PB(MP(y,MP(z,1)));
	FOR(i,1,40){
		v.PB(MP(1ll<<i,MP(1ll<<i,0)));
	}
	now=n;
	FOR(i,1,19){
		if(now&(1<<i)){
			v.PB(MP(1<<i,MP(now,1)));
			now^=1<<i;
		}
	}
	cout<<v.size()<<'\n';
	for(auto u:v){
		if(u.S.S){
			cout<<u.F<<" ^ "<<u.S.F<<'\n';
		}else cout<<u.F<<" + "<<u.S.F<<'\n';
	}
	RE 0;
}