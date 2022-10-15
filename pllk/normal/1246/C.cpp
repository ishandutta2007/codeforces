#include <iostream>

using namespace std;

#define M 1000000007

typedef long long ll;

int n, m;
string s[2222];
int aa[2222][2222];
int oo[2222][2222];
ll ad[2222][2222];
ll od[2222][2222];
int yc[2222], xc[2222];
int yp[2222], xp[2222];
ll yd[2222], xd[2222];

int main() {
	cin >> n >> m;
	if (n == 1 && m == 1) {
		cout << "1\n";
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		s[i] = "#"+s[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 1; j--) {
			oo[i][j] = oo[i][j+1]+(s[i][j]=='R');
		}
	}
	for (int j = 1; j <= m; j++) {
		for (int i = n; i >= 1; i--) {
			aa[i][j] = aa[i+1][j]+(s[i][j]=='R');
		}
	}
	ad[1][1] = od[1][1] = 1;
	for (int i = 1; i <= n; i++) yp[i] = 1;
	for (int i = 1; i <= m; i++) xp[i] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int au = n-i-aa[i][j];
			while (xp[j] <= n && xc[j] > au) {
				xd[j] -= ad[xp[j]-1][j];
				if (s[xp[j]][j] == 'R') xc[j]--;
				xp[j]++;
			}
			od[i][j] += xd[j]%M;
			od[i][j] %= M;

			int ou = m-j-oo[i][j];
			while (yp[i] <= m && yc[i] > ou) {
				yd[i] -= od[i][yp[i]-1];
				if (s[i][yp[i]] == 'R') yc[i]--;
				yp[i]++;
			}
			ad[i][j] += yd[i]%M;
			ad[i][j] %= M;

			yd[i] += od[i][j];
			xd[j] += ad[i][j];

			if (s[i][j] == 'R') {yc[i]++; xc[j]++;}
		}
	}

	ll rr = (ad[n][m]+od[n][m])%M;
	cout << rr << "\n";
}