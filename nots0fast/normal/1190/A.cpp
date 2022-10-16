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
#define pb(a) push_back(a)
#define PI 2*acos(0)
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
const ll INF = 2*pow(10,9)+10;
const ll inf =  pow(10,18);
ll modulo = 163577857;
#define MAX 200100

ll arr[MAX];


void deal(){
	ll n , m , k;
	cin>>n>>m>>k;
	fori(m)
		cin>>arr[i], --arr[i];
	ll st = 0;
	ll sy = 0;
	while(st<m){
		ll sv = st;
		while(st<m && (arr[st]-sv)/k == (arr[sv] - sv)/k){
			
			++st;
		}
	//	cout<<"we started at "<<sv<<"ended at "<<st<<endl;
		++sy;
	}
	cout<<sy;
}

int main(){
//	cin.tie(0);
//	ios_base::sync_with_stdio(0);
	deal();
}