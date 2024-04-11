#include <bits/stdc++.h>
using namespace std;

int N, used;
long long A[100005];
multiset<int> v;
multiset<long long> S;

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%lld", &A[i]);
	for (int i = 0; i < N; i++) S.insert(A[i]);
	while(1) {
		int cur = 0;
		for (int i = 0; i <= 60; i++) {
			if (S.find(1ll << i) != S.end()) {
				S.erase(S.find(1ll << i));
				continue;
			} else {
				cur = i - 1;
				break;
			}
		}
		if (cur == -1) break;
		v.insert(cur);
	}
	vector<int> need;
	for (multiset<long long>::iterator it = S.begin(); it != S.end(); it++) {
		int mini = -1;
		for (int i = 0; i <= 60; i++) {
			if ((1ll << i) >= *it) {
				mini = i - 1;
				break;
			}
		}
		need.push_back(mini);
		used++;
	}
	sort(need.begin(), need.end(), greater<int>());
	for (int i = 0; i < need.size(); i++) {
		if (v.size() == 0 || *v.rbegin() < need[i]) {
			printf("-1\n");
			return 0;
		}
		v.erase(--v.end());
	}
	int minans = v.size() + used, a = 0;
	for (multiset<int>::iterator it = v.begin(); it != v.end();) {
		if (*it + 1 > (int)v.size() - 1) {
			for (int i = minans - a; i <= minans; i++) {
				if (i != minans - a) printf(" ");
				printf("%d", i);
			}
			printf("\n");
			return 0;
		}
		for (int i = 0; i < *it + 1; i++) v.erase(--v.end());
		it++;
		a++;
		v.erase(v.begin());
	}
	for (int i = minans - a; i <= minans; i++) {
				if (i != minans - a) printf(" ");
				printf("%d", i);
			}
			printf("\n");
			return 0;
}