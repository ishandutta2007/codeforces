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
	int n, f[100];
	string s;
	cin >> n
		>> s;
	for (int i = 0; i < 9; i++) {
		cin >> f[i];
	}
	bool found = false;
	for (auto &c : s) {
		if (f[c - '1'] > c - '0')
			c = f[c - '1'] + '0', found = true;
		else if (found and f[c - '1'] < c - '0')
			break;
	}
	cout << s << endl;

	return 0;
}