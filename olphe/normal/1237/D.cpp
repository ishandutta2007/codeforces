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
#include "functional"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<long long int>v(N);
	for (auto &i : v)cin >> i;
	if (*max_element(v.begin(), v.end()) <= *min_element(v.begin(), v.end()) * 2) {
		for (int i = 0; i < N; i++)cout << -1 << " ";
		cout << endl;
		return 0;
	}
	vector<pair<long long int, long long int>>w(N);
	for (int i = 0; i < N; i++) {
		w[i] = { v[i],i };
	}
	sort(w.begin(), w.end());
	int aindex = 0, bindex = 0;
	set<int>s;
	vector<int>ans(N);
	while (bindex < N) {
		//cout << aindex << " " << bindex << endl;
		if (aindex < N&&w[aindex].first <= w[bindex].first*2) {
			auto it = s.lower_bound(w[aindex].second);
			if (it == s.end())ans[w[aindex].second] = MOD;
			else ans[w[aindex].second] = *it - w[aindex].second;
			aindex++;
		}
		else {
			s.insert(w[bindex].second);
			s.insert(w[bindex].second + N);
			bindex++;
		}
	}
	for (int i = N - 1; i >= 0; i--)ans[i] = min(ans[i], ans[(i + 1) % N] + 1);
	for (int i = N - 1; i >= 0; i--)ans[i] = min(ans[i], ans[(i + 1) % N] + 1);
	for (auto i : ans)cout << i << " ";
	cout << endl;
}