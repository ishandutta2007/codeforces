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
const ll inf = pow(10,18)+10;
ll modulo = 998244353;


bool vis[MAX];
ll arr[MAX];

void deal(){
	ll n;
	cin>>n;
	fori(n)
		cin>>arr[i], --arr[i];
	ll sy = 0;
	ll st = 0;
	ll mx = -1;
	while(st<n){
		if(st > mx )
			++sy;
		mx = max(mx,arr[st]);
		++st;
	}
	cout<<sy;
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