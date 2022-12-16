#include <bits/stdc++.h>

int delta[4][110000];
int N, X, Y;
int sofa[110000][2][2];
int cnt[110000][4];
int cntt[4];

int main () {
	std::ios::sync_with_stdio (0);
	std::cin.tie (0);
	std::cout.tie (0);
	std::cin >> N >> X >> Y;
	for (int i = 0; i < N; ++i) {
		std::cin >> sofa[i][0][0] >> sofa[i][0][1] >> sofa[i][1][0] >> sofa[i][1][1];
	}
	for (int i = 0; i < N; ++i) {
		delta[0][i] = std::min (sofa[i][0][0], sofa[i][1][0]);
		delta[1][i] = -std::max (sofa[i][0][0], sofa[i][1][0]);
		delta[2][i] = std::min (sofa[i][0][1], sofa[i][1][1]);
		delta[3][i] = -std::max (sofa[i][0][1], sofa[i][1][1]);
	}
	for (int i = 0; i < 4; ++i)
		std::sort (delta[i], delta[i] + N);
	for (int i = 0; i < N; ++i) {
		cnt[i][0] = std::lower_bound (delta[0], delta[0] + N, std::max (sofa[i][0][0], sofa[i][1][0])) - delta[0] - (sofa[i][0][0] != sofa[i][1][0]);
		cnt[i][1] = std::lower_bound (delta[1], delta[1] + N, -std::min (sofa[i][0][0], sofa[i][1][0])) - delta[1] - (sofa[i][0][0] != sofa[i][1][0]);
		cnt[i][2] = std::lower_bound (delta[2], delta[2] + N, std::max (sofa[i][0][1], sofa[i][1][1])) - delta[2] - (sofa[i][0][1] != sofa[i][1][1]);
		cnt[i][3] = std::lower_bound (delta[3], delta[3] + N, -std::min (sofa[i][0][1], sofa[i][1][1])) - delta[3] - (sofa[i][0][1] != sofa[i][1][1]);
	}
	for (int i = 0; i < 4; ++i)
		std::cin >> cntt[i];
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < 4; ++j)
			if (cntt[j] != cnt[i][j]) goto nextTry;
		std::cout << i + 1 << std::endl;
		return 0;
nextTry:;
	}
	std::cout << -1 << std::endl;
	return 0;
}