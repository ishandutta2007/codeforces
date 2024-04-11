#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 1;
const ll LINF = (ll) 1e18 + 1;
const ld EPS = 1e-9;

int n;

void run() {
	cin >> n;
	int a = 0;
	int d = 0;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A') {
			a++;
		} else {
			d++;
		}
	}
	
	if (a == d) {
		cout << "Friendship\n";
	} else if (a > d) {
		cout << "Anton\n";
	} else {
		cout << "Danik\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	run();
	
	return 0;
}