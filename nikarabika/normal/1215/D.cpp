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
	cin >> n;
	n /= 2;
	int x, y, d;
	x = y = d = 0;
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == '?') x++;
		else d += c - '0';
	}
	for (int i = 0; i < n; i++) {
		char c;
		cin >> c;
		if (c == '?') y++;
		else d -= c - '0';
	}
	d += x / 2 * 9 - y / 2 * 9;
#define yes() return cout << "Bicarp\n", 0;
#define no()  return cout << "Monocarp\n", 0;
	if (x & 1 ^ 1) {
		if (d == 0)
			yes();
		no();
	}
	for (int i = 0; i < 10; i++) {
		bool can = false;
		for (int j = 0; j < 10; j++)
			if (d + i - j == 0)
				can = true;
		if (!can)
			no();
	}
	for (int i = 0; i < 10; i++) {
		bool can = false;
		for (int j = 0; j < 10; j++)
			if (d - i + j == 0)
				can = true;
		if (!can)
			no();
	}
	yes();
	return 0;
}