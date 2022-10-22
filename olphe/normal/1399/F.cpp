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
constexpr double EPS = 1e-12;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N;
		vector<pair<int, int>>v(N);
		for (auto &i : v) {
			cin >> i.first >> i.second;
		}
		v.push_back({ -1,MOD });
		v.push_back({ -2,MOD + 1 });
		int ans = 0;
		sort(v.begin(), v.end());
		map<int, int>x;
		for (auto i : v) {
			x[i.first] = 0; 
			x[i.second] = 0;
		}
		int cnt = 0;
		for (auto &i : x)i.second = cnt++;
		for (auto &i : v) {
			i.first = x[i.first];
			i.second = x[i.second];
		}
		N++;
		N++;
		for (auto &i : v)i.second *= -1;
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		for (auto &i : v)i.second *= -1;
		vector<int>dp(N, 1);
		vector<int>cdp(cnt, 0);
		for (int i = 0; i < N - 1; i++) {
			for (auto &j : cdp)j = 0;
			int bef = 0;
			for (int j = i - 1; j >= 0; j--) {
				if (v[i].first < v[j].first&&v[i].second < v[j].second)continue;
				while (bef < v[j].first) {
					cdp[bef + 1] = max(cdp[bef + 1], cdp[bef]);
					bef++;
				}
				//cout << cnt << " " << v[j].second << endl;
				cdp[v[j].second] = max(cdp[v[j].second], cdp[v[j].first - 1] + dp[j]);
			}
			for (int j = 0; j <= v[i].second; j++) {
			//	cout << N << " " << i << endl;
			//	cout << cnt << " " << j << endl;
				dp[i] = max(cdp[j] + 1, dp[i]);
			}
		}
		cout << dp[N - 2] - 1 << endl;
	}
	//return 0;
}