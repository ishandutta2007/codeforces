#include <bits/stdc++.h>

int ri() {
	int n;
	scanf("%d", &n);
	return n;
}

int main() {
	int n = ri();
	int m = ri();
	int64_t score[n];
	memset(score, 0, sizeof(score));
	for (int i = 0; i < m; i++) {
		int a = ri() - 1;
		int b = ri() - 1;
		int c = ri();
		score[a] += c;
		score[b] -= c;
	}
	struct Res {
		int minus;
		int plus;
		int64_t val;
	};
	std::vector<Res> res;
	std::vector<int> que;
	for (int i = 0; i < n; i++) {
		if (score[i] > 0) {
			while (score[i] && que.size() && score[que.back()] < 0) {
				int64_t pay = std::min(score[i], -score[que.back()]);
				score[i] -= pay;
				res.push_back({que.back(), i, pay});
				if (!(score[que.back()] += pay)) que.pop_back();
			}
			if (score[i]) que.push_back(i);
		} else if (score[i] < 0) {
			while (score[i] && que.size() && score[que.back()] > 0) {
				int64_t pay = std::min(-score[i], score[que.back()]);
				score[i] += pay;
				res.push_back({i, que.back(), pay});
				if (!(score[que.back()] -= pay)) que.pop_back();
			}
			if (score[i]) que.push_back(i);
		}
	}
	assert(!que.size());
	std::cout << res.size() << std::endl;
	for (auto i : res) std::cout << i.plus + 1 << " " << i.minus + 1 << " " << i.val << std::endl;
	
	return 0;
}