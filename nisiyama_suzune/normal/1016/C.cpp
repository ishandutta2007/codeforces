#include <bits/stdc++.h>

int N;
long long A[2][410000];

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N;
	for (int i = 0; i < N; ++i) std::cin >> A[0][i];
	for (int i = 0; i < N; ++i) std::cin >> A[1][i];
	long long ch[2] = {0, 0}, sum = 0, cur = 0;
	for (int i = 0; i < N; ++i) ch[0] += i * A[0][i];
	for (int i = 0; i < N; ++i) ch[0] += (2 * N - 1 - i) * A[1][i];
	for (int i = 0; i < N; ++i) ch[1] += i * A[1][i];
	for (int i = 0; i < N; ++i) ch[1] += (2 * N - 1 - i) * A[0][i];
	for (int i = 0; i < N; ++i) sum += A[0][i] + A[1][i];
	long long res = ch[0];
//	std::cout << ch[0] << " " << ch[1] << "\n";
	for (int i = 0, t = 0, cnt = 0; i + 1 < N; ++i, t ^= 1, cnt += 2) {
		ch[t] -= A[t ^ 1][i] * (2 * (N - i) - 1);
		ch[t ^ 1] -= A[t][i] * (2 * (N - i) - 1);
		sum -= A[t][i] + A[t ^ 1][i]; ch[t] -= sum; ch[t ^ 1] -= sum;
		cur += cnt * A[t][i] + (cnt + 1) * A[t ^ 1][i];
//		std::cout << t << " " << cur << " " << ch[t ^ 1] << " " << sum * (cnt + 2) << "\n";
		res = std::max (res, cur + ch[t ^ 1] + sum * (cnt + 2));
	}
	std::cout << res << "\n";
}