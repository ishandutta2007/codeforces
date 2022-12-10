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

string com;

void solve() {
	int lo = 1,
		hi = 2;
	cout << '?' << ' ' << hi << ' ' << lo << endl;
	cin >> com;
	if (com == "x") {
		cout << '?' << ' ' << lo << ' ' << hi << endl;
		cin >> com;
		if (com == "x") {
			cout << "! " << 1 << endl;
			return;
		}
	}
	else {
		cout << "! " << 2 << endl;
		return;
	}
	while (true) {
		lo <<= 2;
		swap(lo, hi);
		cout << "? " << hi << ' ' << lo << endl;
		cin >> com;
		if (com == "x")
			continue;
		while (hi - lo > 1) {
			LL mid = (lo + hi) >> 1;
			cout << "? " << mid << ' ' << lo << endl;
			cin >> com;
			if (com == "x")
				lo = mid;
			else
				hi = mid;
		}
		cout << "! " << hi << endl;
		return ;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	while (true) {
		cin >> com;
		if (com == "start")
			solve();
		else
			break;
	}
	return 0;
}