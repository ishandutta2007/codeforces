#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<string>v(N);
	vector<string>w(N);
	for (auto &i : v)cin >> i;
	for (auto &i : w)cin >> i;
	vector<int>l(N, -1);
	vector<int>r(N, -1);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			if (v[i][j] != w[i][j]) {
				if (l[i] == -1)l[i] = j;
				r[i] = j;
			}
		}
	}
	int index = 0;
	for (int i = 0; i < N; i++) {
		if (l[i] == -1)continue;
		L = l[i];
		R = r[i];
		index = i;
		break;
	}
	int lft = L;
	int rht = v[index].size() - r[index] - 1;
	for (int i = 0; i < N; i++) {
		if (l[i] == -1)continue;
		if (r[i] - l[i] != R - L) {
			cout << "NO\n";
			return 0;
		}
		for (int j = l[i], k = L; j <= r[i]; j++, k++) {
			if (w[index][k] != w[i][j] || v[index][k] != v[i][j]) {
				cout << "NO\n";
				return 0;
			}
		}
		lft = min(lft, l[i]);
		rht = min(rht, (int)v[i].size() - r[i] - 1);
	}
	for (int i = 0; i < lft; i++) {
		char box = v[index][l[index] - i - 1];
		bool flag = true;
		for (int j = index + 1; j < N; j++) {
			if (l[j] == -1)continue;
			if (v[j][l[j] - i - 1] != box) {
				flag = false;
				break;
			}
		}
		if (flag) {
			L--;
		}
		else {
			break;
		}
	}
	for (int i = 0; i < rht; i++) {
		char box = v[index][r[index] + i + 1];
		bool flag = true;
		for (int j = index + 1; j < N; j++) {
			if (l[j] == -1)continue;
			if (v[j][r[j] + i + 1] != box) {
				flag = false;
				break;
			}
		}
		if (flag) {
			R++;
		}
		else {
			break;
		}
	}
	string sh;
	for (int i = L; i <= R; i++)sh.push_back(v[index][i]);
	//cout << sh << endl;
	for (int i = 0; i < N; i++) {
		if (l[i] == -1) {
			auto box = v[i].find(sh);
			if (box >= 0 && box < v[i].size()) {
				//cout << v[i].find(sh) << endl;
				cout << "NO\n";
				return 0;
			}
			continue;
		}
		if (v[i].find(sh) != L - l[index] + l[i]) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	cout << sh << endl;
	for (int i = L; i <= R; i++) {
		cout << w[index][i];
	}
	cout << endl;
	return 0;
}