#include <iostream>

using namespace std;

typedef long long ll;

int n, m;
string s[1111];
int d[1111][1111];
int r[1111][1111];
ll c;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}
	for (int j = 0; j < m; j++) {
		d[n-1][j] = 1;
		for (int i = n-2; i >= 0; i--) {
			d[i][j] = s[i][j] == s[i+1][j] ? d[i+1][j]+1 : 1;
		}
	}
	for (int i = 0; i < n; i++) {
		r[i][m-1] = 1;
		for (int j = m-2; j >= 0; j--) {
			r[i][j] = s[i][j] == s[i][j+1] ? r[i][j+1]+1 : 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int h = d[i][j];
			if (i+3*h > n) continue;
			if (d[i+h][j] != h || d[i+2*h][j] < h) continue;
			int u = m;
			for (int k = 0; k < 3*h; k++) {
				u = min(u,r[i+k][j]);
			}
			c += u;
		}
	}
	cout << c << "\n";
}