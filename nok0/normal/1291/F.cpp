/**
 *	author: nok0
 *	created: 2020.09.29 19:48:29
**/
#include <bits/stdc++.h>
using namespace std;
#define FOR(i, l, r) for(int i = (l); i < (r); ++i)
#define REP(i, n) FOR(i, 0, n)

bool ask(int i) {
	cout << "? " << i + 1 << endl;
	char c;
	cin >> c;
	if(c == 'N') return true;
	return false;
}

void ans(int i) {
	cout << "! " << i << endl;
}

int res, n, k;
int main() {
	cin >> n >> k;
	k = max(k, 2);
	vector unique(n, 1);
	REP(i, n / k * 2) {
		for(int j = i + 1; j < n / k * 2; j++) {
			REP(s, k / 2) {
				int d = i * k / 2 + s;
				unique[d] &= ask(d);
			}
			REP(s, k / 2) {
				int d = j * k / 2 + s;
				unique[d] &= ask(d);
			}
			cout << 'R' << endl;
		}
	}
	REP(i, n)
	res += unique[i];
	ans(res);
}