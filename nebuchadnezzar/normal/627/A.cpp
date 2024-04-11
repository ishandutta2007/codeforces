#include "bits/stdc++.h"
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define bend(_x) (_x).begin(), (_x).end()
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int bd = 20, bdv = 1 << bd;

int sum[bdv * 2];

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	ll s, x;
	cin >> s >> x;

	ll left = x & (bdv - 1);
	ll right = x >> bd;

	for (int i = 0; i < bdv; ++i) {
	 	int tmpl = i ^ left;
	 	sum[tmpl + i]++;
	}

	ll ans = 0;

	for (int i = 0; i < bdv; ++i) {
	 	int tmpr = i ^ right;
	 	assert(tmpr >= 0);
	 	ll ns = (ll) (tmpr + i) << bd;
	 	if (s - ns < bdv * 2 && s - ns >= 0) {
	 	 	//cerr << s - ns << endl;
	 	 	ans += sum[s - ns];
	 	}
	}

	if (s == x) {
	 	ans -= 2;
	}

	cout << ans << endl;

	return 0;
}