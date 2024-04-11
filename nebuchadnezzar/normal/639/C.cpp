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
const ll INF = 1e9 + 7;

int n, k;

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d%d", &n, &k);

	vector<int> inp;
	for (int i = 0; i <= n; ++i) {
	 	int num;
	 	scanf("%d", &num);
	 	inp.puba(num);
	}

	vector<ll> suff(n + 2);
	ll now = 0;

	for (int i = n; i >= 0; --i) {
	 	suff[i + 1] = now;
	 	now = now * 2 + inp[i];
	 	if (now > INF) {
	 	 	now = INF + 1;
	 	}
	 	if (now < -INF) {
	 	 	now = -INF - 1;
	 	}
	}

	suff[0] = now;

	ll rest = 0;

	int ans = 0;
	for (int i = 0; i <= n && rest % 2 == 0; ++i) {
	 	//rest = (rest / 2 + inp[i]);
	 	rest /= 2;
	 	//cerr << abs(suff[i + 1] * 2) << endl;
	 	if (abs((ll) suff[i + 1] * 2 + rest) <= k && (i < n || (ll) suff[i + 1] * 2 + rest != 0)) {
	 		//cerr << i << " " << -(suff[i + 1] * 2 + rest) << endl;
	 	 	++ans;
	 	}
	 	rest += inp[i];
	}

	cout << ans << "\n";

	return 0;
}