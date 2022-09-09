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

int n, m;

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d%d", &n, &m);

	ll l = 0, r = 1e18;
	
	while (r - l > 1) {
	 	ll mid = (l + r) / 2;
	 	ll d2 = mid / 2;
	 	ll d3 = mid / 3;
	 	ll d6 = mid / 6;
		ll tmp1 = max(n - (d2 - d6), 0ll);
		ll tmp2 = max(m - (d3 - d6), 0ll);
		if (tmp1 + tmp2 <= d6) {
		 	r = mid;
		} else {
		 	l = mid;
		}
	}

	cout << r << "\n";

	return 0;
}