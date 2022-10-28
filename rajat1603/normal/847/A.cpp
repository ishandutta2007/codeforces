#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <climits>

#include <sstream>
#include <iostream>
#include <iomanip>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

#define fast_cin() ios_base::sync_with_stdio(false)

typedef long double ld;
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int max_N = 110;
int L[max_N], R[max_N];

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i) {
		cin >> L[i] >> R[i];
	}

	int prev_end_point = 0;
	for (int i = 1; i <= N; ++i) {
		if (L[i] == 0) {
			/* a start point */
			R[prev_end_point] = i;
			L[i] = prev_end_point;
			int j;
			for (j = i; R[j]; j = R[j]) {
			}
			prev_end_point = j;
		}
	}

	for (int i = 1; i <= N; ++i) {
		cout << L[i] << ' ' << R[i] << endl;
	}
}