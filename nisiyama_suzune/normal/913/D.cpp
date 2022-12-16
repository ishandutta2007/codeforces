#include <bits/stdc++.h>

int N, TT;
int A[210000], T[210000];

bool eval (int m) {
	std::vector <int> tim;
	for (int i = 0; i < N; ++i) 
		if (m <= A[i]) tim.push_back (T[i]);
	std::sort (tim.begin (), tim.end ());
	if (tim.size () < m) return false;
	int k = 0;
	for (int i = 0; i < m; ++i) {
		k += tim[i];
		if (k > TT) return false;
	}
	return true;
}

void output (int m) {
	std::vector <std::pair <int, int>> tim;
	for (int i = 0; i < N; ++i) 
		if (m <= A[i]) tim.push_back ({T[i], i});
	std::sort (tim.begin (), tim.end ());
	for (int i = 0; i < m; ++i) {
		printf ("%d%c", tim[i].second + 1, " \n"[i == m - 1]);
	}
}

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N >> TT;
	for (int i = 0; i < N; ++i)
		std::cin >> A[i] >> T[i];
	int l = 0, r = N, ans = -1;
	while (l <= r) {
		int m = (l + r) / 2;
		if (eval (m)) {
			ans = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	printf ("%d\n%d\n", ans, ans);
	output (ans);
}