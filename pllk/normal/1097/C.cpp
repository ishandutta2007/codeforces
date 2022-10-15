#include <iostream>

using namespace std;

int n;
int z;
int f1[505050];
int f2[505050];
int u;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		int k = s.size();
		int d = 0;
		bool ok = true;
		for (int i = 0; i < k; i++) {
			if (s[i] == '(') d++;
			else d--;
			if (d < 0) ok = false;
		}
		if (ok) {
			if (d == 0) z++;
			else if (f2[d]) {
				f2[d]--;
				u++;
			} else f1[d]++;
		}
		d = 0;
		ok = true;
		for (int i = k-1; i >= 0; i--) {
			if (s[i] == ')') d++;
			else d--;
			if (d < 0) ok = false;
		}
		if (ok) {
			if (d == 0);
			else if (f1[d]) {
				f1[d]--;
				u++;
			} else f2[d]++;
		}
	}
	while (z >= 2) {u++; z -= 2;}
	cout << u << "\n";
}