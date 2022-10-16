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
#define MAX (int)(2*pow(10,5) + 10)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = 100'000'007;


ll pv[MAX];

void pre(){
	pv[0] = 1;
	for(ll i= 1; i<63; i++){
		pv[i] = pv[i-1] * 2;
	}
	
	for(ll i = 63; i<MAX; i++){
		pv[i] = pv[i-1];
	}
	
}

void recurse(ll& n , ll& cur, vector<ll>& arr, ll& k){
	if(cur > n){
		return;
	}
	if(cur == n){
		arr.pb(n);
		return;
	}
	
	
	ll tot = n-cur+1;
	
	// very first one has 2^(tot-2) choices etc...
	
	
	
	for(ll i = tot-2, now = cur, summed = 0; ;i--, now++){
		if(i < 0){
			i = 0;
		}
		
		if(summed + pv[i] >= k){
			k -= summed;
			for(ll j = now; j>= cur; j--){
				arr.pb(j);
			}
			now++;
			return recurse(n, now, arr, k);
		}
		
		summed+=pv[i];
		
	}
	
	
}

void deal(){
	pre();	
	
	srand(time(NULL));
	ll t;
	cin>>t;
	
	forl(t){
		ll n, k;
		cin>>n>>k;
		
		ll tot = 1;
		
		fori(n-1){
			tot*=2;
			if(tot >= k){
				break;
			}
		}
		
		if(tot < k){
			cout<<-1<<'\n';
			continue;
		}
		
		vector<ll> ans;
		{
			ll cur = 1;
			recurse(n, cur, ans, k);
		}
		
		for(auto& el : ans){
			cout<<el<<' ';
		}
		cout<<'\n';
		
	}
	
}

int main(){

    cin.tie(0);
    ios_base::sync_with_stdio(0);
    deal();
}