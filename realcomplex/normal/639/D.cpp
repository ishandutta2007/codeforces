#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef pair<ll, ll> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
	fastIO;
	int n, k;
	ll x, y;
	cin >> n >> k >> x >> y;
	x = min(x, 5 * y);
	ll a[n];
	for(int i = 0 ;i < n; i ++ ){
		cin >> a[i];
	}
	ll q;
	ll rq;
	ll val;
	ll sum;
	ll answ = (ll)9e18;
	for(int t = 0 ;t < 5; t ++ ){
		vector<pii> rr;
		for(int j = 0 ; j < n ; j ++ ){
			q = a[j];
			rq = 0;
			while(((q % 5) + 5) % 5 != t)
				q ++, rq ++  ;
			rr.push_back(mp(q, rq));
		}
		sort(rr.begin(), rr.end());
		multiset<ll> rem;
		sum = 0;
		for(int j = 0 ; j < n ; j ++ ){
			q = rr[j].fi;
			rq = rr[j].se;
			q -= rr[0].fi;
			q /= 5;
			q *= x;
			val = q;
			val = -val;
			val += y * rq;
			rem.insert(val);
			sum += val;
			while(rem.size() > k){
				auto it = rem.end();
				-- it;
				sum -= *it;
				rem.erase(it);
			}
			if(rem.size() == k){
				answ = min(answ, sum + k * q);
			}
		}
	}
	cout << answ << "\n";
	return 0;
}