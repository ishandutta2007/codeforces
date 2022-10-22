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
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N >> M >> K;
	vector<int>l(N);
	vector<int>r(N);
	map<int, int>mp;
	for (int i = 0; i < N; i++) {
		cin >> l[i] >> r[i];
		r[i]++;
		mp[l[i]] = mp[r[i]] = 0;
	}
	mp[-MOD] = 0;
	mp[MOD] = 0;
	mp[M + 1] = 0;
	vector<int>conv;
	int cnt = 0;
	for (auto& i : mp) {
		i.second = cnt++;
		conv.push_back(i.first);
	}
	for (int i = 0; i < N; i++) {
		l[i] = mp[l[i]];
		r[i] = mp[r[i]];
	}
	vector<int>dp(1 << K, -MOD);
	dp[0] = 0;
	vector<vector<int>>box(cnt);
	for (int i = 0; i < N; i++) {
		box[l[i]].push_back(r[i]);
	}
	for (int i = 0; i < cnt; i++) {
		sort(box[i].begin(), box[i].end());
	}
	vector<int>nodd(256);
	vector<int>nb(256);
	for (int i = 0; i < 256; i++) {
		for (int j = 0; j < 8; j++) {
			if (i >> j & 1) {
				nodd[i] ^= 1;
				nb[i] |= 1 << j;
			}
		}
	}
	vector<int>use;
	for (int i = 1; i + 1 < cnt; i++) {
		vector<int>ndp(1 << K, -MOD);
		vector<int>nx;
		int idx = 0;
		for (int j = 0; j < use.size(); j++) {
			if (use[j] > i) {
				nx.push_back(idx++);
			}
			else {
				nx.push_back(-1);
			}
		}
		vector<int>mx(256,-1);
		vector<int>odd(256);

		for (int j = 0; j < 1 << use.size(); j++) {
			int od = 0;
			int nxb = 0;
			for (int k = 0; k < use.size(); k++) {
				if (j >> k & 1) {
					if (nx[k] != -1) {
						nxb |= 1 << nx[k];
						od ^= 1;
					}
				}
			}
			odd[nxb] = od;
			mx[nxb] = max(mx[nxb], dp[j]);
		}
		for(int j=0;j<1<<use.size();j++){
		//	cout << j << " " << mx[j] << endl;
			if (mx[j] == -1)continue;
			for (int k = 0; k < 1 << box[i].size(); k++) {
				if (odd[j] ^ nodd[k]) {
					ndp[j ^ (nb[k]<<idx)] = max(ndp[j ^ (nb[k] << idx)], mx[j] + conv[i + 1] - conv[i]);
				}
				else {
					ndp[j ^ (nb[k] << idx)] = max(ndp[j ^ (nb[k] << idx)], mx[j]);
				}
			}
		}
		vector<int>nuse;
		for (int j = 0; j < use.size(); j++) {
			if (nx[j] != -1) {
				nuse.push_back(use[j]);
			}
		}
		for (int j = 0; j < box[i].size(); j++) {
			nuse.push_back(box[i][j]);
		}
		use = nuse;
		dp = ndp;
	}
	cout << *max_element(dp.begin(), dp.end()) << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
//	cin >> T;
	while (T--) {
		Solve();
	}
}