#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;
typedef vector<bool> vb;
const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= (a); i--)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s; cin >> s;
	ll n = sz(s);
	vl a(n);
	FOR(i,0,n) a[i] = s[i]-'0';
	ll m = 200; //sqrt(n)+1;
	
	long long res = 0;

	clock_t start = clock();

	vl sum(n+1);
	FOR(i,0,n) sum[i+1] = sum[i] + a[i];
	
	FOR(k,1,m+1) {
		map<ll,ll> cnt;
		FOR(i,0,n+1) cnt[k*sum[i] - i]++;
		
		for (auto [x,c]: cnt) res += c*1LL*(c-1)/2;
	}
	
	cerr << double(clock()-start)/CLOCKS_PER_SEC << endl;

	vl step(n+1,n);
	FORD(i,0,n) step[i] = a[i] ? i : step[i+1];

	FOR(cnt,1,n/m+10) {
		ll j = 0, cur = 0;
		FOR(i,0,n) {
			while (cur < cnt) {
				if (j == n) break;
				cur += a[j++];
			}
			if (cur < cnt) break;

			ll minlen = max((m+1)*cnt, j-i);
			ll maxlen = step[j]-i;

			if (minlen <= maxlen) {
				res += maxlen/cnt - (minlen + cnt-1)/cnt + 1;
			}
			
			cur -= a[i];
		}
	}
	
	cout << res << endl;
}