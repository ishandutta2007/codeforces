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
//const long long int MOD = 1000003;
//const int MOD = 998244353;
const long long int MOD = 998244353;

int N, M, K, H, W, L, R;
//long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	for (int &i : v)cin >> i;
	vector<int>w(N);
	for (int &i : w)cin >> i;
	int ans = 0;
	int index = N - 1;
	vector<int>box(N);
	for (int i = 0; i < N; i++)box[i] = i + 1;
	if (w == box) {
		cout << 0 << endl;
		return 0;
	}
	if (w.back() != N) {
		while (w[index] == w[index - 1] + 1)index--;
		if (!w[index]) {
			bool flag = true;
			for (int i = 0; i < index; i++) {
				if (w[i] && w[i] <= w.back() + i + 1)flag = false;
			}
			if (flag) {
				cout << N - w.back() << endl;
				return 0;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		if (!w[i])continue;
		ans = max(ans, N + 2 + i - w[i]);
	}
	cout << ans << endl;
}