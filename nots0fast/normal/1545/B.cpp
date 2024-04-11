#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision
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
#define mt make_tuple
#define MAX (int)(pow(10,5) + 10)
// #define cout out
// #define cin in
ll inf = pow(10, 18) + 100;
ll INF = pow(10, 9);
ll modulo = 998244353;
double eps = 1e-10;


ll pow_mod(ll a, ll b){
	a = a%modulo;
	if(!a){
		return 0;
	}
	ll has = 1%modulo;
	for(ll i = 62; i>-1; i--){
		has*=has;
		has%=modulo;
		if(((ll)1<<i)&b)
			has*=a, has%=modulo;
	}
	return has;
}

ll fkt[MAX];
ll inv[MAX];

void pre(){
	fkt[0] = inv[0] = 1;
	for(ll i =1; i<MAX; i++){
		fkt[i] = fkt[i-1] * i % modulo;
		inv[i] = pow_mod(fkt[i], modulo-2);
	}
}

ll choose(ll i, ll j){
	return fkt[i] * inv[j] % modulo * inv[i-j] % modulo;
}

void deal(){
	pre();
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		string a;
		cin>>a;
		ll st = 0;
		ll s0 = 0, s1 = 0;
		while(st < n){
			if(a[st] == '0'){
				++st;
				++s0;
			}
			else{
				ll nd = st;
				while(a[nd] == '1' && nd < n){
					++nd;
				}
				s1 += (nd-st)/2;
				st = nd;
			}
		}
		cout<<choose(s0+s1, s1)<<'\n';
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	deal();
}