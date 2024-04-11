#include <bits/stdc++.h>
using namespace std;

int N, cur;

vector<int> div1, div2;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int c, d;
		scanf("%d%d", &c, &d);
		if (d == 1) div1.push_back(cur);
		else div2.push_back(cur);
		cur += c;
	}
	sort(div1.begin(), div1.end());
	sort(div2.begin(), div2.end());
	if (div2.size() == 0) {
		printf("Infinity\n");
		return 0;
	}
	if (div1.size() > 0 && div1[0] <= div2.back()) {
		printf("Impossible\n");
		return 0;
	}
	int diff = 1899 - div2.back();
	cur += diff;
	printf("%d\n", cur);
}