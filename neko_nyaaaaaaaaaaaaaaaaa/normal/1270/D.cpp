#include <bits/stdc++.h>
using namespace std;

pair<int, int> ask(vector<int> que) {
	cout << "? ";
	for (int i: que) cout << i << ' ';
		cout << '\n';

	int pos, val; cin >> pos >> val;
	return make_pair(pos, val);
}

vector<int> a(502, -1);

bool cmp(int x, int y) {
	return a[x] < a[y];
}

signed main() {
	//ios::sync_with_stdio(0); cin.tie(0);

	int n, k; cin >> n >> k;
	if (k == 1) {
		cout << "! 1" << endl;
		exit(0);
	}
	vector<int> que;
	for (int i = 1; i <= k; i++) {
		que.push_back(i);
	}

	for (int i = k; i <= n; i++) {
		auto [u, v] = ask(que);
		a[u] = v;

		for (int j = 0; j < k; j++) {
			if (que[j] == u) {
				que[j] = i+1;
				break;
			}
		}
	}

	que.clear();
	vector<int> unk;
	for (int i = 1; i <= n; i++) {
		if (a[i] == -1) {
			unk.push_back(i);
		} else {
			que.push_back(i);
		}
	}
	sort(que.begin(), que.end(), cmp);

	// if we recovered k numbers, just ask
	// if we have not recovered k numbers
	// along with every cyclic subarray of que

	if (que.size() >= k) {
		while (que.size() > k) {
			que.pop_back();
		}
		auto [u, v] = ask(que);
		for (int i = 0; i < k; i++) {
			if (u == que[i]) {
				cout << "! " << i+1 << endl;
				exit(0);
			}
		}
	} else {
		while (que.size() > 2) que.pop_back();
		int g = k - que.size();
		int f = unk.size();

		int m = 1;
		for (int i = 0; i < f; i++) {
			vector<int> que2 = que;
			for (int j = i; que2.size() < k; j = (j + 1) % f){
				que2.push_back(unk[j]);
			}
			auto [u, v] = ask(que2);
			if (u == que[1]) {
				m++;
			}
		}
		cout << "! " << m << '\n';
	}

	return 0;
}