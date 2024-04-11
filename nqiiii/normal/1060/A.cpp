#include <bits/stdc++.h>
using namespace std;
int n, cnt;
int main() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		char c = getchar();
		while (!isgraph(c)) c = getchar();
		cnt += c == '8';
	}
	printf("%d", min(n / 11, cnt));
}