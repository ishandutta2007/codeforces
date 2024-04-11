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
#define MAX (int)(pow(10,6) + 5)
// #define cout out
// #define cin in
ll inf = pow(10, 18) + 100;
ll INF = pow(10, 9);
ll modulo = 998244353;
double eps = 1e-10;

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n;
		cin>>n;
		vector<vector<ll> > arr(2, vector<ll>(n));
		vector<vector<ll> > pref(2, vector<ll>(n+1, 0));
		fori(2){
			forj(n){
				cin>>arr[i][j];
			}
			sort(arr[i].rbegin(), arr[i].rend());
			for(ll j = 1; j<=n; j++){
				pref[i][j] = pref[i][j-1]+arr[i][j-1];
			}
		}
		ll lo = n, hi = 4e5;
		while(lo < hi){
			ll mid = (lo+hi)/2;
			ll s1 = 0, s2 = 0;
			if(mid - n >= mid - mid/4){
				s1 = (mid-mid/4)*100;
			}
			else{
				s1 = (mid - n)*100 + pref[0][mid - mid/4 - (mid-n)];
			}
			s2 = pref[1][min(n, mid-mid/4)];
			if(s1 >= s2){
				hi = mid;
			}
			else{
				lo = mid+1;
			}
		}
		cout<<lo - n<<'\n';
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	deal();
}