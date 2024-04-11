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

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n,k;
		cin>>n>>k;
		vector<ll> arr(n);
		vector<ll> occ(n+1);
		fori(n){
			cin>>arr[i];
			occ[arr[i]]++;
		}
		ll ri = 0;
		ll tot = 0;
		ll lans = -1, rans  = inf;
		for(ll li = 1; li<=n; li++){
			while(ri + 1 <=n && tot < n - tot + k){
				++ri;
				tot += occ[ri];
			}
			if(tot >= n - tot + k && ri - li < rans - lans){
				lans = li, rans = ri;
			}
			tot -= occ[li];
		}
		cout<<lans<<" "<<rans<<'\n';
		vector<pair<ll,ll> > ans;
		{
			ll st = 0;
			while(st < n){
				ll cnt = 0;
				ll sv = st;
				while(st < n && cnt <= 0){
					if(arr[st] >= lans && arr[st] <= rans){
						++cnt;
					}
					else{
						--cnt;
					}
					++st;
				}
				ans.pb(mp(sv+1, st));
			}
			while((ll)ans.size() > k){
				ans.erase(ans.end()-1);
			}
			ans.back().ss = n;
		}
		assert((ll)ans.size() == k);
		fori(k){
			cout<<ans[i].ff<<" "<<ans[i].ss<<'\n';
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}