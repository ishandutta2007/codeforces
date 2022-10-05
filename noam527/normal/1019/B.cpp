#include <bits/stdc++.h>
#define fast ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define debug cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7, inf = 1e9 + 7;
const ll hs = 199;
const ldb eps = 1e-9, pi = acos(-1);
using namespace std;

int ask(int pos) {
	pos++;
	cout << "? " << pos << endl;
	fflush(stdout);
	cout.flush();
	int rtn;
	cin >> rtn;
	return rtn;
}
int end(int pos) {
	pos++;
	cout << "! " << pos << endl;
	return 0;
}

int main() {
	fast;
	int n;
	cin >> n;
	n /= 2;
	if (n & 1) return end(-2);

	int at = 2 * n - 1, jump, p[2];

	if (ask(0) < ask(n - 1)) {
		// go if askright > askleft
		jump = n / 2;
		while (jump > 1) {
			if (at - jump >= n) {
				p[0] = ask(at - n - jump);
				p[1] = ask(at - jump);
				if (p[0] == p[1]) return end(at - n - jump);
				if (p[0] > p[1]) at -= jump;
			}
			jump = (jump + 1) / 2;
		}
		if (at > n && ask(at - n - 1) == ask(at - 1)) at--;
		return end(at - n);
	}
	// go if askright < askleft
	jump = n / 2;
	while (jump > 1) {
		if (at - jump >= n) {
			p[0] = ask(at - n - jump);
			p[1] = ask(at - jump);
			if (p[0] == p[1]) return end(at - n - jump);
			if (p[0] < p[1]) at -= jump;
		}
		jump = (jump + 1) / 2;
	}
	if (at > n && ask(at - n - 1) == ask(at - 1)) at--;
	return end(at - n);
}