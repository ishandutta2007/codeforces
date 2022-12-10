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

const int maxn = 2e5 + 10;
int a[maxn],
	b[maxn],
	pos[maxn],
	n;
deque<int> dq;

void first_solve() {
	if (dq.back() == -1)
		return;
	int ptr = n - 1;
	while (ptr > 0 and dq[ptr] and dq[ptr] == dq[ptr - 1] + 1)
		ptr--;
	if (dq[ptr] != 0) return;
	int k = dq.back();
	for (int i = k + 1; i < n; i++)
		if (pos[i] + 1 >= i - k)
			return;
	cout << n - 1 - k << endl;
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
	}
	for (int i = 0; i < n; i++)
		pos[i] = -1e8;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		b[i]--;
		if (~b[i])
			pos[b[i]] = i;
		dq.PB(b[i]);
	}
	first_solve();
	int ans = 0;
	for (int i = 0; i < n; i++)
		smax(ans, pos[i] - i + 1);
	cout << n + ans << endl;
	return 0;
}