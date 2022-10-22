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
constexpr double EPS = 1e-9;

int N, M, K, H, W, L, R;
//long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		string s;
		cin >> s;
		vector<vector<int>>nx(4,vector<int>(s.size()+2, MOD));
		for (int i = s.size(); i < s.size() + 2; i++) {
			for (int j = 0; j < 4; j++) {
				nx[j][i] = i;
			}
		}
		for (int i = s.size()-1; i >= 0; i--) {
			nx[s[i] - '0'][i] = i;
			//if (i + 1 < s.size()) {
				for (int j = 0; j < 4; j++) {
					nx[j][i] = min(nx[j][i], nx[j][i + 1]);
				}
		//	}
		}
		for (int i = 0; i < s.size()+2; i++) {
			for (int j = 0; j <= 3; j++) {
	//			cout << j << " " << i << " " << nx[j][i] << endl;
			}
		}
		int ans = MOD;
		for (int i = 0; i < s.size(); i++) {
			int ed = MOD;
			if (s[i] == '1') {
				ed = min(ed, nx[2][nx[3][i]]);
				ed = min(ed, nx[3][nx[2][i]]);
			}
			if (s[i] == '3') {
				ed = min(ed, nx[2][nx[1][i]]);
				ed = min(ed, nx[1][nx[2][i]]);
			}
			if (s[i] == '2') {
				ed = min(ed, nx[1][nx[3][i]]);
				ed = min(ed, nx[3][nx[1][i]]);
			}
			if (ed < s.size())ans = min(ans, ed - i+1);
		}
		cout << ans % MOD << endl;
	}
}