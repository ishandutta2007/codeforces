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
#define double long double
#define MAX (int)(pow(10,6) + 10)
#define pb(a) push_back(a)
const ll INF = 0x3f3f3f3f;
const ll inf = pow(10,18);
ll modulo = pow(10,9)+7;

void getIt(ll l, ll r, ll special, ll specialcost, ll& tot, vector<ll>& jump, vector<vector<ll> >& arr, ll& n){
	if(r == n-1){
		return;
	}
	ll lz = -1;
	ll mx = -1;
	for(ll i = l; i<=r; i++){
		if(arr[i][1] - (arr[r][0] - arr[i][0]) > mx){
			lz = i;
			mx = arr[i][1] - (arr[r][0] - arr[i][0]);
		}
	}
	
//	cout<<"we at "<<l+1<<" "<<r+1<<endl;
	
	if(mx < arr[r+1][0] - arr[r][0]){
		// check special
		if(arr[special][1] - (arr[r][0] - arr[special][0]) > mx){
			lz = special;
			mx =  arr[special][1] - (arr[r][0] - arr[special][0]);
			tot -= specialcost;
		}
		else{
			special = lz;
		}
		tot += (arr[r+1][0] - arr[r][0]) - mx;
		specialcost = mx;
		getIt(r+1, r+1, special, specialcost, tot, jump, arr, n);
	}
	else{
		getIt(r+1, jump[lz], lz, 0, tot, jump, arr, n);
	}
	
}

void deal(){
	ll n;
	cin>>n;
	vector<vector<ll> > arr;
	fori(n){
		ll ai, ci;
		cin>>ai>>ci;
		arr.pb(vector<ll>({ai, ci}));
	}
	
	sort(arr.begin(), arr.end());
	
	ll tot = 0;
	
	
	fori(n){
		tot+=arr[i][1];
	}
	
	vector<ll> jump(n, 0);
	vector<ll> dp(n, 0);
	for(ll i = 1; i<n; i++){
		dp[i] = dp[i-1] + arr[i][0] - arr[i-1][0];
	}
	
	fori(n){
		ll lo = i, hi = n-1;
		while(lo < hi){
			ll mid = (lo+hi)/2 + 1;
			ll cs = dp[mid] - dp[i];
			if(cs <= arr[i][1]){
				lo = mid;
			}
			else{
				hi = mid-1;
			}	
		}
		jump[i] = lo;
	}
	
	getIt(0, 0, 0, 0, tot, jump, arr, n);
	
	cout<<tot;
	
}


 
 
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}