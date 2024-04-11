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
#define MAX 1001000
#define pb(a) push_back(a)
#define M 1001000
#define N 100100
#define MAXN 700
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
int col[MAX];
void deal(){
	int n;
	cin>>n;
	fori(n){
		cin>>col[i];
	}
	ll mx;
	for(int i=n-1; i>-1; i--){
		if(col[i] != col[0]){
			mx = i;
			break;
		}
	}
	fori(n){
		if(col[i] != col[n-1]){
			mx = max(mx,n-1-i);
			break;
		}
	}
	cout<<mx;
}
int main(){
    deal();
}