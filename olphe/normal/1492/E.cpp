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

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N >> M;
	vector<vector<int>>v(N, vector<int>(M));
	for (auto& i : v)for (auto& j : i)cin >> j;
	if (M <= 2) {
		cout << "Yes\n";
		for (auto i : v[0])cout << i << " ";
		cout << endl;
		return;
	}
	if (N <= 500) {
		int mx = 0, ii = -1, jj = -1;
		vector<int>idx;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				int dif = 0;
				for (int k = 0; k < M; k++) {
					dif += v[i][k] != v[j][k];
					if (v[i][k] != v[j][k])idx.push_back(k);
				}
				if (dif > mx) {
					mx = dif;
					ii = i, jj = j;
				}
				if (dif > 4) {
					cout << "No\n";
					return;
				}
			}
		}
		sort(idx.begin(), idx.end());
		idx.erase(unique(idx.begin(), idx.end()), idx.end());
		vector<int>dif(N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				dif[i] += v[i][j] != v[0][j];
			}
		}
		for (int I = 0; I < idx.size(); I++) {
			for (int J = I + 1; J < idx.size(); J++) {
				int i = idx[I];
				int j = idx[J];
				vector<pair<int, int>>cand;
				cand.emplace_back(-1, -1);
				for (int k = 1; k < N; k++) {
					int cdif = dif[k];
					cdif -= v[k][i] != v[0][i];
					cdif -= v[k][j] != v[0][j];
					if (cdif == 0) {

					}
					else if (cdif == 1) {
						vector<pair<int, int>>ncand;
						for (auto c : cand) {
							if (c.first == -1 && c.second == -1) {
								ncand.emplace_back(-1, v[k][j]);
								ncand.emplace_back(v[k][i], -1);
							}
							else if (c.first == -1) {
								if (c.second == v[k][j]) {
									ncand.emplace_back(-1, c.second);
								}
								else {
									ncand.emplace_back(v[k][i], c.second);
								}
							}
							else if (c.second == -1) {
								if (c.first == v[k][i]) {
									ncand.emplace_back(c.first, -1);
								}
								else {
									ncand.emplace_back(c.first, v[k][j]);
								}
							}
							else {
								if (c.first == v[k][i] || c.second == v[k][j]) {
									ncand.push_back(c);
								}
							}
						}
						cand = ncand;
						sort(cand.begin(), cand.end());
						cand.erase(unique(cand.begin(), cand.end()), cand.end());
					}
					else if (cdif == 2) {
						vector<pair<int, int>>ncand;
						for (auto c : cand) {
							if ((c.first == -1 || c.first == v[k][i]) && (c.second == -1 || c.second == v[k][j])) {
								ncand.emplace_back(v[k][i], v[k][j]);
							}
						}
						cand = ncand;
						sort(cand.begin(), cand.end());
						cand.erase(unique(cand.begin(), cand.end()), cand.end());
					}
					else {
						cand.clear();
					}
				}
				if (cand.size()) {
					auto ans = v[0];
					if (cand[0].first != -1) {
						ans[i] = cand[0].first;
					}
					if (cand[0].second != -1) {
						ans[j] = cand[0].second;
					}
					cout << "Yes\n";
					for (auto k : ans) {
						cout << k << " ";
					}
					cout << endl;
					return;
				}
			}
		}
	}
	else {
		vector<int>dif(N);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				dif[i] += v[i][j] != v[0][j];
			}
		}
		for (int i = 0; i < M; i++) {
			for (int j = i + 1; j < M; j++) {
				vector<pair<int, int>>cand;
				cand.emplace_back(-1, -1);
				for (int k = 1; k < N; k++) {
					int cdif = dif[k];
					cdif -= v[k][i] != v[0][i];
					cdif -= v[k][j] != v[0][j];
					if (cdif == 0) {

					}
					else if (cdif == 1) {
						vector<pair<int, int>>ncand;
						for (auto c : cand) {
							if (c.first == -1 && c.second == -1) {
								ncand.emplace_back(-1, v[k][j]);
								ncand.emplace_back(v[k][i], -1);
							}
							else if (c.first == -1) {
								if (c.second == v[k][j]) {
									ncand.emplace_back(-1, c.second);
								}
								else {
									ncand.emplace_back(v[k][i], c.second);
								}
							}
							else if (c.second == -1) {
								if (c.first == v[k][i]) {
									ncand.emplace_back(c.first, -1);
								}
								else {
									ncand.emplace_back(c.first, v[k][j]);
								}
							}
							else {
								if (c.first == v[k][i] || c.second == v[k][j]) {
									ncand.push_back(c);
								}
							}
						}
						cand = ncand;
						sort(cand.begin(), cand.end());
						cand.erase(unique(cand.begin(), cand.end()), cand.end());
					}
					else if (cdif == 2) {
						vector<pair<int, int>>ncand;
						for (auto c : cand) {
							if ((c.first == -1 || c.first == v[k][i]) && (c.second == -1 || c.second == v[k][j])) {
								ncand.emplace_back(v[k][i], v[k][j]);
							}
						}
						cand = ncand;
						sort(cand.begin(), cand.end());
						cand.erase(unique(cand.begin(), cand.end()), cand.end());
					}
					else {
						cand.clear();
						break;
					}
					if (cand.empty())break;
				}
				if (cand.size()) {
					auto ans = v[0];
					if (cand[0].first != -1) {
						ans[i] = cand[0].first;
					}
					if (cand[0].second != -1) {
						ans[j] = cand[0].second;
					}
					cout << "Yes\n";
					for (auto k : ans) {
						cout << k << " ";
					}
					cout << endl;
					return;
				}
			}
		}
	}
	cout << "No" << endl;
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