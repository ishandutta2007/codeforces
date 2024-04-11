#include <bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)
#define ff first
#define setp setprecision
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
#define mt make_tuple
#define MAX (int)(4*pow(10,5) + 5)
// #define cout out
// #define cin in
ll inf = pow(10, 18) + 100;
ll INF = pow(10, 9);
ll modulo = 998244353;
double eps = 1e-10;

void updTillEnd(ll id, ll vl, vector<ll>& fen){
	ll sz = fen.size();
	while(id < sz){
		fen[id] += vl;
		if(fen[id] >= modulo){
			fen[id] -= modulo;
		}
		id+=id&-id;
	}
}

ll queTillStart(ll id, vector<ll>& fen){
	ll sz = fen.size();
	ll s = 0;
	id = min(id, sz-1);
	while(id ){
		s+=fen[id];
		if(s >= modulo){
			s-=modulo;
		}
		id-=id&-id;
	}
	return s;
}

void deal(){
	ll n;
	cin>>n;
	vector<ll> arr(n+1);
	arr[0] = -1;
	ll ans = 0;
	vector<ll> fen(n+1, 0);
	for(ll i = 1; i<=n; i++){
		cin>>arr[i];
		ll yi, si;
		cin>>yi>>si;
		ll lo = 0 , hi = i;
		while(lo < hi){
			ll mid = (lo+hi)/2;
			if(arr[mid] > yi){
				hi = mid;
			}
			else{
				lo = mid+1;
			}
		}
		ll cur = queTillStart(i, fen) - queTillStart(lo-1, fen);
		if(cur < 0){
			cur+=modulo;
		}
		cur += arr[i]-yi;
		if(cur >= modulo){
			cur -= modulo;
		}
		updTillEnd(i, cur, fen);
		if(si){
			ans+=cur;
			ans%=modulo;
		}
	}
	ans = (ans+arr[n] + 1) % modulo;
	cout<<ans;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	deal();
}