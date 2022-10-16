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
#define ld long double
#define pb(a) push_back(a)
#define MAX (int)(pow(10,6) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 998244353;

ll ind[MAX];
vector<pair<ll,ll> >  all, all1, all2;

bool J(pair<ll,ll>& a, pair<ll,ll>& b){
	return a.ss < b.ss;
}

void deal(){
	ll n;
	cin>>n;
	all.resize(n);
	fori(n){
		cin>>all[i].ff>>all[i].ss;
		ind[all[i].ff]  = i;
		ind[all[i].ss] =  i;
		if(all[i].ff < all[i].ss)
			all1.pb(all[i]);
		else	
			all2.pb(all[i]);
	}
	sort(all1.begin(), all1.end(), J);
	sort(all2.begin(), all2.end(), J);
	reverse(all1.begin(), all1.end());
	if(all2.size() > all1.size())
		all1 = all2;
	cout<<all1.size()<<'\n';
	fori(all1.size())
		cout<<ind[all1[i].ss]+1<<' ';
	
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}





// 4 1 1000 10
// 1 2 1
// ? 1 2
// ? 2 1
// + 2 4 1
// ? 1 4
// ? 4 1
// ? 4 2
// + 3 4 1
// ? 1 3
// ? 3 1