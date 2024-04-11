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
#define lll __int128
#define pb(a) push_back(a)
typedef long double ld;
const ll INF = 0x3f3f3f3f;
const ll inf =  pow(10, 18);
const ll modulo = pow(10,9) + 7;

void deal(){
	ll t;
	cin>>t;
	forl(t){
		ll n, m;
		cin>>n>>m;
		vector<ll> pts;
		fori(n){
			ll ed;
			cin>>ed;
			pts.pb(ed);
		}
		pts.pb(-inf);
		pts.pb(inf);
		sort(pts.begin(), pts.end());
		n+=2;
		vector<vector<pair<ll,ll> > > all(n);
		fori(m){
			ll li ,ri;
			cin>>li>>ri;
			auto id = upper_bound(pts.begin(), pts.end(), ri) - pts.begin() - 1;
			if(pts[id] >= li){
				continue;
			}
			all[id].pb(mp(li, ri));
		}
		vector<vector<ll> > dp(n, vector<ll>(2));
		dp[0] = vector<ll>(2, 0);
		// 0 - went , 1 - went and came back
		for(ll i = 0; i<n-1; i++){
			// do the transition between i and i+1
			sort(all[i].begin(), all[i].end());
			multiset<ll> rs;
			rs.insert(pts[i+1]);
			for(auto& el : all[i]){
				rs.insert(el.ss);
			}
			{
				ll mn = (*rs.begin());
				dp[i+1][0] = dp[i][0] + pts[i+1] - mn;
				dp[i+1][1] = dp[i][0] + 2*(pts[i+1] - mn);
			}
			for(ll j = 0; j<(ll)all[i].size(); j++){
				ll li = all[i][j].ff;
				ll ri = all[i][j].ss;
				rs.erase(rs.find(ri));
				ll mn = (*rs.begin());
				dp[i+1][0] = min(dp[i+1][0], 
					min(dp[i][1] + li - pts[i], dp[i][0] + 2*(li - pts[i])) + pts[i+1] - mn);
				dp[i+1][1] = min(dp[i+1][1], 
					min(dp[i][1] + li - pts[i], dp[i][0] + 2*(li - pts[i])) + 2*(pts[i+1] - mn));
			}
		}
		cout<<dp[n-1][0]<<'\n';
	}
}
 
int main()  {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	deal();
}