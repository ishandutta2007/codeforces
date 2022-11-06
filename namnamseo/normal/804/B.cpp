#include <iostream>
#include <cstring>
using namespace std;

const int maxn = int(1e6) + 10;
const int mod = int(1e9) + 7;
char s[maxn];
int n;

int main() {
	cin >> (s+1);
	n = strlen(s+1);

	int ans = 0;
	int bb = 0;
	for (int i=n; 1<=i; --i) {
		if (s[i] == 'b') {
			++bb;
			if (bb == mod) bb = 0;
		}
		else {
			ans += bb;
			if (ans >= mod) ans -= mod;
			bb *= 2;
			if (bb >= mod) bb -= mod;
		}
	}

	printf("%d\n", ans);

	return 0;
}