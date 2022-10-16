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
ll modulo = 998244353 ;
double eps = 1e-6;
ifstream in;
ofstream out;

ll pow_mod(ll a, ll b){
	a = a%modulo;
	ll has = 1%modulo;
	for(ll i = 30; i>-1; i--){
		has*=has;
		has%=modulo;
		if((1<<i)&b)
			has*=a, has%=modulo;
	}
	return has;
}


#define MAX 200'100

vector<pair<ll, ll> > dv[MAX];
ll invs[MAX];
bool isp[MAX];

void pre(){
	for(ll i = 2; i<MAX; i++){
		isp[i] = 1;
	}
	fori(MAX){
		if(isp[i]){
			for(ll j = i; j<MAX; j+=i){
				isp[j] = 0;
				ll cr = j;
				ll cnt = 0;
				while(cr % i == 0){
					cr/=i;
					++cnt;
				}
				dv[j].pb(mp(i, cnt));
			}
			isp[i] = 1;
		}
	}
	invs[0] = 1;
	for(ll i = 1; i<MAX; i++){
		invs[i] = pow_mod(i, modulo-2);
	}
}


ll mn[MAX];
ll cur[MAX];
bool seen[MAX];
vector<ll> save;
vector<tuple<ll, ll, ll> > g[MAX];

void dfs1(ll hd, ll pr){
	for(auto&[hr, x, y] : g[hd]){
		if(hr == pr){
			continue;
		}
	//	cout<<"we going from "<<hd+1<<" "<<hr+1<<endl;
		for(auto& el : dv[x]){
			cur[el.ff]+=el.ss;
		}
		for(auto& el : dv[y]){
			ll wh = el.ff;
			cur[wh] -= el.ss;
			mn[wh] = min(mn[wh], cur[wh]);
			
	//		cout<<"we got new "<<wh<<" which is "<<mn[wh]<<endl;
			
			if(cur[wh] < 0 && !seen[wh]){
				seen[wh] = 1;
				save.pb(wh);
			}
		}
		dfs1(hr, hd);
		for(auto& el : dv[x]){
			cur[el.ff]-=el.ss;
		}
		for(auto& el : dv[y]){
			cur[el.ff]+=el.ss;
		}
	}
}

void dfs2(ll hd, ll pr, ll curval, ll& s){
	s += curval;
	if(s >= modulo){
		s-=modulo;
	}
	for(auto& [hr, x, y] : g[hd]){
		if(hr == pr){
			continue;
		}
		ll pv = curval;
		curval *= x;
		curval %= modulo;
		curval *= invs[y];
		curval %= modulo;
		dfs2(hr, hd, curval, s);
		curval = pv;
	}
}

void deal(){
	pre();
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		fori(n-1){
			ll ai, bi, xi , yi;
			cin>>ai>>bi>>xi>>yi;
			--ai, --bi;
			ll ebob = __gcd(xi, yi);
			xi /= ebob, yi /= ebob;
			g[ai].pb(mt(bi, yi, xi));
			g[bi].pb(mt(ai, xi, yi));
		}
		
		dfs1(0, -1);
		ll curval = 1;
		for(auto& el : save){
			curval *= pow_mod(el, -mn[el]);
	//		cout<<"we need to have "<<el<<" ^ "<<-mn[el]<<endl;
			curval %= modulo;
			mn[el] = 0;
			seen[el] = 0;
		}
		
		
		ll s=  0;
		dfs2(0, -1, curval, s);
		
		cout<<s<<'\n';
		
		
		save.clear();
		fori(n){
			g[i].clear();
		}
		
		
	}
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}