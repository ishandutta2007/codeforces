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
#define MAX 100100

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n , m;
		cin>>n>>m;
		vector<vector<char> > all( n);
		fori(n){
			all[i].resize(m);
			forj(m)
				cin>>all[i][j];
		}
		ll Mx = 0;
		vector<ll> sms(m, 0);
		forj(m){
			ll s = 0;
			fori(n)
				s+=(all[i][j] == '*');
			Mx = max(Mx, s);
			sms[j] = s;
		}
		ll Mn = n*m;
		fori(n){
			ll s = 0;
			bool ok = 1;
			forj(m){
				if(all[i][j] == '*')
					++s;
				else if(sms[j] == Mx)
					ok = 0;
			}
			Mn = min(Mn, n + m - 1 - s - Mx + ok);
		}
		cout<<Mn<<'\n';
	}
}
int main(){
//	cin.tie(0);
//	ios_base::sync_with_stdio(0);
	deal();
}