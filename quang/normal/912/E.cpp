#include <bits/stdc++.h>

using namespace std;

const long long INF = (long long)1e18 + 10;

int n;
vector<int> a;
vector<long long> res[2];

void gen(int id, long long u, int now, int t) {
	if (id == t) {
		res[now].push_back(u);
		return;
	}
	while (u <= 1e18) {
		gen(id + 1, u, now, t);
		if (INF / u >= a[id]) {
			u *= a[id];
		} else {
			break;
		}
	}
}

long long get(long long u) {
	int id = (res[0].size() > res[1].size()) ? 1 : 0;
	long long cnt = 0;
	for (int i = 0; i < res[id].size(); i++) {
		long long foo = res[id][i];
		int low = -1, high = res[id ^ 1].size();
		while (high - low > 1) {
			int mid = (low + high) >> 1;
			if ((u - 1) / foo + 1 > res[id ^ 1][mid]) {
				low = mid;
			} else {
				high = mid;
			}	
		}
		cnt += low + 1;
	}
	return cnt;
}

long long k;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int u;
		cin >> u;
		a.push_back(u);
	}
	cin >> k;
	sort(a.begin(), a.end());
	int mid = a.size() / 2;
	gen(0, 1, 0, mid);
	gen(mid, 1, 1, a.size()); 
	sort(res[1].begin(), res[1].end());
	sort(res[0].begin(), res[0].end());
	long long low = 0, high = INF;
	while (high - low > 1) {
		long long mid = (low + high) >> 1ll;
		long long foo = get(mid);
		if (foo >= k) {
			high = mid;
		} else {
			low = mid;
		}
		// cout << low << " " << high << endl;
	}
	cout << low << endl;
	// cout << get((long long)1e18 + 1) << endl;
	return 0;
}