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
int siz;
int a[maxn],
	n;
int vec[100];

void add(int val) {
	for (int i = 0; i < siz; i++)
		if (val & (vec[i] & -vec[i]))
			val ^= vec[i];
	if (!val)
		return;
	for (int i = 0; i < siz; i++)
		if (vec[i] & (val & -val))
			vec[i] ^= val;
	vec[siz++] = val;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[i + 1] = a[i] ^ x;
	}
	if (!a[n])
		return cout << -1 << endl, 0;
	for (int i = 0; i <= n; i++)
		add(a[i]);
	cout << siz << endl;
	return 0;
}