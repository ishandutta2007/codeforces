#include <bits/stdc++.h>

#ifdef __WIN32
#define LLFORMAT "I64"
#else
#define LLFORMAT "ll"
#endif

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n;
	double s;
	scanf("%d%lf", &n, &s);
	vector<int> deg(n);
	for (int i = 1; i < n; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		++deg[x - 1];
		++deg[y - 1];
	}
	if(n == 2) {
		cout << s << endl;
		return 0;
	}
	int cnt = 0;
	for (int u = 0; u < n; ++u) if(deg[u] == 1) ++cnt;
	double ans = s / (1.0 * cnt) * 2;
	printf("%.12f\n", ans);
	return 0;
}