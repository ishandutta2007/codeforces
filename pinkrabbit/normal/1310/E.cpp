#include <cstdio>
#include <algorithm>
#include <vector>

const int Mod = 998244353;
const int MN = 2025;

inline void Add(int &x, int y) { x -= (x += y) >= Mod ? Mod : 0; }

int N, K;

void Solve1() {
	static int Arr[MN], Ans;
	Arr[0] = 1;
	for (int i = 1; i <= N; ++i)
		for (int j = i; j <= N; ++j)
			Add(Arr[j], Arr[j - i]);
	for (int i = 1; i <= N; ++i) Add(Ans, Arr[i]);
	printf("%d\n", Ans);
}

int f[MN][MN], g[MN][MN];
void Solve2() {
	int Ans = N;
	for (int i = 1; i <= N; ++i) f[i][i] = 1;
	for (int i = 2, s = 3; s <= N; s += ++i) {
		for (int j = N / (s - i); j > 1; --j)
			for (int k = (s - i) * j; k <= N; ++k)
				Add(f[j - 1][k], f[j][k]);
		for (int j = 1; s * j <= N; ++j)
			for (int k = s * j; k <= N; ++k)
				Add(Ans, g[j][k] = f[j][k - i * j]);
		std::swap(f, g);
	}
	printf("%d\n", Ans);
}

int Ans, stk[MN], tp;
std::vector<int> arr1, arr2;
inline bool chk() {
	arr1.clear();
	for (int i = 1; i <= tp; ++i) arr1.push_back(stk[i]);
	for (int t = 1; t < K; ++t) {
		int sum = 0;
		for (int x : arr1) sum += x;
		if (sum > N) return 0;
		arr2.clear(); int i = arr1.size();
		for (int x : arr1) { while (x--) arr2.push_back(i); --i; }
		std::reverse(arr2.begin(), arr2.end());
		std::swap(arr1, arr2);
	}
	int sum = 0;
	for (int x : arr1) sum += x;
	if (sum > N) return 0;
	return ++Ans, 1;
}
bool DFS(int sum, int mx) {
	if (sum && !chk()) return 0;
	for (int i = mx; i <= N - sum; ++i) {
		stk[++tp] = i;
		bool d = DFS(sum + i, i);
		--tp;
		if (!d) break;
	}
	return 1;
}
void Solve3() {
	DFS(0, 1);
	printf("%d\n", Ans);
}

int main() {
	scanf("%d%d", &N, &K);
	if (K == 1) Solve1();
	else if (K == 2) Solve2();
	else if (K >= 9) puts("1");
	else Solve3();
	return 0;
}