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
#define MAX (int)(pow(10,6)+10)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 1000000007;

ll Mx[MAX][21];

void deal(){
	ll n , m;
	cin>>n>>m;
	fori(n){
		ll l , r;
		cin>>l>>r;
		Mx[l][0] = max(Mx[l][0], r);
	}
	for(ll i= 1; i<MAX; i++)
		Mx[i][0] = max(Mx[i][0], Mx[i-1][0]);
	for(ll j = 1; j<21; j++)
		fori(MAX)
			Mx[i][j] = Mx[Mx[i][j-1]][j-1];
	fori(m){
		ll x, y;
		cin>>x>>y;
		ll sv = x;
		ll num = 0;
		for(ll j = 20; j>-1; j--)
			if( Mx[x][j]<y && Mx[x][j]!=-1)
				x = Mx[x][j], num|=(1<<j);
		ll num1 = num + 1;
		x = sv;
		for(ll j=20; j>-1; j--)
			if((1<<j)&num1)
				x = Mx[x][j];
		if(x<y)
			num1 = -1;
		cout<<num1<<'\n';
	}
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