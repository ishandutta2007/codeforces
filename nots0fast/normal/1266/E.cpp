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
 
map<ll,ll> all[MAX];
 
void deal(){
	ll ans = 0;
	ll n;
	cin>>n;
	vector<ll> arr(n);
	fori(n){
		cin>>arr[i];
		ans += arr[i];
	}
	vector<ll> cum(n, 0);
	ll q;
	cin>>q;
	fori(q){
		ll sj, tj, uj;
		cin>>sj>>tj>>uj;
		--sj, --uj;
		if(all[sj].find(tj)!=all[sj].end()){
			ll which = all[sj][tj];
			--cum[which];
			if(cum[which] < arr[which]){
				++ans;
			}
			all[sj].erase(tj);
		}
		if(uj != -1){
			all[sj][tj] = uj;
			++cum[uj];
			if(cum[uj] <= arr[uj]){
				--ans;
			}
		}
		cout<<ans<<'\n';
	}
}
 
 
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}