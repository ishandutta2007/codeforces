//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxn = 1000;
int a[maxn][maxn],
	cnt[maxn];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		int x;
		cin >> x;
		cnt[x - 1]++;
	}
	if (n & 1) {
		int tmp = 0;
		for (int i = 0; i < maxn; i++)
			if (cnt[i] & 1) {
				if (tmp)
					return cout << "NO" << endl, 0;
				else {
					tmp = 1;
					a[n / 2][n / 2] = i;
					cnt[i]--;
				}
			}
		tmp = 0;
		vector<int> vec, vec2;
		for (int i = 0; i < maxn; i++) {
			if (cnt[i] % 4 == 2) {
				vec.PB(i);
				cnt[i] -= 2;
			}
			for (int j = 0; j < cnt[i]; j += 4)
				vec2.PB(i);
		}
		if (sz(vec) > n)
			return cout << "NO" << endl, 0;
		int k = n / 2;
		bool addit = false;
		for (int i = 0; i < k; i++) {
			if (sz(vec)) {
				a[k][i] = a[k][n - 1 - i] = vec.back();
				vec.pop_back();
			}
			else {
				a[k][i] = a[k][n - 1 - i] = vec2.back();
				if (i == k - 1)
					a[0][k] = a[n - 1][k] = vec2.back(), addit = true;
				else
					a[k][i + 1] = a[k][n - 1 - (i + 1)] = vec2.back();
				i++;
				vec2.pop_back();
			}
		}
		for (int i = addit; i < k; i++) {
			if (sz(vec)) {
				a[i][k] = a[n - 1 - i][k] = vec.back();
				vec.pop_back();
			}
			else {
				a[i][k] = a[n - 1 - i][k] = vec2.back();
				a[i + 1][k] = a[n - 1 - (i + 1)][k] = vec2.back();
				i++;
				vec2.pop_back();
			}
		}
		for (int i = 0; i < k; i++)
			for (int j = 0; j < k; j++) {
				a[i][j] = a[n - 1 - i][n - 1 - j] = a[i][n - 1 - j] = a[n - 1 - i][j] = vec2.back();
				vec2.pop_back();
			}
	}
	else {
		int k = n / 2;
		int cur = 0;
		for (int i = 0; i < maxn; i++) {
			if (cnt[i] % 4)
				return cout << "NO" << endl, 0;
			for (int j = 0; j < cnt[i]; j += 4, cur++) {
				int r = cur / k;
				int c = cur % k;
				a[r][c] = a[n - r - 1][c] = a[r][n - c - 1] = a[n - r - 1][n - c - 1] = i;
			}
		}
	}
	cout << "YES\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cout << a[i][j] + 1 << " \n"[j == n - 1];
	return 0;
}