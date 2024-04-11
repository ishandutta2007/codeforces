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
	vector<long long int>v(N);
	for (auto &i : v)cin >> i;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	vector<long long int>w;
	for (int i = 1; i < v.size(); i++) {
		w.push_back(v[i] - v[i - 1]-1);
	}
	w.push_back(MOD*MOD);
	sort(w.begin(), w.end());
	auto wsum = w;
	vector<long long int>ret;
	for (int i = 1; i < wsum.size(); i++)wsum[i] += wsum[i - 1];
	cin >> K;
	for (int i = 0; i < K; i++) {
		cin >> L >> R;
		M = R - L;
		auto it = lower_bound(w.begin(), w.end(), M);
		//cout << it - w.begin() << endl;
		long long int ans = w.size();
		if (it - w.begin() > 0) {
			ans += wsum[it - w.begin() - 1];
		}
		ans += M * (w.size() - (it - w.begin()));
		ret.push_back(ans);
	}
	for (auto i : ret)cout << i << " ";
	cout << endl;
	return 0;
}