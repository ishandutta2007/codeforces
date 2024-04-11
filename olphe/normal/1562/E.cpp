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
//#include <atcoder/all>

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr long long int MOD = 998244353;
constexpr int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

class SuffixArray {
	string s;
	vector<int>nx;
	int length = 1;
	int n;
public:
	vector<int>ret;
	vector<int>id;
	vector<int>lcp;
	SuffixArray(string ss) {
		s = ss;
		n = s.size();
		id.resize(n);
		nx.resize(n);
		ret.resize(n);
		lcp.resize(n);
		for (int i = 0; i < n; i++) {
			ret[i] = i;
		}
		for (int i = 0; i < n; i++) {
			id[i] = s[i];
		}
		while (length < n) {
			auto comp = [&](int a, int b) {
				if (id[a] != id[b])return id[a] < id[b];
				int l = -1, r = -1;
				if (a + length < n)l = id[a + length];
				if (b + length < n)r = id[b + length];
				return l < r;
			};
			sort(ret.begin(), ret.end(), comp);
			nx[ret[0]] = 0;
			for (int i = 1; i < n; i++) {
				nx[ret[i]] = nx[ret[i - 1]] + comp(ret[i - 1], ret[i]);
			}
			id = nx;
			length <<= 1;
		}
		for (int i = 0; i < n; i++) {
			int nx = id[i];
			if (nx + 1 == n)continue;
			nx = ret[nx + 1];
			int idx = i;
			if (i && lcp[id[i - 1]]) {
				lcp[id[i]] = lcp[id[i - 1]] - 1;
				nx += lcp[id[i]];
				idx += lcp[id[i]];
			}
			while (nx < n && i < n && s[idx] == s[nx]) {
				lcp[id[i]]++;
				nx++;
				idx++;
			}
		}
	}
};

void Solve() {
	cin >> N;
	string s;
	cin >> s;
	if (N == 1) {
		cout << 1 << endl;
		return;
	}
	//cout << s.size() << endl;
	//N = 5000;
	//s = string(N, 'a');
	SuffixArray sa(s);
	vector<vector<int>>box(N + 1, vector<int>(N + 1, -1));
	vector<int>dp(N + 1);
	for (int i = 0; i < N - 1; i++) {
		int mx = N - sa.ret[i];
		for (int j = i + 1; j < N; j++) {
			mx = min(mx, sa.lcp[j - 1]);
			box[sa.ret[j]][sa.ret[i]] = mx;
		}
	}
	dp[0] = N;
	for (int i = 1; i < N; i++) {
		dp[i] = N - i;
		for (int j = 0; j < i; j++) {
			if (box[i][j] == -1)continue;
			dp[i] = max(dp[i], dp[j] + (int)N - i - box[i][j]);
		}
	}
	cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}