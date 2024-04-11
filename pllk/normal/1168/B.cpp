#include <iostream>

using namespace std;

typedef long long ll;

string s;
int n;
int z[555];
int d1[303030];
int d2[303030];
int r[303030];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;
	n = s.size();
	z['0'] = z['1'] = -1;
	for (int i = 0; i < n; i++) {
		d1[i] = z[s[i]];
		z[s[i]] = i;
	}
	z['0'] = z['1'] = -1;
	for (int i = n-1; i >= 0; i--) {
		d2[i] = z[s[i]];
		z[s[i]] = i;
	}
	for (int i = 0; i < n; i++) r[i] = n;
	for (int i = 0; i < n; i++) {
		int a = d1[i];
		int b = d2[i];
		while (true) {
			if (a == -1 || b == -1) break;
			if (i-a == b-i) {
				r[a] = min(r[a],b);
				break;
			}
			if (i-a < b-i) a = d1[a];
			else b = d2[b];
		}
	}
	int g = n;
	ll u = 0;
	for (int i = n-1; i >= 0; i--) {
		g = min(g,r[i]);
		u += n-g;
	}
	cout << u << "\n";
}