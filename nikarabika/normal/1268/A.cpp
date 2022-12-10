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
	int n, k;
	cin >> n >> k;
	int *a = new int[n];
	bool bad = false;
	bool found = false;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		a[i] = c - '0';
		if (a[i] > a[i % k] and !found)
			bad = true;
		else if (a[i] < a[i % k])
			found = true;
	}
	if (bad)
		for (int i = k - 1; i >= 0 and (i == k - 1 or a[i + 1] == 0); i--)
			a[i] = (a[i] + 1) % 10;
	cout << n << '\n';
	for (int i = 0; i < n; i++)
		cout << a[i % k];
	cout << '\n';
	return 0;
}