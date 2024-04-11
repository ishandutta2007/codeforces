#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

pair<int, int> calc(int n, vector<int> &pos) {
	pair<int, int> best = { -1, -1 };
	for (int k = 1; k < n; k++) {
		int cnt = 0;
		int cur = 0;
		vector<int> curpos;
		for (int i = 0; i < n - 1; i++) {
			if (cur == k) {
				cur = 0;
			}
			else {
				curpos.push_back(i);
				cur++;
				cnt++;
			}
		}
		int can = cnt - k;
		pair<int, int> tmp = { can, k };
		if (tmp > best) {
			best = tmp;
			pos = curpos;
		}
	}
	return best;
}

int n;
int state[1005] = {};

vector<int> work(vector<int> pos) {
	int k = pos.size();
	cout << k << " ";
	for (const auto &i : pos) cout << 1 + i << " "; cout << endl;
	fflush(stdout);
	int x;
	cin >> x;
	--x;
	vector<int> res;
	for (int i = 0; i < k; i++)
		res.push_back((x + i) % n);
	return res;
}

void upd(vector<int> pos, int to) {
	for (const auto &i : pos) state[i] = to;
}
int potent(const vector<int> &pos) {
	int sum = 0;
	for (const auto &i : pos) sum += state[i];
	return sum;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	/*
	while (1) {
		int nn;
		cin >> nn;
		auto p = calc(nn);
		cout << p.first << " " << p.second << endl;
	}
	*/
	cin >> n;
	if (n <= 3) {
		cout << 0 << endl;
		fflush(stdout);
		return 0;
	}
	vector<int> pos;
	int k = calc(n, pos).second + 1;

	while (potent(pos) <= pos.size() - k) {
		vector<int> can;
		for (const auto &i : pos) {
			if (state[i] == 0) {
				can.push_back(i);
				if (can.size() == k) break;
			}
		}
		vector<int> opp = work(can);
		upd(can, 1);
		upd(opp, 0);
	}
	cout << 0 << endl;
	fflush(stdout);
}