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

using namespace std;

const long long int MOD = 1000000007;
//const int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;




int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	vector<int>l(N + 1,MOD);
	vector<int>r(N + 1, -1);
	for (int i = 0; i < N; i++) {
		l[v[i]] = min(l[v[i]], i);
		r[v[i]] = i;
	}
	vector<pair<int, int>>boxl;
	vector<pair<int, int>>boxr;
	for (int i = 1; i <= N; i++) {
		if (r[i] == -1)continue;
		boxl.push_back({ l[i],i });
		boxr.push_back({ r[i],i });
	}
	sort(boxl.begin(), boxl.end());
	sort(boxr.begin(), boxr.end());
	reverse(boxr.begin(), boxr.end());
	int ans = 0;
	for (int i = 0; i < N; i++) {
		if (boxl[0].second == v[i]) {
			ans = max(ans, abs(i - boxl[1].first));
		}
		else {
			ans = max(ans, i);
		}
		if (boxr[0].second == v[i]) {
			ans = max(ans, abs(i - boxr[1].first));
		}
		else {
			ans = max(ans, i - boxr[0].first);
		}
	}
	cout << ans << endl;
	return 0;
}