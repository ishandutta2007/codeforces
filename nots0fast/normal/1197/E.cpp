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
#define double long double
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = pow(10,9)+7  ;
#define MAX (int)(pow(10,6)+ 10)




bool J(pair<ll,ll>& a, pair<ll,ll>& b){
	return a.ss < b.ss;
}

void deal(){
	ll n;
	cin>>n;
	vector<pair<ll,ll> > inp(n+1);
	fori(n)
		cin>>inp[i].ss>>inp[i].ff;
	inp[n].ff = 0, inp[n].ss = 0;
	sort(inp.begin(), inp.end(), J);
	vector<pair<ll,ll> > add(n+1);
	vector<pair<ll,ll> > Mn(n+1); // minimum with sum at each version
	map<ll,ll> all; // sorted by (-outermost + inner) smallest to biggest, you always want to take the smallest available;
	all[0] = 1;
	Mn[0].ff = 0, Mn[0].ss = 1;
	add[0].ff = 0, add[0].ss = 1;
	ll mx = 0;
	// map is for actual simulation purposes
	for(ll i = 1; i<=n; i++){
		mx = max(mx, inp[i].ff);
		ll lo = 0, hi = i-1;
		while(lo < hi){
			ll mid = (lo+hi)/2+1;
			if(inp[mid].ss > inp[i].ff)
				hi = mid-1;
			else
				lo = mid;
		}
		add[i] = mp(Mn[lo].ff+inp[i].ff-inp[i].ss, Mn[lo].ss);
		all[add[i].ff] += add[i].ss;
		all[add[i].ff] %= modulo;
		auto it = all.begin();
		Mn[i].ff  = (*it).ff;
		Mn[i].ss  = (*it).ss;
/*		cout<<"\n\n\n !! wee att "<<i<<endl;
		cout<<"we added everyone up until "<<lo<<endl;
		cout<<" we decided we gonna add "<<add[i].ff<<" with num of ways "<<add[i].ss<<endl;
		cout<<"so the min at "<<i<<" now is going to be "<<Mn[i].ff<<" "<<Mn[i].ss<<endl;
*/	}
	ll ans = 0;
	ll mn = inf;
	fori(n+1)
		add[i].ff += inp[i].ss;
	fori(n+1)
		if(inp[i].ss > mx)
			mn = min(mn, add[i].ff);
	fori(n+1)
		if(inp[i].ss > mx && add[i].ff == mn)
			ans+=add[i].ss, ans%=modulo;
	cout<<ans;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}

/*

4 6
4 8 7 8
1 2 4
2 1 2 2
1 3 4
2 1 1 8
1 1 3
1 1 4

acacabbbbbbbacc

cccbbbaaa
*/