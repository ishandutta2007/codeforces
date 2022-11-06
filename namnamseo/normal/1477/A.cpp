#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void cppio(){ ios_base::sync_with_stdio(0); cin.tie(0); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define sz(x) (int)(x).size()

const int maxn = int(2e5) + 10;

int n;
ll k;

int main()
{
	cppio();
int tc; cin >> tc;
rep(tci, tc) {
	cin >> n >> k;
	ll hab = 0;
	ll v0;
	rrep(i, n) {
		ll x; cin >> x;
		if (i == 1) {
			v0 = x; continue;
		}
		ll d = abs(x - v0);
		hab = gcd(hab, d);
	}
	k -= v0;
	if (k % hab) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
	}
}

	return 0;
}