#include <iostream>

using namespace std;

typedef long long ll;

ll k;
int c[22];
string f = "codeforces";
string g;

int main() {
	cin >> k;
	for (int i = 1; i <= 10; i++) c[i] = 1;
	ll t = 1;
	if (t >= k) g = f;
	for (int h = 2; h <= 40; h++) {
		for (int i = 1; i <= 10; i++) {
			t /= c[i];
			c[i]++;
			t *= c[i];
			if (t >= k) {
				string s;
				for (int i = 0; i < 10; i++) {
					for (int j = 0; j < c[i+1]; j++) {
						s += f[i];
					}
				}
				if (g == "" || s.size() < g.size()) g = s;
			}
		}
	}
	cout << g << "\n";
}