#include <bits/stdc++.h>
using namespace std;

vector <int> all;

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		all.clear();
		while (n--) {
			int x; scanf("%d", &x);
			all.push_back(x);
		}
		sort(all.begin(), all.end()), all.resize(unique(all.begin(), all.end()) - all.begin());
		printf("%d\n", (int)all.size());
	}
	return 0;
}