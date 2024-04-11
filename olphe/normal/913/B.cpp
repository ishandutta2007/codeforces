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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<vector<int>>parents(N + 1);
	vector<vector<int>>children(N + 1);
	vector<bool>leaf(N + 1);
	for (int i = 2; i <= N; i++) {
		cin >> M;
		parents[i].push_back(M);
		children[M].push_back(i);
	}
	for (int i = 1; i <= N; i++) {
		if (children[i].empty()) {
			leaf[i] = true;
		}
	}
	for (int i = 1; i <= N; i++) {
		if (leaf[i]) {
			continue;
		}
		int cnt = 0;
		for (auto j : children[i]) {
			if (leaf[j]) {
				cnt++;
			}
		}
		if (cnt < 3) {
			cout << "No\n";
			return 0;
		}
	}
	cout << "Yes\n";
	return 0;
}