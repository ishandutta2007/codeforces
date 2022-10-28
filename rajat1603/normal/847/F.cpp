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

struct cand {
	int num_votes;
	int last_vote;
	int id;

	bool operator<(const cand &other) const
	{
		return tie(num_votes, other.last_vote) > tie(other.num_votes, last_vote);
	}
};

cand cnt[max_N];
int r[max_N];

int main()
{
	fast_cin();
	int N, K, m, a;
	cin >> N >> K >> m >> a;

	for (int i = 1; i <= N; ++i) {
		cnt[i].id = i;
	}

	for (int i = 1; i <= a; ++i) {
		int x;
		cin >> x;
		cnt[x].num_votes++;
		cnt[x].last_vote = i;
	}

	sort(cnt + 1, cnt + 1 + N);

	for (int i = 1; i <= N; ++i) {
		int req = 0;
		int idx = cnt[i].id;
		for (int j = i + 1; j <= K + 1; ++j) {
			req += cnt[i].num_votes + 1 - cnt[j].num_votes;
		}

		if ((cnt[i].num_votes == 0) || (K < N && req <= m - a)) {
			cand temp = {cnt[i].num_votes + m - a, m, 0};
			if (temp.num_votes > 0 && temp < cnt[K]) {
				r[idx] = 2;
			} else {
				r[idx] = 3;
			}
		} else {
			r[idx] = 1;
		}
	}

	for (int i = 1; i <= N; ++i) {
		cout << r[i] << ' ';
	}
}