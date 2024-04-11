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
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
#define lc (x<<1)
#define rc ((x<<1)|1)
#define sz(x) ((int)x.size())
using namespace std;
int val[125][125];
void solve(){
	int t,x,y;
	cin>>t>>x>>y;
	if(x+y>t){
		cout<<"NO\n";RE;
	}
	FILL(val,0);
	val[0][0]=t-x-y+1;
	P<int,int> at=MP(0,0);
	rep(t,0,x+y){
		P<int,int> to=MP(-1,-1);
		FOR(i,0,min(t,119ll)){
			int j=t-i;
			if(j>119)continue;
			if(at.F==i){
				to=at;
				if(val[i][j]&1)to.S++;else to.F++;
			}
			val[i][j+1]+=(val[i][j]+1)/2;
			val[i+1][j]+=val[i][j]/2;
		}
		if(to.F>119||to.S>119){
			cout<<"NO\n";RE;
		}
		at=to;
	}
	if(at==MP(x,y)){
		cout<<"YES\n";
	}else cout<<"NO\n";
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)solve();
	RE 0;
}