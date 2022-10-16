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
#define fory(v) for(ll y=0; y<v; y++)
#define ll long long
#define lll __int128
#define pb(a) push_back(a)
#define ld long double
#define mt make_tuple
const ll INF = 0x3f3f3f3f;
ll inf = 1e18;
ll modulo = pow(10,9) + 7;


ll pow_mod(ll a, ll b){
	a = a%modulo;
	if(!a){
		return 0;
	}
	ll has = 1%modulo;
	for(ll i = 62; i>-1; i--){
		has*=has;
		has%=modulo;
		if(((ll)1<<i)&b)
			has*=a, has%=modulo;
	}
	return has;
}

#define MAX 400'100

ll fkt[MAX];
ll inv[MAX];

void pre(){
      fkt[0] = 1;
      for(ll i= 1; i<MAX; i++){
            fkt[i]= fkt[i-1] * i % modulo;
      }
      inv[MAX-1] = pow_mod(fkt[MAX-1], modulo-2);
      for(ll i = MAX-2; i>=0; i--){
            inv[i] = inv[i+1] * (i+1) % modulo;
      }
}

ll choose(ll i, ll j){
      return fkt[i] * inv[j] % modulo * inv[i-j] % modulo;
}

void deal(){
      pre();
      ll n;
      cin>>n;
      ll odd = 0;
      vector<ll> tot(30, 0);
      fori(n){
            ll ed;
            cin>>ed;
            if(ed % 2 == 0){
                  ll cnt = 0;
                  while(ed % 2 == 0){
                        ed/=2;
                        cnt++;
                  }
                  tot[cnt]++;
            }
            else{
                  ++odd;
            }
      }
      
      ll bad = 0;
      fori(30){
            ll rest = 0;
            for(ll j = i+1; j<30; j++){
                  rest+=tot[j];
            }
            for(ll j =1; j<=tot[i]; j+=2){
                  bad += choose(tot[i], j) * pow_mod(2, rest) % modulo;
                  bad %= modulo;
            }
      }
      
      ll ans = pow_mod(2, n) -1 - bad;
      
      cout<<(ans % modulo + modulo)%modulo;
}
 
int main(){
      cin.tie(0);
      ios_base::sync_with_stdio(0);
      deal();
}