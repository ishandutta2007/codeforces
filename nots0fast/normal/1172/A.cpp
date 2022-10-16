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
#define MAX (int)(pow(10,6)+10)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,7)+10;
ll modulo = 1000000007;

ll arr[MAX], arr1[MAX];
bool have[MAX];


ll check(ll n){
	fori(n+1)
		have[i] = 0;
	fori(n)
		have[arr[i]] = 1;
	ll index = -1;
	fori(n){
		if(arr1[i] == 1){
			index = i;
			break;
		}
	}
	if(index == -1)	
		return inf;
	ll sv = index;
	while(index < n-1 && arr1[index+1] == arr1[index] + 1)
		++index;
	if(index != n-1)
		return inf;
	ll what = 2 + index - sv;
	for(ll i = n; what < n + 1 ;i++, what++){
		if(!have[what])
			return inf;
		have[arr1[i-n]] = 1;
	}
	return n - 1 - (index - sv);
}

void deal(){
	ll n;
	cin>>n;
	fori(n)
		cin>>arr[i];
	fori(n)
		cin>>arr1[i];
	ll mn = check(n);
	ll lo = 0, hi= n;
	while(lo< hi){
		ll mid = (lo + hi)>>1;
		fori(n+1)
			have[i] = 0;
		fori(n)
			have[arr[i]] = 1;
		fori(mid)
			have[arr1[i]] = 1;
		bool gg = 1;
		for(ll i = 1; i<=n; i++){
			if(!have[i])
				gg = 0;
			if(i+mid-1<n)
				have[arr1[i+mid-1]] = 1;
		}
		if(gg)
			hi = mid;
		else
			lo = mid+1;
	}
	mn = min(mn, lo+n);
	cout<<mn;
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