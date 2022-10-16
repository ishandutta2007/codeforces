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
const ll inf =  pow(10,9);
ll modulo = 163577857;
#define MAX 1010
#define MAX2 30

bool fx[MAX];
ll arr[MAX];

void deal(){
	ll n, m;
	cin>>n>>m;
	fori(n)
		arr[i] = -1;
	vector<pair<ll,ll> > all[2];
	fori(m){
		ll ty, l , r;
		cin>>ty>>l>>r;
		ty = !ty;
		--l , -- r;
		all[ty].pb(mp(l,r));
	}
	sort(all[0].begin(), all[0].end());
	ll st = 0; 
	ll nd = -1;
	fori(all[0].size()){
		if(all[0][i].ff > nd){
			ll num = n - st;
			for(st; st<=nd; ++st)
				arr[st] = num;
			st = all[0][i].ff;
		}
		nd = max(nd, all[0][i].ss);
	}
	{
		ll num = n - st;
		for(st; st<=nd; ++st)
			arr[st] = num;
	}
	fori(n)
		if(arr[i] == -1)
			arr[i] =  n - i;
//	fori(n)
//		cout<<arr[i]<<' ';
	fori(all[1].size()){
		bool k = 0;
		for(ll l = all[1][i].ff+1; l <= all[1][i].ss; ++l)
			k|=(arr[l]<arr[l-1]);
		if(!k){
			cout<<"NO";
			return;
		}
	}
	cout<<"YES\n";
	fori(n)
		cout<<arr[i]<<' ';
}	


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}