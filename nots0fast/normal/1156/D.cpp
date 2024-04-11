#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp(a) setprecision(a)<<fixed
#define ss second
#define fori(v) for(ll i=0; i<v; i++)
#define forj(v) for(ll j=0; j<v; j++)
#define fork(v) for(ll k=0; k<v; k++)
#define forl(v) for(ll l=0; l<v; l++)
#define fort(v) for(ll t=0; t<v; t++)
#define forz(v) for(ll z=0; z<v; z++)
#define forx(v) for(ll x=0; x<v; x++)
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long 
#define double long double
#define MAX 200100
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 998244353;

ll ans = 0;
ll dp[MAX][4]; // 0 , 1 ,  01  , 10 
vector<pair<int,int> > g[MAX];


void dfs(int hd,int pr){
	fori(g[hd].size()){
		int hr = g[hd][i].ff, cs = g[hd][i].ss;
		if(hr == pr)
			continue;
		dfs(hr, hd);
		if(!cs){
			dp[hr][2] = 0;
			dp[hr][3] += dp[hr][1];
			dp[hr][1] = 0;
			dp[hr][0] ++;
		}
		else{
			dp[hr][3] = 0;
			dp[hr][2] += dp[hr][0];
			dp[hr][0] = 0;
			dp[hr][1] ++;
		}
	//	cout<<"we processed pair "<<hd+1<<" "<<hr+1<<endl;
	//	cout<<"before answer: "<<ans<<endl;
		ans += dp[hr][0]*dp[hd][0] + dp[hr][1]*dp[hd][1] + (dp[hr][0] + dp[hr][1]) * (dp[hd][0] + dp[hd][1]);
	//	cout<<"in between "<<ans<<endl;
		ans+= 
		(dp[hr][3] * dp[hd][0] + dp[hd][3] * dp[hr][0]) + 
		(dp[hr][2] * dp[hd][1] + dp[hr][1] * dp[hd][2]);
	//	cout<<"after answer: "<<ans<<endl;
		forj(4)
			dp[hd][j] += dp[hr][j];
	}
//	cout<<"we processed the node "<<hd+1<<endl;
//	cout<<"before ans: "<<ans<<endl;
	forj(2)
		ans+=2*dp[hd][j], ans+=dp[hd][j+2];
//	cout<<"after answer: "<<ans<<endl;
}

void deal(){
	int n;
	cin>>n;
	fori(n-1){
		int x,y,c;
		cin>>x>>y>>c;
		--x,--y;
		g[x].pb(mp(y,c));
		g[y].pb(mp(x,c));
	}
	dfs(0, -1);
	cout<<ans;
}



int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}

/* 
10
1 2 0
1 3 1
2 4 0 
2 5 1
3 6 1
3 7 0
7 8 1
7 9 1
8 10 0



4
1 2 1
1 3 1
3 4 0
*/