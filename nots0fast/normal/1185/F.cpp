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
const ll inf =  pow(10,18);
ll modulo = pow(10,9) + 7;
#define MAX (int)((1<<10) + 10)

ll ppl[MAX];
ll actual[MAX];
ll pizza[MAX];
ll indice[MAX];
vector<pair<ll,ll> > all;

void deal(){	 // 1 printed one , 0 - meant message
	ll n, m;
	cin>>n>>m;
	fori(n){
		ll nm;
		cin>>nm;
		ll bt = 0;
		forj(nm){
			ll ed;
			cin>>ed;
			--ed;
			bt^=(1<<ed);
		}
		ppl[bt]++;
	}
	fori(MAX)
		pizza[i] = inf;
	fori(1<<10)
		forj(1<<10)
			if((i&j) == j)
				actual[i] += ppl[j];
	fori(m){
		ll pr;
		cin>>pr;
		all.pb(mp(pr,i));
		ll nm ;
		cin>>nm;
		ll bt = 0;
		forj(nm){
			ll ed;
			cin>>ed;
			--ed;
			bt^=(1<<ed);
		}
		pizza[bt] = min(pizza[bt], pr);
		if(pizza[bt] == pr)
			indice[bt] = i;
	}
	sort(all.begin(), all.end());
	ll sum = 0;
	ll mn = inf;
	ll ans[2]  = { };
	fori(1<<10){
		if(pizza[i] == inf)
			continue;
		if(actual[i] > sum || (actual[i] == sum && pizza[i] < mn) )
			sum = actual[i], mn = pizza[i], ans[0] = indice[i];
	}
	if(ans[0] == all[0].ss)
		mn += all[1].ff, ans[1] = all[1].ss;
	else
		mn += all[0].ff, ans[1] = all[0].ss;
	fori(1<<10)
		forj(1<<10){
			if(pizza[i] == inf || pizza[j] == inf || i == j)
				continue;
			pair<ll,ll> cur({pizza[i]+pizza[j], actual[i|j]});
			if(cur.ss > sum || (cur.ss == sum && cur.ff < mn)){
				mn = cur.ff, sum = cur.ss, ans[0] = indice[i], ans[1] = indice[j];
			}
		}
	cout<<ans[0]+1<<' '<<ans[1]+1;
}

int main()  
{
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}