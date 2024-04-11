#include <bits/stdc++.h>

using namespace std;

#define int long long
#define sz(x) ((int) (x).size())
#define left isodjfiosd
#define right sjdfiosdjoisd

const int maxn = 1e5 + 42;

int n, k;
int a[maxn];
int left[maxn];
int right[maxn];
int mid[maxn];
int sum = 0;
set<pair<int, int>> increase; // new - old, pos
set<pair<int, int>> decrease; // new - old, pos

int f(int pos, int val) {
	return val * (a[pos] - val * val);
}

void add(int pos) {
	sum += mid[pos];
	if (mid[pos] < right[pos]) {
		increase.insert({f(pos, mid[pos] + 1) - f(pos, mid[pos]), pos});
	}
	if (mid[pos] > left[pos]) {
		decrease.insert({f(pos, mid[pos] - 1) - f(pos, mid[pos]), pos});
	}
}

void del(int pos) {
	sum -= mid[pos];
	if (mid[pos] < right[pos]) {
		increase.erase({f(pos, mid[pos] + 1) - f(pos, mid[pos]), pos});
	}
	if (mid[pos] > left[pos]) {
		decrease.erase({f(pos, mid[pos] - 1) - f(pos, mid[pos]), pos});
	}
}


signed main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	
	cin >> n >> k;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		left[i] = 0;
		right[i] = a[i];
		mid[i] = a[i] / 2;
		add(i);
	}
	
	while (!increase.empty() || !decrease.empty()) {
		if (sum == k) {
			if (!increase.empty()) {
				int pos = increase.begin()->second;
				del(pos);
				mid[pos] += 1;
				add(pos);
			} else {
				int pos = decrease.begin()->second;
				del(pos);
				mid[pos] -= 1;
				add(pos);
			}
		} else if (sum < k) {
			assert(!increase.empty());
			int pos = increase.rbegin()->second;
			del(pos);
			left[pos] = mid[pos] + 1;
			mid[pos] = (left[pos] + right[pos]) / 2;
			add(pos);
		} else if (sum > k) {
			assert(!decrease.empty());
			int pos = decrease.rbegin()->second;
			del(pos);
			right[pos] = mid[pos] - 1;
			mid[pos] = (left[pos] + right[pos]) / 2;
			add(pos);
		}
	}
	
	for (int i = 0; i < n; ++i) {
		cout << mid[i] << ' ';
	}
	cout << '\n';
	
}