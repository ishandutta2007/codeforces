#include <bits/stdc++.h>
using namespace std;

int N, pt[205], blen = 1000000000;
long long a[205];
string ba, bb;

int main() {
	scanf("%d", &N);
	int tN = N;
	for (int R = 3; R <= 9; R++) {
		N = tN;
		for (int i = 0; i < 200; i++) a[i] = 1;
		for (int i = 0; i < R; i++) {
			for (int j = 1; j < 200; j++) a[j] += a[j - 1];
		}
		memset(pt, 0, sizeof(pt));
		int mx = 0;
		while (N > 0) {
			int pos = upper_bound(a, a + 200, N) - a - 1;
			mx = max(mx, pos);
			N -= a[pos];
			pt[pos]++;
		}
		string a, b;
		int len = 0;
		for (int i = 0; i <= mx; i++) {
			for (int j = 0; j < R; j++) a += (char)('a' + j);
			for (int j = 0; j < pt[i]; j++) a += (char)('a' + R);
			len += R + pt[i];
		}
		for (int j = 0; j <= R; j++) b += (char)('a' + j);
		if (len < blen) {
			blen = len;
			ba = a;
			bb = b;
		}
	}
	printf("%s %s\n", ba.c_str(), bb.c_str());
}