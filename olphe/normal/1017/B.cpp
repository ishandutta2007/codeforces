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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	string s, t;
	cin >> s >> t;
	vector<long long int>v(4);
	for (int i = 0; i < N; i++) {
		int box = s[i] - '0';
		box *= 2;
	//	cout << box << " ";
		box += t[i] - '0';
	//	cout << box << endl;
		v[box]++;
	}
	long long int ans = 0;
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			int box = (i % 2) + (j & 2);
			int bag = (j % 2) + (i & 2);
			if (i&&j) {
				if (box&&bag)continue;
				ans += v[i] * v[j];
			}
			else if (i && !j) {
				if (box && !bag)continue;
				ans += v[i] * v[j];
			}
			else if (!i&&j) {
				if (!box&&bag)continue;
				ans += v[i] * v[j];
			}
			else {
				if (!box && !bag)continue;
				ans += v[i] * v[j];
			}
			//cout << i << " " << j << " " << ans << endl;
		}
	}
	cout << ans << endl;
	return 0;
}