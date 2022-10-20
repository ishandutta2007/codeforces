#include <bits/stdc++.h>

using namespace std;

const int N = 400010;

int n;
char s[N];
int cnt[100];

int turn(char u) {
	if (u >= 'a' && u <= 'z') return u - 'a';
	if (u >= 'A' && u <= 'Z') return u - 'A' + 26;
	return u - '0' + 26 * 2;
}

char revturn(int u) {
	if (u < 26) {
		return u + 'a';
	}
	if (u < 26 * 2) {
		return u + 'A' - 26;
	}
	return u + '0' - 26 * 2;
}

int odd = 0;

bool check(int u) {
	if ((n / u) & 1) {
		return odd <= u && (u - odd) % 2 == 0;
	}
	return odd == 0;
}

char ans[N];

char getNxt() {
	for (int i = 0; i < 100; i++) {
		if (cnt[i] >= 2) {
			cnt[i] -=  2;
			return revturn(i);
		}
	}
}

char getNxtOdd() {
	for (int i = 0; i < 100; i++) {
		if (cnt[i] % 2 == 1 && cnt[i]) {
			cnt[i]--;
			return revturn(i);
		}
	}
	for (int i = 0; i < 100; i++) {
		if (cnt[i]) {
			cnt[i]--;
			return revturn(i);
		}
	}
}

int main() {
	scanf("%d", &n);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) {
		cnt[turn(s[i])]++;
	}
	for (int i = 0; i < 100; i++) {
		if (cnt[i] & 1) {
			odd++;
		}
	}
	int res = -1;
	for (int i = 1; i <= n; i++) {
		if (n % i != 0) {
			continue;
		}
		if (check(i)) {
			if (res == -1 || res > i) {
				res = i;
			}
		}
	}
	cout << res << endl;
	if ((n / res) % 2 == 0) {
		for (int i = 1; i <= res; i++) {
			for (int j = 1; j <= n / res / 2; j++) {
				ans[j] = ans[n / res - j + 1] = getNxt();
			}
			for (int j = 1; j <= n / res; j++) {
				cout << ans[j];
			}
			cout << " ";
		}
	} else {
		int len = n / res;
		cerr << len << endl;
		for (int i = 1; i <= res; i++) {
			for (int j = 1; j <= len / 2; j++) {
				ans[j] = ans[len - j + 1] = getNxt();
				// cout << j << " " << ans[j] << endl;	
			}
			ans[len / 2 + 1] = getNxtOdd();
			// cout << n / res / 2 + 1 << endl << ans[n / res / 2 + 1] << endl;
			for (int j = 1; j <= len; j++) {
				cout << ans[j];
			}
			cout << " ";
		}

	}
	cout << endl;
	return 0;
}