#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <cassert>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;

#define all(v) v.begin(), v.end()
#define TASK "cinema"

void file() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
#endif
}

const int dd = (int)2e5 + 7;
const int INF = (int)1e9 + 7;

int A[dd], B[dd], ANS[dd], ans[dd];

int main() {
	file();
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", &B[i]);
	}
	set<pair<int, int> > Sa, Sb;
	for (int i = 0; i < n; ++i) {
		Sa.insert({ A[i], i });
	}
	for (int i = 0; i < m; ++i) {
		Sb.insert({ B[i],i });
	}
	int k = 0, C = 0, U = 0;
	vector<pair<int, int> > D;
	while ((int)Sb.size()) {
		for (auto it : Sb) {
			auto it2 = Sa.lower_bound({ it.first, 0 });
			if (it2 == Sa.end()) {
				break;
			}
			if (it2->first == it.first) {
				ANS[it2->second] = it.second + 1;
				++C;
				U += k;
				ans[it.second] = k;
				D.push_back(it);
				Sa.erase(it2);
			}
		}

		for (auto it : D) {
			Sb.erase(it);
		}
		D = vector<pair<int, int> >(0);
		for (auto it : Sb) {
			pair<int, int> nw = { (it.first + 1) / 2, it.second };
			if (nw.first != it.first) {
				D.push_back(nw);
			}
		}
		Sb.clear();
		for (auto it : D) {
			Sb.insert(it);
		}
		D = vector<pair<int, int> >(0);
		++k;
	}
	printf("%d %d\n", C, U);
	for (int i = 0; i < m; ++i) {
		printf("%d ", ans[i]);
	}
	puts("");
	for (int i = 0; i < n; ++i) {
		printf("%d ", ANS[i]);
	}
	return 0;
}