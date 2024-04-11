#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int query(string s, int a, int b) {
	printf("%s %d %d\n", s.c_str(), a + 1, b + 1);
	fflush(stdout);
	int r;
	scanf("%d", &r);
	return r;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	int and01 = query("and", 0, 1);
	int or01 = query("or", 0, 1);
	int and02 = query("and", 0, 2);
	int or02 = query("or", 0, 2);
	int and12 = query("and", 1, 2);
	int or12 = query("or", 1, 2);
	vector<int> a(n);
	for (int bit = 0; bit < 30; ++bit) {
		int count = 0;
		for (int v0 = 0; v0 < 2; ++v0) {
			for (int v1 = 0; v1 < 2; ++v1) {
				for (int v2 = 0; v2 < 2; ++v2) {
					if ((v0 & v1) != (and01 >> bit) % 2) continue;
					if ((v0 | v1) != (or01 >> bit) % 2) continue;
					if ((v0 & v2) != (and02 >> bit) % 2) continue;
					if ((v0 | v2) != (or02 >> bit) % 2) continue;
					if ((v1 & v2) != (and12 >> bit) % 2) continue;
					if ((v1 | v2) != (or12 >> bit) % 2) continue;
					++count;
					if (v0) a[0] |= (1 << bit);
					if (v1) a[1] |= (1 << bit);
					if (v2) a[2] |= (1 << bit);
				}
			}
		}
		assert(count == 1);
	}
	for (int i = 3; i < n; ++i) {
		int and0i = query("and", 0, i);
		int or0i = query("or", 0, i);
		a[i] = (a[0] ^ and0i ^ or0i);
	}
	sort(a.begin(), a.end());
	printf("finish %d\n", a[m - 1]);
	fflush(stdout);
	return 0;
}