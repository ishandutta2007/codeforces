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

//const long long int MOD = 1000000007;
const int MOD = 1000000007;
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	string s;
	cin >> s;
	vector<string>vs(3);
	vector<vector<vector<int>>>dp(251, vector<vector<int>>(251, vector<int>(251, MOD)));
	vector<vector<int>>nx(26, vector<int>(N, MOD));
	for (int i = 0; i < N; i++) {
		if (i)nx[s[i] - 'a'][i - 1] = i;
	}
	for (int i = 0; i < 26; i++) {
		for (int j = N - 2; j >= 0; j--)nx[i][j] = min(nx[i][j], nx[i][j + 1]);
	}
	dp[0][0][0] = -1;
	for (int i = 0; i < M; i++) {
		//cout << i << endl;
		char c;
		cin >> c >> K;
		K--;
		if (c == '-') {
			if (K == 0) {
				for (int j = 0; j <= vs[1].size(); j++) {
					for (int k = 0; k <= vs[2].size(); k++) {
						dp[vs[0].size()][j][k] = MOD;
					}
				}
			}
			else if (K == 1) {
				for (int j = 0; j <= vs[0].size(); j++) {
					for (int k = 0; k <= vs[2].size(); k++) {
						dp[j][vs[1].size()][k] = MOD;
					}
				}
			}
			else {
				for (int j = 0; j <= vs[0].size(); j++) {
					for (int k = 0; k <= vs[1].size(); k++) {
						dp[j][k][vs[2].size()] = MOD;
					}
				}
			}
			vs[K].pop_back();
			if (dp[vs[0].size()][vs[1].size()][vs[2].size()] != MOD) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
		else {
			cin >> c;
			vs[K].push_back(c);
			int jst = 0;
			int kst = 0;
			int lst = 0;
			if (K == 0)jst = vs[0].size();
			if (K == 1)kst = vs[1].size();
			if (K == 2)lst = vs[2].size();
			for (int j = jst; j <= vs[0].size(); j++) {
				for (int k = kst; k <= vs[1].size(); k++) {
					for (int l = lst; l <= vs[2].size(); l++) {
						if (j + k + l == 1) {
							if (j) {
								dp[j][k][l] = nx[vs[0].back() - 'a'][0];
								if (s[0] == vs[0].back())dp[j][k][l] = 0;
							}
							if (k) {
								dp[j][k][l] = nx[vs[1].back() - 'a'][0];
								if (s[0] == vs[1].back())dp[j][k][l] = 0;
							}
							if (l) {
								dp[j][k][l] = nx[vs[2].back() - 'a'][0];
								if (s[0] == vs[2].back())dp[j][k][l] = 0;
							}
						}
						else {
							if (j && dp[j - 1][k][l] != MOD)dp[j][k][l] = min(dp[j][k][l], nx[vs[0][j - 1] - 'a'][dp[j - 1][k][l]]);
							if (k && dp[j][k - 1][l] != MOD)dp[j][k][l] = min(dp[j][k][l], nx[vs[1][k - 1] - 'a'][dp[j][k - 1][l]]);
							if (l && dp[j][k][l - 1] != MOD)dp[j][k][l] = min(dp[j][k][l], nx[vs[2][l - 1] - 'a'][dp[j][k][l - 1]]);
						}
					}
				}
			}
			if (dp[vs[0].size()][vs[1].size()][vs[2].size()] != MOD)cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}