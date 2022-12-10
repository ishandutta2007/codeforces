//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define smin(x, y) x = min(x, y)

const int maxn = 1e5 + 10,
	  maxval = 2e7;
int taken[maxval],
	isp[maxval],
	a[maxn];
int n;

bool isgood(int val, int pos) {
	while (val > 1) {
		if (taken[isp[val]] < pos)
			return false;
		val /= isp[val];
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	memset(isp, -1, sizeof isp);
	for (int i = 2; i < maxval; i++)
		if (isp[i] == -1) {
			isp[i] = i;
			for (LL j = 1LL * i * i; j < maxval; j += i)
				isp[j] = i;
		}

	memset(taken, 63, sizeof taken);
	cin >> n;
	int badpos = -1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		int tmp = a[i];
		bool bad = false;
		while (a[i] > 1) {
			int p = isp[a[i]];
			if (taken[p] >= i)
				taken[p] = i;
			else {
				bad = true;
				break;
			}
			while (a[i] % p == 0)
				a[i] /= p;
		}
		a[i] = tmp;
		if (bad) {
			badpos = i;
			a[i] = tmp + 1;
			for (int j = 0; j < maxval; j++)
				if (taken[j] == i)
					taken[j] = taken[maxval - 1];
			while (!isgood(a[i], badpos))
				a[i]++;
			int tmp = a[i];
			while (tmp > 1)
				taken[isp[tmp]] = i, tmp /= isp[tmp];
			break;
		}
	}
	if (badpos != -1) {
		int pos = 2;
		for (int i = badpos + 1; i < n; i++) {
			while (isp[pos] != pos or taken[pos] <= badpos) pos++;
			a[i] = pos;
			pos++;
		}
	}
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
	return 0;
}