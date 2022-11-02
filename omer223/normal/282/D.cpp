#define fast ios::sync_with_stdio(false); cin.tie(0)
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define pb push_back
#define mp make_pair
#define F "BitLGM"
#define S "BitAryo"

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <list>


using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int sz = 3, szn = 301;
int a[sz];
bool dp[szn][szn][szn], dp2[szn][szn];

void prec() {
	foru(sm, 0, 3 * (szn - 1) + 1) {
		foru(i, 0, szn) {
			if (i > sm)break;
			foru(j, 0, szn) {
				if (i + j > sm)break;
				if (sm - i - j > szn - 1)continue;
				int k = sm - i - j;
				if (dp[i][j][k])continue;
				foru(p, i + 1, szn)dp[p][j][k] = 1;
				foru(p, j + 1, szn)dp[i][p][k] = 1;
				foru(p, k + 1, szn)dp[i][j][p] = 1;
				for (int p = 1; i + p < szn&&j + p < szn&&k + p < szn;p++)dp[i + p][j + p][k + p] = 1;//opt
			}
		}
	}
	foru(i, 0, szn) {
		foru(j, 0, szn)dp2[i][j] = 0;
	}
	foru(sm, 0, 2 * (szn - 1) + 1) {
		foru(i, 0, szn) {
			if (i > sm)break;
			if (sm - i > szn - 1)continue;
			int j = sm - i;
			if (dp2[i][j])continue;
			foru(p, i + 1, szn)dp2[p][j] = 1;
			foru(p, j + 1, szn)dp2[i][p] = 1;
			for (int p = 1; i + p < szn&&j + p < szn; p++)dp2[i + p][j + p] = 1;
		}
	}
}

int main() {
	fast;
	int n;
	cin >> n;
	foru(i, 0, n)cin >> a[i];
	prec();
	switch (n) {
	case 1:
		cout << (a[0] ? F : S) << endl;
		break;
	case 2:
		cout << (dp2[a[0]][a[1]] ? F : S) << endl;
		break;
	case 3:
		cout << (dp[a[0]][a[1]][a[2]] ? F : S) << endl;
		break;
	}
	return 0;
}