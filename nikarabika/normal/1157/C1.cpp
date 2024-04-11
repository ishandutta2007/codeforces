//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	deque<int> dq;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		dq.PB(x);
	}
	int prv = 0;
	string ans;
	while (dq.size() and dq.front() != dq.back()) {
		if (dq.front() > dq.back()) {
			if (dq.back() > prv) {
				prv = dq.back();
				dq.pop_back();
				ans += 'R';
			}
			else if (dq.front() > prv) {
				prv = dq.front();
				dq.pop_front();
				ans += 'L';
			}
			else
				break;
		}
		else {
			if (dq.front() > prv) {
				prv = dq.front();
				dq.pop_front();
				ans += 'L';
			}
			else if (dq.back() > prv) {
				prv = dq.back();
				dq.pop_back();
				ans += 'R';
			}
			else
				break;
		}
	}
	int sprv, le, ri;
	if (max(dq.front(), dq.back()) <= prv)
		goto hell;
	sprv = prv;
	le = 0;
	while (le < sz(dq) and dq[le] > prv) {
		prv = dq[le];
		le++;
	}

	prv = sprv;
	ri = 0;
	while (ri < sz(dq) and dq[sz(dq) - 1 - ri] > prv) {
		prv = dq[sz(dq) - 1 - ri];
		ri++;
	}
	if (le > ri)
		for (int i = 0; i < le; i++)
			ans += 'L';
	else
		for (int i = 0; i < ri; i++)
			ans += 'R';
hell:
	cout << sz(ans) << endl
		<< ans << endl;
	return 0;
}