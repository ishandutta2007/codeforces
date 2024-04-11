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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<int>v(M + 2);
	for (int i = 0; i < N; i++) {
		cin >> L >> R;
		v[L]++;
		v[R + 1]--;
	}
	vector<int>ans;
	for (int i = 1; i <= M; i++) {
		v[i] += v[i - 1];
		if (!v[i])ans.push_back(i);
	}
	cout << ans.size() << endl;
	for (auto i : ans)cout << i << " ";
	cout << endl;
	return 0;
}