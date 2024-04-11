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
#define ll long long // TODO
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
#define MAX (int)(2*pow(10,2) + 10)


ifstream in;
ofstream out;
// #define cin in
// #define cout out



void deal(){
	ll n;
	cin>>n;
	vector<ll> all(n);
	ll last = 0;
	ll s = 0;
	fori(n){
		cin>>all[i];
		ll last_oddity = (last%2);
		ll cur_oddity = (all[i]%2);
		if(last>all[i]){
			if(last_oddity == cur_oddity){
				last = all[i];
			}
			else{
				last = all[i]-1;
			}
		}
		s+=(last+1)/2;
		s+=(all[i]-last)/2;
		if(last_oddity == cur_oddity){
			if(last!=0){
				--last;
			}
		}
		else{
			++last;
		}
		
	}
	cout<<s;
}

 
 
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}