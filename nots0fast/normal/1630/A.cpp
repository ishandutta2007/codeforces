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
#define ll long long
#define ld long double
#define pb push_back
#define mt make_tuple
// #define cout out
// #define cin in
ll inf = pow(10,18);
ll modulo = pow(10, 9) + 7;
double eps = 1e-6;
ifstream in;
ofstream out;

void func(){
	
}

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll m, k;
		cin>>m>>k;
		ll n = 0;
		forj(30){
			if((1<<j) & m){
				n = j;
			}
		}
		if(n == 2){
			if(k == 0){
				cout<<"0 3\n1 2\n";
			}
			else if(k == 1){
				cout<<"0 2\n1 3\n";
			}
			else if(k == 2){
				cout<<"0 1\n2 3\n";
			}
			else{
				cout<<-1<<'\n';
			}
		}
		else{
			set<ll> matched;
			set<pair<ll, ll > > all;
			if(k == (1<<n) - 1){
				all.insert(mp(m-1, (1<<(n-1)) + 1));
				all.insert(mp(m-2, (m-1- (1<<(n-1)) )));
			}
			else{
				all.insert(mp(m-1, k));
			}
			
			set<pair<ll, ll> > yen;
			for(auto& el : all){
				ll ai = el.ff, bi = el.ss;
				ll r1 = ((m-1) ^ ai), r2 = ((m-1) ^ bi);
				if(r1 < r2){
					swap(r1, r2);
				}
				yen.insert(mp(r1, r2));
			}
			for(auto& el : yen){
				all.insert(el);
			}
			for(auto& el : all){
				matched.insert(el.ff);
				matched.insert(el.ss);
			}
			fori(1<<n){
				if(matched.find(i) == matched.end()){
					ll rev = ((m-1) ^ i);
					if(rev < i){
						all.insert(mp(i, rev));
						assert(matched.find(rev) == matched.end());
						matched.insert(i);
						matched.insert(rev);
					}
				}
			}
			assert((ll)matched.size() == m);
			assert((ll)all.size() == m/2);
			ll sum = 0;
			for(auto& el : all){
				sum += (el.ff & el.ss);
				cout<<el.ff<<' '<<el.ss<<'\n';
			}
			assert(sum == k);
			
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}