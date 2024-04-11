#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:256000000")
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <bitset>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <numeric>
#include <queue>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <random>

using namespace std;

typedef long long ll;
typedef long double ld;

#define TASK "lasers"

int solve();

int main() {
#ifdef Dron37_21
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#else
	//freopen(TASK".in", "r", stdin), freopen(TASK".out", "w", stdout);
#endif
	return solve();
}

const int dd = (int)2e5 + 7;
const int inf = (int)1e9 + 7;

pair<string, int> A[dd], B[dd], C[dd];
int iC, n;

bool pal(string s) {
	for (int i = 0; i < n / 2; ++i)
		if (s[i] != s[n - i - 1])
			return false;
	return true;
}

int solve() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k;
	cin >> k >> n;
	for (int i = 0; i < k; ++i) {
		cin >> A[i].first >> A[i].second;

		if (pal(A[i].first)) {
			C[iC++] = A[i];
			A[i].first = "";
			A[i].second = 0;
			continue;
		}

		A[i].second *= -1;
		B[i] = A[i];
		reverse(B[i].first.begin(), B[i].first.end());
	}
	sort(A, A + k);
	sort(B, B + k);

	int r = 0, ans = 0;
	for (int i = 0; i < k; ++i) {
		while (r < k && B[r].first < A[i].first)
			++r;
		if (r < k && A[i].first == B[r].first) {
			if (-A[i].second - B[r].second > 0)
				ans += -A[i].second - B[r].second;
			++r;
		}
	}
	ans /= 2;

	sort(C, C + iC);
	int mx = 0;
	for (int i = iC - 1; i >= 0; --i) {
		if (i && C[i].first == C[i - 1].first && C[i].second + C[i - 1].second > 0) {
			ans += C[i].second + C[i - 1].second;
			--i;
		} else
			mx = max(mx, C[i].second);
	}

	int mxd = 0;

	for (int i = iC - 1; i >= 0; --i) {
		if (i && C[i].first == C[i - 1].first && C[i].second + C[i - 1].second > 0) {
			mxd = max(mxd, -C[i - 1].second - mx);
			--i;
		} else
			mx = max(mx, C[i].second);
	}
	
	printf("%d", ans + mx + mxd);
	return 0;
}