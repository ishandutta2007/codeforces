#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int XY_MAX = 105;

int N = 0;
int X[3], Y[3];
char logo[4], grid[XY_MAX][XY_MAX];

void fill(char letter, int start_row, int end_row, int start_col, int end_col) {
	for (int r = start_row; r < end_row; r++) {
		for (int c = start_col; c < end_col; c++) {
			grid[r][c] = letter;
		}
	}
}

int main() {
	strcpy(logo, "ABC");
	int area = 0;

	for (int i = 0; i < 3; i++) {
		scanf("%d %d", &X[i], &Y[i]);

		if (X[i] < Y[i]) {
			swap(X[i], Y[i]);
		}

		N = max(N, X[i]);
		area += X[i] * Y[i];
	}

	if (area != N * N) {
		puts("-1");
		return 0;
	}

	if (X[0] == N && X[1] == N && X[2] == N) {
		// Place them all horizontally
		fill(logo[0], 0, Y[0], 0, N);
		fill(logo[1], Y[0], Y[0] + Y[1], 0, N);
		fill(logo[2], Y[0] + Y[1], N, 0, N);
	} else {
		for (int i = 1; i < 3; i++) {
			if (X[i] == N) {
				swap(X[0], X[i]);
				swap(Y[0], Y[i]);
				swap(logo[0], logo[i]);
			}
		}

		// Place logo 0 horizontally at the bottom
		fill(logo[0], N - Y[0], N, 0, N);

		for (int i = 1; i < 3; i++) {
			if (Y[i] != N - Y[0]) {
				swap(X[i], Y[i]);
			}
		}

		// Both logos must have the same height
		if (Y[1] != Y[2]) {
			puts("-1");
			return 0;
		}

		// Place the other two above logo 0
		fill(logo[1], 0, Y[1], 0, X[1]);
		fill(logo[2], 0, Y[2], X[1], N);
	}

	printf("%d\n", N);

	for (int i = 0; i < N; i++) {
		puts(grid[i]);
	}

	return 0;
}