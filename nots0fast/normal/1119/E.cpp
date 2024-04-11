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
#define MAX 1000100
#define pb(a) push_back(a)
#define M 1000
#define N 100100
#define MAXN 1000001
typedef long double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10,13);
ll modulo = pow(10,9) + 7;
void deal(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	ll n;
	cin>>n;
	ll ql = 0;
	ll s = 0;
	fori(n){
		ll ed;
		cin>>ed;
		while(ql && ed>1){
			--ql;
			ed-=2;
			++s;
		}
		s+=ed/3;
		ed%=3;
		ql += ed;
	}
	cout<<s;
}
int main(){
    deal();
}