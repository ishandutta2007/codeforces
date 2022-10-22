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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	string s, t;
	cin >> s >> t;
	string ss = s, tt = t;
	sort(ss.begin(), ss.end());
	sort(tt.begin(), tt.end());
	if (ss != tt) {
		cout << -1 << endl;
		return 0;
	}
	vector<int>ans;
	while (s != t) {
		for (int i = 0; i < N; i++) {
			if (s[i] != t[i]) {
				for (int j = i + 1; j < N; j++) {
					if (t[i] == s[j]) {
						for (int k = j - 1; k >= i; k--) {
							ans.push_back(k + 1);
							swap(s[k], s[k + 1]);
						}
						break;
					}
				}
				break;
			}
		}
	}
	cout << ans.size() << endl;
	for (auto i : ans)cout << i << " ";
	cout << endl;
	return 0;
}