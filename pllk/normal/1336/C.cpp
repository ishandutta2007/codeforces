#include <iostream>

using namespace std;

typedef long long ll;
#define M 998244353

string s, t;
int n, m;

ll w[3333][3333];
ll d[3333][3333];

int main() {
	cin >> s >> t;
	n = s.size(); m = t.size();
	s = "#"+s;
	t = "#"+t;
	for (int k = 1; k <= m-1; k++) {
		for (int i = 1; i+k-1 <= m-1; i++) {
			int a = i, b = i+k-1;
			int c = b-a+1;
			if (c == 1) {
				w[a][b] = 2*(s[1] == t[a]);
			} else {
				if (s[c] == t[a]) w[a][b] += w[a+1][b];
				if (s[c] == t[b]) w[a][b] += w[a][b-1];
				w[a][b] %= M;
			}
		}
	}
	d[n+1][0] = 1;
	for (int i = n; i >= 1; i--) {
		d[i][0] = d[i+1][0];
		for (int j = 1; j <= m; j++) {
			d[i][j] = d[i+1][j];
			if (s[i] == t[j]) {
				if (j == 1) d[i][j] += n-i+1;
				else d[i][j] += d[i+1][j-1];
			}
			d[i][j] %= M;
		}
	}
	ll r = 0;
	ll c = 1;
	for (int i = 1; i <= n; i++) {
		r += c*(d[i][m]-d[i+1][m]);
		r %= M;
		c = c*2%M;
	}
	if (s[1] == t[m]) {
		r += d[2][m-1];
		r %= M;
	}
	for (int a = m-1; a >= 1; a--) {
		if (s[m-a+1] == t[m]) {
			r += w[a][m-1]*d[m-a+2][a-1];
			r %= M;
		}
	}
	cout << r << "\n";
}