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
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-5;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;


void Solve() {
	cin >> N;
	vector<int>v(N);
	for (auto &i : v) {
		cin >> i;
		i--;
	}
	vector<pair<int, int>>ans;
	vector<int>used(N);
	vector<vector<int>>box;
	for (int i = 0; i < N; i++) {
		if (used[i])continue;
		if (v[i] == i)continue;
		used[i] = 1;
		vector<int>w;
		w.push_back(i);
		int nx = v[i];
		while (nx != i) {
			used[nx] = 1;
			w.push_back(nx);
			nx = v[nx];
		}
		box.push_back(w);
	}
	for (int i = 0; i + 1 < box.size(); i += 2) {
		int a = box[i + 0].size();
		int b = box[i + 1].size();
		int aidx = 0;
		int bidx = 0;
		ans.push_back({ box[i + 0][0], box[i + 1][0] });
		while (a && b) {
			if (a > b) {
				aidx++;
				aidx %= box[i + 0].size();
				a--;
				ans.push_back({ box[i + 0][aidx],box[i + 1][0] });
			}
			else {
				bidx++;
				bidx %= box[i + 1].size();
				b--;
				ans.push_back({ box[i + 0][0],box[i + 1][bidx] });
			}
		}
	}
	if (box.size() & 1) {
		if (box.back().size() == 2) {
			vector<int>flag(N);
			for (auto i : box.back()) {
				flag[i] = 1;
			}
			int amari = -1;
			for (int i = 0; i < N; i++) {
				if (flag[i] == 0) {
					amari = i;
				}
			}
			ans.push_back({box.back()[0], amari });
			ans.push_back({box.back()[1], amari });
			ans.push_back({box.back()[0], amari });
		}
		else {
			ans.push_back({ box.back()[0],box.back()[1] });
			for (int i = 2; i < box.back().size(); i++) {
				ans.push_back({ box.back()[1],box.back()[i] });
			}
			ans.push_back({ box.back()[0],box.back()[2] });
			ans.push_back({ box.back()[0],box.back()[1] });
		}
	}
	cout << ans.size() << endl;
	for (auto i : ans) {
		cout << i.first + 1 << " " << i.second + 1 << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	//cin >> T;
	while (T--) {
		Solve();
	}
}