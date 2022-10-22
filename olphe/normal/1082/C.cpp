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

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<vector<int>>v(M + 1);
	for (int i = 0; i < N; i++) {
		cin >> L >> R;
		v[L].push_back(R);
	}
	for (int i = 1; i <= M; i++) {
		if (v[i].empty())continue;
		sort(v[i].begin(), v[i].end(), greater<int>());
		for (int j = 1; j < v[i].size(); j++)v[i][j] += v[i][j - 1];
	}
	int ans = 0;
	vector<int>w(M);
	for (int i = 0; i < M; i++)w[i] = i + 1;
	for (int i = 0; i <= N; i++) {
		int box = 0;
		//cout << i << " " << w.size() << endl;
		for (int j = 0; j < w.size(); j++) {
			while (1) {
				int cn = w[j];
				if (v[cn].size() <= i || v[cn][i] <= 0) {
					swap(w[j], w[w.size() - 1]);
					w.pop_back();
				}
				else break;
				if (w.size() == j)break;
			}
			if(w.size()>j)box += v[w[j]][i];
		}
		ans = max(ans, box);
		//cout << ans << endl;
	}
	cout << ans << endl;
}