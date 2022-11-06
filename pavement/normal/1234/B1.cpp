#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, k, id;
	scanf("%d%d", &n, &k);
	deque<int> q;
	unordered_set<int> on;
	while (n--) {
		scanf("%d", &id);
		if (on.count(id)) continue;
		if (q.size() < k) {
			q.push_back(id);
			on.insert(id);
		} else {
			int tmp = q.front();
			on.erase(tmp);
			q.pop_front();
			q.push_back(id);
			on.insert(id);
		}
	}
	printf("%d\n", q.size());
	while (!q.empty()) {
		printf("%d ", q.back());
		q.pop_back();
	}
}