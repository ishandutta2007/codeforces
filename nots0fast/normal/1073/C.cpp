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
#define ld long double
#define pb(a) push_back(a)
#define MAX (int)(pow(10,6) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 1000000007;

string dir = "UDLR";
ll dx[4] = { 0, 0,-1, 1};
ll dy[4] = { 1,-1, 0, 0};
ll ini[MAX][2];
ll fin[MAX][2];


void deal(){
	ll n,x ,y;
	string a;
	cin>>n>>a>>x>>y;
	if(x<0){
		x = -x;
		fori(n){
			ll which = dir.find(a[i]);
			if(which > 1)
				a[i] = dir[which^1];
		}
	}
	
	if(y<0){
		y = -y;
		fori(n){
			ll which = dir.find(a[i]);
			if(which < 2)
				a[i] = dir[which^1];
		}
	}
	
	if( ( ((x+y)&1) != (n&1) ) || (x+y) > n ){
		cout<<-1;
		return;
	}
	
	
	ll lef = 0, rig = n;
	fin[n][0] = x, fin[n][1] = y;
	ini[0][0] = 0, ini[0][1] = 0;
	fori(n){
		ll which = dir.find(a[i]);
		ini[i+1][0] = ini[i][0] + dx[which];
		ini[i+1][1] = ini[i][1] + dy[which];
	}
	for(ll i=n-1; i>-1; i--){
		ll which = dir.find(a[i]);
		which ^= 1;
		fin[i][0] = fin[i+1][0] + dx[which];
		fin[i][1] = fin[i+1][1] + dy[which];
	}
	
	while(lef<rig){
		ll mid = (lef+rig)>>1;
		bool yea = 0;
		for(ll i = 0; i<=n-mid; i++){
			ll diff = fabs(ini[i][0] - fin[i+mid][0]) + fabs(ini[i][1] - fin[i+mid][1]);
			if( (diff&1) == (mid&1) && mid>=diff)
				yea = 1;
		}
		if(yea)
			rig = mid;
		else	
			lef = mid+1;
	}
	cout<<lef;
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}





// 4 1 1000 10
// 1 2 1
// ? 1 2
// ? 2 1
// + 2 4 1
// ? 1 4
// ? 4 1
// ? 4 2
// + 3 4 1
// ? 1 3
// ? 3 1