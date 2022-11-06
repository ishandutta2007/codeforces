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

int main()
{
	cppio();
	int tc; cin >> tc;
for(;tc--;) {
	ll n; cin >> n;
	if (n <= 3) {
		cout << n << '\n';
		continue;
	}
	n -= 3;
	for(ll gi=1, gc = 12, gs = 4; ; ++gi) {
		if (n > gc) {
			n -= gc;
			gs += gc;
			gc *= 4;
			continue;
		}
		if (n%3 == 1) {
			cout << (gs + (n/3)) << '\n';
			break;
		}
		vector<int> pat;
		ll st;
		if (n%3 == 2) {
			pat = {0, 2, 3, 1};
			st = gs + gc/3;
		} else {
			pat = {0, 3, 1, 2};
			st = gs + gc/3*2;
			n -= 3;
		}
		n /= 3;
		for(ll step = 1; step <gc/3; step *= 4) {
			st += pat[n%4] * step;
			n /= 4;
		}
		cout << st << '\n';
		break;
	}
}
	return 0;
}