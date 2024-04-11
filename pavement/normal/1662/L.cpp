// shamelessly copied

#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;
typedef unsigned int ui;
//#define mp make_pair
#define pb push_back
#define vi vector<ll>
#define ti tuple<ll,ll,ll,ll>
#define ff first
#define ss second
#define FOR(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define nl '\n'
#define cma <<','<<
ll mod = 1e9+7;
ll inf = 1e18;
const ll maxn = 400005;

ll ft[maxn], t[maxn], a[maxn];

void up(ll x, ll v) {
	for (; x < maxn; x += x & -x) ft[x] += v;
}
ll qry(ll x) {
	ll sum = 0;
	for (; x; x -= x & -x) sum += ft[x];
	return sum;
}



int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ll n,v; cin >> n >> v;
	vector<pll> v1,v2;
	FOR(i,0,n){
		cin >> t[i];
	}
	FOR(i,0,n){
		cin >> a[i];
		v1.pb({a[i],t[i]});
	}
	for(auto i: v1){
		ll x = i.ff, t = i.ss;
		v2.pb({x+v*t, -x + v*t});
	}
	sort(all(v2));
	
	vector<ll> cur,cur2;
	for(auto i: v2){
		ll q = i.ss, p = i.ff;
		if(cur.empty()){
			cur.pb(q);
		}else{
			auto it = upper_bound(all(cur),q);
			if(it==cur.end()) cur.pb(q);
			else *it = q;
		}
		if(p<0 || q<0) continue;
		if(cur2.empty()) cur2.pb(q);
		else{
			auto it = upper_bound(all(cur2),q);
			if(it==cur2.end())cur2.pb(q);
			else *it = q;
		}
	}
	cout << cur2.size();
}