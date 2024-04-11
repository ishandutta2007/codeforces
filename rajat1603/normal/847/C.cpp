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

const int max_N = 3e5 + 10;
int cnt[max_N];
char out[max_N * 3];

void construct(int depth, int &idx);

int main()
{
	fast_cin();
	int N; ll K;
	cin >> N >> K;

	ll res = 0;
	int used = 0;
	for (ll i = 0; i < N && res + i <= K; ++i) {
		res += i;
		++used;
		cnt[i] = 1;
	}


	if (used == N && res < K) {
		cout << "Impossible" << endl;
		return 0;
	}

	while(res < K) {
		ll M = min(K - res, ll(N - 1));
		cnt[M]++;
		used++;
		res += M;
	}


	while(used < N) {
		cnt[0]++;
		++used;
	}

	if (used > N) {
		cout << "Impossible" << endl;
	}

	int idx = 0;
	construct(0, idx);
	out[idx] = 0;

	cout << out << endl;
}

void construct(int depth, int &idx)
{
	if (cnt[depth] > 0) {
		out[idx++] = '(';
		construct(depth + 1, idx);
		out[idx++] = ')';
	}
	for (int i = 1; i < cnt[depth]; ++i) {
		out[idx++] = '(';
		out[idx++] = ')';
	}
}