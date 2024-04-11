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

	cin >> M;
	string s;
	cin >> s;
	set<char>st;
	for (auto i : s) {
		st.insert(i);
	}
	N = st.size();
	int cnt = 0;
	R = 0;
	map<char, int>m;
	int ans = INT_MAX;
	for (int i = 0; i < M; i++) {
		while (cnt < N) {
			if (R == M) {
				break;
			}
			m[s[R]]++;
			if (m[s[R]] == 1) {
				cnt++;
			}
			R++;
		}
		if (cnt == N) {
			ans = min(ans, (int)R - i);
		}
		m[s[i]]--;
		if (m[s[i]] == 0) {
			cnt--;
		}
	}
	cout << ans << endl;
	return 0;
}