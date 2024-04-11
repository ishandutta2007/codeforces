#include <bits/stdc++.h>

int N;
int a[2][2];
std::string str1, str2;

int main () {
	std::ios::sync_with_stdio (0);
	std::cin >> N >> str1 >> str2;
	for (int i = 0; i < N; ++i) ++a[str1[i] - '0'][str2[i] - '0'];
	std::cout << 1LL * a[0][0] * a[1][0] + 1LL * a[0][0] * a[1][1] +
		1LL * a[0][1] * a[1][0] << "\n";
}