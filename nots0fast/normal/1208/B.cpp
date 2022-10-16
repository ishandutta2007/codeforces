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
#define ll long long
#define ld long double
#define MAX (int)(pow(10,6) + 10)
#define pb(a) push_back(a)
// #define cout out
// #define cin in
ll inf = pow(10,9);
ll INF = inf;
ll modulo = inf;
double eps = 1e-10;
ifstream in;
ofstream out;


void fx(map<ll,ll>& all){
	ll index=0;
	for(auto& pr: all)
		pr.ss = index, ++index;
}

void deal(){
	ll n;
	cin>>n;
	vector<ll> arr(n);
	map<ll,ll> all;
	ll st = -1;
	fori(n){
		ll ed;
		cin>>ed;
		all[ed] = 1;
		arr[i] = ed;
	}
	fx(all);
	vector<ll> how(n);
	
	fori(n)
		arr[i] = all[arr[i]], how[arr[i]]++;
	ll mn = n;
	forj(n){
		ll lo = j, hi = n;
		while(lo<hi){
			ll mid = (lo+hi)/2;
			for(ll i = j; i<mid; i++)
				how[arr[i]]--;
			bool gg = 1;
			fori(n)
				if(how[i] > 1)
					gg = 0;
			for(ll i = j; i<mid; i++)
				how[arr[i]]++;
			if(gg)
				hi = mid;
			else
				lo = mid+1;
		}
		for(ll i = j; i<lo; i++)
			how[arr[i]]--;
		bool gg = 1;
		fori(n)
			if(how[i] > 1)
				gg = 0;
		for(ll i = j; i<lo; i++)
			how[arr[i]]++;
		if(gg)
		mn = min (mn, lo - j);
	}
	cout<<mn;
}
 
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}



/*
1000000 1000000
1000000000000000000
*/