#include <bits/stdc++.h>

int N;
int A[110000];
std::vector <std::pair <int, int>> vec;

void op (int l, int r) {
	vec.push_back (std::make_pair (l, r));
	A[l] = !A[l]; A[l + r >> 1] = !A[l + r >> 1]; A[r] = !A[r];
}

void rop (int l, int r) {
	op (N + 1 - r, N + 1 - l);
}

int main () {
	scanf ("%d", &N); for (int i = 1; i <= N; ++i) scanf ("%d", &A[i]);
	int l = 1, r = N;
	while (l + 6 <= r && A[l] == 0) ++l;
	while (l + 6 <= r && A[r] == 0) --r;
	while (l + 6 <= r) {
		if (A[l] == 1 && A[l + 1] == 0 && A[l + 2] == 0) op (l, l + 6);
		else if (A[l] == 1 && A[l + 1] == 0 && A[l + 2] == 1) op (l, l + 4);
		else if (A[l] == 1 && A[l + 1] == 1 && A[l + 2] == 1) op (l, l + 2);
		else if (A[r] == 1 && A[r - 1] == 0 && A[r - 2] == 0) op (r - 6, r);
		else if (A[r] == 1 && A[r - 1] == 0 && A[r - 2] == 1) op (r - 4, r);
		else if (A[r] == 1 && A[r - 1] == 1 && A[r - 2] == 1) op (r - 2, r);
		else if ((l + r) % 2 == 0) op (l, r), op (l + 1, r - 1);
		else op (l, r - 1), op (l + 1, r);
		while (l + 6 <= r && A[l] == 0) ++l;
		while (l + 6 <= r && A[r] == 0) --r; 
	}
	if (A[l + 5] == 1) op (l + 3, l + 5);
	if (A[l + 4] == 1) op (l + 2, l + 4);
	if (A[l + 3] == 1) op (l + 1, l + 3);
	if (A[l] + A[l + 1] + A[l + 2] >= 2) op (l, l + 2);
	if (A[l] + A[l + 1] + A[l + 2] == 1) {
		while (A[l] == 0) ++l;
		if (N >= 8 && l == 3) {
			op (1, 7); op (2, 8); op (1, 3); op (4, 6); op (6, 8);
		} else if (N >= 8 && l == N - 2) {
			rop (1, 7); rop (2, 8); rop (1, 3); rop (4, 6); rop (6, 8);
		} else {
			if (l - 3 < 1) {
				if (l + 3 <= N) op (l, l + 2), op (l + 1, l + 3), l += 3;
				else return puts ("NO"), 0;
			}
			if (l + 3 > N) {
				if (l - 3 >= 1) op (l - 2, l), op (l - 3, l - 1), l -= 3;
				else return puts ("NO"), 0;
			}
			if (l - 3 >= 1 && l + 3 <= N) {
				op (l - 1, l + 1); op (l - 3, l - 1); op (l + 1, l + 3); op (l - 3, l + 3); op (l - 2, l + 2);
			} else return puts ("NO"), 0;
		}
	}
	for (int i = 1; i <= N; ++i) assert (A[i] == 0);
	puts ("YES");
	printf ("%d\n", (int) vec.size ());
	for (auto it : vec) {
		printf ("%d %d %d\n", it.first, it.first + it.second >> 1, it.second);
	}
}