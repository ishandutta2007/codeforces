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

const int maxn = int(1e5) + 10;
int n;
int x, y;
char s[maxn];

const ll inf = 1ll<<60;

int f(int a, int b) {
	if (!a && b) return x;
	if (a && !b) return y;
	return 0;
}

ll zans;

int main()
{
	cppio();

	cin >> (s+1);
	cin >> x >> y;
	n = strlen(s+1);

	ll c0 = 0, c1 = 0;
	rrep(i, n) {
		if (s[i] != '1') {
			zans += c1 * f(1, 0);
			++c0;
		} else {
			zans += c0 * f(0, 1);
			++c1;
		}
	}

	int qc = 0;
	rrep(i, n) if (s[i] == '?') ++qc;

	priority_queue<ll> pq;

	ll cc0 = 0, cc1 = 0;
	rrep(i, n) if (s[i] == '?') {
		ll delta = 0;

		ll bef0 = cc0;
		ll bef1 = cc1;

		ll after0 = c0 - cc0 - 1;
		ll after1 = c1 - cc1;

		delta -= x * after1 + y * bef1;
		delta += x * bef0 + y * after0;

		pq.push(-delta);

		++cc0;
	} else {
		if (s[i] == '1') ++cc1;
		else ++cc0;
	}

	ll ans = zans;
	ll cd = 0;
	rrep(qi, qc) {
		cd -= pq.top(); pq.pop();
		ans = min(ans,
			zans + cd - qi * (qi-1ll) / 2 * (x+y));
	}

	cout << ans << '\n';

	return 0;
}