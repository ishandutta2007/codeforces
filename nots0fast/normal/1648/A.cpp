/*
#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")
*/


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
#define ll long long
#define ld long double
#define pb push_back
#define mt make_tuple
// #define cout out
// #define cin in
ll inf = pow(10,18);
ll modulo = pow(10, 9);
double eps = 1e-6;
ifstream in;
ofstream out;

void add(map<ll, vector<ll> >& all, ll& ans){
	for(auto& el : all){
		sort(el.ss.begin(), el.ss.end());
		ll sum = 0;
		fori((ll)el.ss.size()){
			ans += i * el.ss[i] - sum;
			sum += el.ss[i];
		}
		
	}
}

void deal(){
	ll n, m;
	cin>>n>>m;
	map<ll, vector<ll> > xs, ys;
	fori(n){
		forj(m){
			ll ci;
			cin>>ci;
			xs[ci].pb(i);
			ys[ci].pb(j);
		}
	}
	ll ans  = 0;
	add(xs, ans);
	add(ys, ans);
	cout<<ans;
}

 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}