#pragma GCC optimize("O3")
#pragma GCC target("sse4,avx2,abm,fma,tune=native")
#pragma GCC optimize("unroll-loops")

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
const ll inf = pow(10, 9);
ll INF = 1e9;
ll modulo = 998244353;
ld eps = 1e-9;

void fakemerge(string& a, ll& id, ll l, ll r){
	if(r-l <= 1){
		return;
	}
	ll m = (l+r)>>1;
	fakemerge(a, id, l, m);
	fakemerge(a, id, m, r);
	
	if(id == inf){
		return;
	}
	
	ll i = l, j = m;
	
	while(i < m && j<r){
		if(id == (ll)a.length()){
			id = inf;
			return;
		}
		
		if(a[id] == '0'){
			++i;
		}
		else{
			++j;
		}
		++id;
	}
	
}

bool enoughlength(string& a, ll n){
	ll id = 0;
	fakemerge(a, id, 0, n);
	return (id != inf);
}

void actualmerge(vector<ll>& arr, vector<ll>& extra, ll l, ll r, string& a, ll& id){
	if(r-l <= 1){
		return;
	}
	ll m = (l+r)>>1;
	actualmerge(arr, extra, l, m, a, id);
	actualmerge(arr, extra, m, r, a, id);
	
	ll i = l, j = m, k = l;
	
	while(i < m && j<r){
		if(a[id] == '0'){
			extra[k] = arr[i];
			++i;
		}
		else{
			extra[k] = arr[j];
			++j;
		}
		++k;
		++id;
	}
	
	while(i < m){
		extra[k] = arr[i];
		++i;
		++k;
	}
	
	while(j < r){
		extra[k] = arr[j];
		++j;
		++k;
	}
	
	for(ll p = l; p < r; ++p){
		arr[p] = extra[p];
	}
	
}

void deal(){
	string a;
	cin>>a;
	ll lo = 1, hi = 1e5;
	while(lo < hi){
		ll mid = (lo+hi)/2+1;
		if(enoughlength(a, mid)){
			lo = mid;
		}
		else{
			hi = mid-1;
		}
	}
	
	ll n = lo;
	vector<ll> arr(n), extra(n);
	ll id = 0;
	fori(n){
		arr[i] = i;
	}
	
	
	actualmerge(arr, extra, 0, n, a, id);
	extra = arr;
	
	fori(n){
		arr[extra[i]] = i+1;
	}
	
	
	cout<<n<<'\n';
	fori(n){
		 cout<<arr[i]<<' ';
	}
	
}
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}