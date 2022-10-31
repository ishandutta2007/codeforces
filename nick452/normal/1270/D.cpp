#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int l, n;
	cin >> l >> n;
	++n;
	map<int, int> count;
	for (int i = 0; i < n; ++i) {
		printf("?");
		for (int j = 0; j < n; ++j) {
			if (i != j) {
				printf(" %d", j + 1);
			}
		}
		printf("\n");
		fflush(stdout);
		int pos;
		int a_pos;
		cin >> pos >> a_pos;
		++count[a_pos];
	}
	printf("! %d\n", (--count.end())->second);
	return 0;
}