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
const long double EPS = 1e-8;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N + 2, -10000000);
	for (int i = 1; i <= N; i++)cin >> v[i];
	vector<int>l(N + 2, -MOD);
	vector<int>r(N + 2, -MOD);
	for (int i = 1; i <= N; i++) {
		l[i] = max(0, v[i - 1] - v[i] + 1);
		r[i] = max(0, v[i + 1] - v[i] + 1);
	}
	M = (N + 1) / 2;
	vector<int>dpf(M+1, MOD);
	vector<int>dps(M+1, MOD);
	vector<int>dpt(M+1, MOD);
	vector<int>ans(M + 1,MOD);
	dpf[0] = 0;
	dps[0] = 0;
	dpt[0] = 0;
	dpf[1] = r[1];
	ans[1] = r[1];
	for (int i = 2; i <= N; i++) {
		for (int j = M; j >= 1; j--) {
			dpt[j] = min(dpt[j], dps[j]);
			dps[j] = dpf[j];
			if (j > 1) {
				dpf[j] = min({  dpt[j - 1] + l[i] + r[i], dps[j - 1] + r[i] + max(0, l[i] - r[i - 2]) });
			}
			else {
				dpf[j] = r[i] + l[i];
			}
			ans[j] = min(ans[j], dpf[j]);
		}
	}
	for (int i = 1; i <= M; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}