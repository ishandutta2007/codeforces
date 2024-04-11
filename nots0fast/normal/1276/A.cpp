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
#define MAX (int)(pow(10,5) + 10)


bool eq(string& a, string& check, ll ind){
	for(ll i = ind; i < ind + check.length(); i++){
		if(i >= a.length()){
			return 0;
		}
		if( a[i] != check[i-ind] ){
			return 0;
		}
	}
	return 1;
}

void deal(){
	ll t;
	cin>>t;
	while(t--){
		string check1 = "two", check2 = "one";
		string a;
		cin>>a;
		vector<ll> ind;
		fori(a.length()){
			if(eq(a, check1, i) || eq(a, check2, i)){
				if(i+3 >= (ll)a.length() || a[i+3] != a[i+2]){
					ind.pb(i+2+1);
					a[i+2] = 'z';
				}
				else{
					ind.pb(i+1+1);
					a[i+1] = 'z';
				}
			}
		}
		cout<<ind.size()<<'\n';
		for(auto el : ind){
			cout<<el<<' ';
		}
		cout<<'\n';
	}
}
 
 
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}