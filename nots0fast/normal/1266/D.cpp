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

bool by_second(pair<ll,ll>& a, pair<ll,ll>& b){
	return a.ss < b.ss;
}

void deal(){
	vector<pair<ll,ll >  > owe, owed;
	ll n , m;
	cin>>n>>m;
	vector<ll> all(n, 0);
	fori(m){
		ll a , b, d;
		cin>>a>>b>>d;
		--a, --b;
		all[a] += d;
		all[b] -= d;
	}
	fori(n){
		if(all[i] > 0){
			owe.pb(mp(i,all[i]));
		}
		else{
			owed.pb(mp(i, -all[i]));
		}
	}
	sort(owe.begin(), owe.end(), by_second);
	sort(owed.begin(), owed.end(), by_second);
	vector<vector<ll> > edg;
	while(owe.size() && owed.size()){
		ll sz1 = owe.size();
		ll sz2 = owed.size();
		ll mn = min(owe[sz1-1].ss, owed[sz2-1].ss);
		edg.pb(vector<ll>({owe[sz1-1].ff, owed[sz2-1].ff, mn}));
		owe[sz1-1].ss -= mn, owed[sz2-1].ss -= mn;
		if(!owe[sz1-1].ss){
			owe.erase(owe.end() - 1);
		}
		if(!owed[sz2-1].ss){
			owed.erase(owed.end() - 1);
		}
	}
	cout<<edg.size()<<'\n';
	for(auto& el : edg){
		cout<<el[0]+1<<' '<<el[1]+1<<' '<<el[2]<<'\n';
	}
}
 
 
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}