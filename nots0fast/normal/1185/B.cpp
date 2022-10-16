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
const ll inf =  2*pow(10,9);
ll modulo = pow(10,9) + 7;
#define MAX (int)(pow(10,6) + 10)

vector<pair<char, ll> > encode(string& a){
	ll n = a.length();
	ll st = 0;
	vector<pair<char, ll> > all;
	while(st<n){
		ll nd = st+1;
		while(nd < n && a[nd] == a[st])
			++nd;
		all.pb(mp(a[st], nd-st));
		st = nd;
	}
	return all;
}

string all[2];
vector<pair<char,ll > > enc[2];
void deal(){	 // 1 printed one , 0 - meant message
	ll n;
	cin>>n;
	fori(n){
		forj(2)
			cin>>all[j], enc[j] = encode(all[j]);
		if(enc[0].size() != enc[1].size())
			cout<<"NO\n";
		else{
			bool fucked = 0;
			fori(enc[0].size())
				if(enc[0][i].ff != enc[1][i].ff || enc[0][i].ss > enc[1][i].ss)
					fucked = 1;
			if(fucked)
				cout<<"NO\n";
			else
				cout<<"YES\n";
		}
	}
}

int main()  
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}