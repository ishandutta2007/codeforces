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
typedef double ld;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ld> vd;
typedef vector<vd> vvd;
typedef pair<ll, ll> pii;
typedef vector<pii> vpii;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10,18);
ll modulo = pow(10,9) + 7;
#define MAX (int)(pow(10,6) + 10)

bool pr[MAX];

void sieve(){
	for(ll j = 2; j<MAX; j++){
		pr[j] = 1;
	}
	for(ll i = 2; i<MAX; i++){
		if(pr[i]){
			for(ll j = 2*i; j<MAX; j+=i){
				pr[j] = 0;
			}
		}
	}
}

ll lcm(ll a, ll b){
	return a*b / __gcd(a,b);
}


void deal(){
	sieve();
	ll r, c;
	cin>>r>>c;
	if(r == 1 && c == 1){
		cout<<0;
		return;
	}
	vector<ll> one, two;
	for(ll i = 1; i<=r+c; i++){
		if(r < c){
			if(i > r){
				two.pb(i);
			}
			else{
				one.pb(i);
			}
		}
		else{
			if(i > c){
				one.pb(i);
			}
			else{
				two.pb(i);
			}
		}
	}
	vector<ll> prime;
	for(ll i = 2 ; prime.size() < r + c; i++){
		if(pr[i]){
			prime.pb(i);
		}
	}
	for(ll i = 0; i<r; i++){
		for(ll j = 0; j<c; j++){
		//	cout<<one[i]<<' '<<two[j]<<endl;
			ll num = one[i]*two[j];
			while( num % (one[i] * one[i] ) == 0 &&  num % (one[i] * two[j]) == 0 && one[i] != 1){
				num /= one[i];
			}
			while( num % (two[j] * two[j]) == 0 && num% (one[i] * two[j] ) == 0 && two[j] != 1){
				num /= two[j];
			}
			cout<< num<<' ';
		}	
		cout<<'\n';
	}
}
 
 
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}