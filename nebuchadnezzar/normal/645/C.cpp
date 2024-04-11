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
const int MAXN = 1e5 + 5;

int k, n;
char s[MAXN];
int pref[MAXN];
int arr[MAXN];

int get_sum(int l, int r) {
 	return pref[r + 1] - pref[l];
}

int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);

	scanf("%d%d", &n, &k);
	scanf("%s", s);

	for (int i = 0; i < n; ++i) {
	 	if (s[i] == '0') {
	 	 	arr[i] = 1;
	 	}
	 	pref[i + 1] = pref[i] + arr[i];
	}
	                      
	int ans = n;
	for (int i = 0; i < n; ++i) {
		if (!arr[i]) {
		 	continue;
		}
	 	int l = 0, r = n;
	 	while (r - l > 1) {
	 	 	int mid = (r + l) / 2;
	 	 	if (get_sum(max(i - mid, 0), min(i + mid, n - 1)) >= k + 1) {
	 	 	 	r = mid;
	 	 	} else {
	 	 	 	l = mid;
	 	 	}
	 	}
	 	ans = min(ans, r);
	}

	cout << ans << "\n";

	return 0;
}