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

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	N = s.size();
	vector<vector<int>>p(3);
	for (int i = 0; i < N; i++) {
		p[s[i] - 'a'].push_back(i);
	}
	for (int i = 0; i < 3; i++) {
		string t;
		M = p[i].size();
		if (!M)continue;
		if (M & 1) {
			L = R = M / 2;
		}
		else {
			R = M / 2;
			L = R - 1;
			vector<int>num(3);
			for (int j = p[i][L] + 1; j < p[i][R]; j++) {
				num[s[j] - 'a']++;
			}
			int mx = 0;
			for (int j = 0; j < 3; j++)mx = max(mx, num[j]);
			for (int j = 0; j < 3; j++) {
				if (mx == num[j]) {
					for (int k = 0; k < (mx + 1) / 2; k++) {
						t.push_back(j + 'a');
					}
					if (mx & 1)M++;
					break;
				}
			}
		}
		while (L) {
			t.push_back(i + 'a');
			vector<int>lnum(3);
			vector<int>rnum(3);
			for (int j = p[i][L] - 1; j > p[i][L - 1]; j--)lnum[s[j] - 'a']++;
			for (int j = p[i][R] + 1; j < p[i][R + 1]; j++)rnum[s[j] - 'a']++;
			int mx = 0;
			for (int j = 0; j < 3; j++) {
				mx = max(mx, min(lnum[j], rnum[j]));
			}
			for (int j = 0; j < 3; j++) {
				if (mx == min(lnum[j], rnum[j])) {
					for (int k = 0; k < mx; k++)t.push_back(j + 'a');
					break;
				}
			}
			L--;
			R++;
		}
		t.push_back(i + 'a');
		vector<int>lnum(3);
		vector<int>rnum(3);
		for (int j = p[i][L] - 1; j >= 0; j--) {
			lnum[s[j] - 'a']++;
		}
		for (int j = p[i][R] + 1; j < N; j++) {
			rnum[s[j] - 'a']++;
		}
		int mx = 0;
		for (int j = 0; j < 3; j++) {
			mx = max(mx, min(lnum[j], rnum[j]));
		}
		for (int j = 0; j < 3; j++) {
			if (mx == min(lnum[j], rnum[j])) {
				for (int k = 0; k < mx; k++)t.push_back(j + 'a');
				break;
			}
		}
		if (t.empty())continue;
		auto u = t;
		reverse(u.begin(), u.end());
		if (M & 1)u.pop_back();
		u += t;
		if (u.size() >= N / 2) {
			cout << u << endl;
			return 0;
		}
	}
	cout << "IMPOSSIBLE\n";
}