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
#define double long double
#define MAX 5010
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = INF;
ll modulo = 998244353;

#define Max_pow 62

ll pow_mod(ll a, ll b){
	a = a%modulo;
	ll val = 1;
	for(ll i = Max_pow; i>-1; i--){
		val*=val , val%=modulo;
		if(((ll)1<<i) & b)
			val *= a, val%=modulo;
	}
	return val; 
}
int inverses[MAX];
int inv(ll a){
	return (inverses[a] == -1)? (inverses[a] = pow_mod(a, modulo-2) ) :(inverses[a]);
}

int arr[MAX];
int dp[MAX];	// we have taken i cards

void deal(){
	fori(MAX)
		inverses[i] = -1;
	int n;
	cin>>n;
	fori(n)
		cin>>arr[i];
	sort(arr, arr+n);
	int st = 0;
	int ans = 0;
	dp[0] = 1;
	while(st<n){
		int nd = st;
		while(nd<n && arr[nd] == arr[st])
			++nd;
		// we win
		fori(MAX){
			if(!dp[i])
				continue;
			ll cav = 1;
			cav*=dp[i], cav*=nd-st, cav%=modulo, cav*=inv(n-i), cav%=modulo;
			cav*= nd-st-1, cav%=modulo, cav*= inv(n-i-1), cav%=modulo;
			ans += cav;
			ans %= modulo;
		}
		for(int i = MAX-2; i>-1 ; i--){
			if(!dp[i])
				continue;
			ll cav = 1;
			cav*= dp[i], cav*= nd-st, cav%=modulo, cav*= inv(n-i), cav%=modulo;
			dp[i+1] += cav;
			dp[i+1] %= modulo;
		}
		st = nd;
	}
	cout<<ans;
	
}



int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}