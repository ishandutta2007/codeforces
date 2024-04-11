#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<int> ans;
set<int> S;

int main() {
	scanf("%d%d", &N, &M);
	long long total = 0;
	for (int i = 1; i <= N; i++) {
		long long get = (i - 1) / 2;
		if (total + get >= M) {
			long long pairsIWant = M - total;
			total = M;
			ans.push_back(i * 2 - pairsIWant * 2 - 1);
			break;
		} else {
			total += get;
			ans.push_back(i);
		}
	}
	if (total != M) {
		printf("-1\n");
	}
	else {
		int val = ans.back();
		while (ans.size() < N) {
			ans.push_back(ans.back() + val + 1);
		}
		for (int i = 0; i < ans.size(); i++) {
			if (i) printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
	}
}