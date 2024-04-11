#pragma warning(disable:4996)

#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <string.h>
#include <vector>

#define mp make_pair
#define ni(n) scanf("%d", &(n))
#define nii(m, n) scanf("%d%d", &(n), &(m))

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

pii a, b, c;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int x, y;
	nii(x, y); a = mp(x, y);
	nii(x, y); b = mp(x, y);
	nii(x, y); c = mp(x, y);

	for (int i = 0; i < 3; i++) {
		if (a.first == b.first) {
			if (a.first == c.first) {
				puts("1"); return 0;
			}
			int _m = min(a.second, b.second);
			int _M = max(a.second, b.second);
			if (_m<c.second && _M>c.second) {
				puts("3"); return 0;
			}
			else {
				puts("2"); return 0;
			}
		}
		swap(a.first, a.second);
		swap(b.first, b.second);
		swap(c.first, c.second);
		if (a.first == b.first) {
			if (a.first == c.first) {
				puts("1"); return 0;
			}
			int _m = min(a.second, b.second);
			int _M = max(a.second, b.second);
			if (_m<c.second && _M>c.second) {
				puts("3"); return 0;
			}
			else {
				puts("2"); return 0;
			}
		}

		swap(a.first, a.second);
		swap(b.first, b.second);
		swap(c.first, c.second);

		swap(a, b);
		swap(b, c);
	}
	puts("3"); return 0;

	return 0;
}