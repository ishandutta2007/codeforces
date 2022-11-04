#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (int) x.size()
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;

int a, b, c;
int x, y, z;

int main() {
	ios::sync_with_stdio(false);

	cin >> a >> b >> c;
	cin >> x >> y >> z;

	int na = x - a;
	int nb = y - b;
	int nc = z - c;

	int get = 0;
	if (na < 0) {
		get += (-na) / 2;
	}
	if (nb < 0) {
		get += (-nb) / 2;
	}
	if (nc < 0) {
		get += (-nc) / 2;
	}

	if (na > 0) {
		get -= na;
	}
	if (nb > 0) {
		get -= nb;
	}
	if (nc > 0) {
		get -= nc;
	}

	cout << (get >= 0 ? "Yes" : "No") << endl;

    return 0;
}