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
#define TASK "twopaths"

const int dd = (int)2e5 + 7;
const int INF = (int)1e9 + 7;

void file() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin); freopen(TASK".out", "w", stdout);
#endif
}

ll A[dd];
vector<int> P0;

int main() {
	file();
	ll n, k, x, cur = 0, cur0 = 0;
	scanf("%I64d%I64d%I64d", &n, &k, &x);
	for (int i = 0; i < n; ++i) {
		scanf("%I64d", &A[i]);
		if (A[i] < 0) {
			++cur;
		}
		if (A[i] == 0) {
			++cur0;
			P0.push_back(i);
		}
	}
	if (cur0 > k) {
		for (int i = 0; i < n; ++i) {
			printf("%I64d ", A[i]);
		}
		return 0;
	}
	for (auto i : P0) {
		A[i] = x;
		--k;
	}
	if ((cur & 1) == 0) {
		if ((int)P0.size()) {
			A[P0[0]] = -x;
		} else {
			int G = INF, pos;
			for (int i = 0; i < n; ++i) {
				if (abs(A[i]) < G) {
					G = abs(A[i]), pos = i;
				}
			}
			if (k * x > abs(A[pos])) {
				ll k1= abs(A[pos]) / x + 1;
				k -= k1;
				if (A[pos] > 0) {
					A[pos] -= k1 * x;
				} else {
					A[pos] += k1 * x;
				}
			} else {
				if (A[pos] > 0) {
					A[pos] -= k * x;
				} else {
					A[pos] += k * x;
				}
				for (int i = 0; i < n; ++i) {
					printf("%I64d ", A[i]);
				}
				return 0;
			}
		}
	}
	set<pair<ll, int> > S;
	for (int i = 0; i < n; ++i) {
		S.insert({ abs(A[i]), i });
	}
	for (int i = 0; i < k; ++i) {
		int pos = (*S.begin()).second;
		S.erase(S.begin());
		if (A[pos] < 0) {
			A[pos] -= x;
		} else {
			A[pos] += x;
		}
		S.insert({ abs(A[pos]), pos });
	}
	for (int i = 0; i < n; ++i) {
		printf("%I64d ", A[i]);
	}
	return 0;
}