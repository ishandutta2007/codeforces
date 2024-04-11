#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m, ans=0;
bool pos[25][25][25][25];
string s[25];

int main() {
	cin >> n >> m;
	for (int i=0; i<n; ++i)
		cin >> s[i];

	memset(pos, 0, sizeof(pos));
	for (int a=0; a<n; ++a) {
		for (int b=0; b<m; ++b) {
			for (int c=a; c<n; ++c) {
				for (int d=b; d<m; ++d) {
					if (a==c&&b==d&&s[a][b]=='0')
						pos[a][b][c][d] = 1;
					else if (c>a) {
						if (pos[a][b][c-1][d]) {
							bool ok = 1;
							for (int i=b; i<=d; ++i) {
								if (s[c][i]=='1') {
									ok = 0;
									break;
								}
							}
							if (ok)
								pos[a][b][c][d] = 1;
						}
					}
					else if (d>b) {
						if (pos[a][b][c][d-1]) {
							bool ok = 1;
							for (int i=a; i<=c; ++i) {
								if (s[i][d]=='1') {
									ok = 0;
									break;
								}
							}
							if (ok)
								pos[a][b][c][d] = 1;
						}
					}
					if (pos[a][b][c][d])
						ans = max(ans, 2*(c-a+d-b+2));
				}
			}
		}
	}
	cout << ans;
	return 0;
}