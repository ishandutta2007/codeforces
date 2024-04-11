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
	string s, t;
	cin >> s >> t;
	vector<vector<int>>v(26);
	vector<int>w;
	for (int i = 0; i < N; i++) {
		if (t[i] == '?') {
			w.push_back(i + 1);
			continue;
		}
		v[t[i] - 'a'].push_back(i + 1);
	}
	vector<pair<int, int>>ans;
	for (int i = 0; i < N; i++) {
		if (s[i] == '?')continue;
		if (!v[s[i] - 'a'].empty()) {
			ans.push_back({ i + 1 ,v[s[i] - 'a'].back() });
			v[s[i] - 'a'].pop_back();
			continue;
		}
		if (!w.empty()) {
			ans.push_back({ i + 1,w.back() });
			w.pop_back();
			continue;
		}
	}
	vector<int>box;
	for (auto i : v)for (auto j : i)box.push_back(j);
	for (auto i : w)box.push_back(i);
	for (int i = 0; i < N; i++) {
		if (s[i] != '?')continue;
		ans.push_back({ i + 1,box.back() });
		box.pop_back();
	}
	cout << ans.size() << endl;
	for (auto i : ans)cout << i.first << " " << i.second << endl;
	return 0;
}