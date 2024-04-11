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
	vector<int>v(N);
	for (auto &i : v)cin >> i;
	unordered_map<int, int>m;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = i; j >= 0; j--) {
			sum += v[j];
			auto it = m.find(sum);
			if (it == m.end()) {
				m[sum] = 10000 + i;
			}
			else {
				int num = it->second / 10000;
				int index = it->second % 10000;
				if (index >= j)continue;
				it->second = (num + 1) * 10000 + i;
			}
		}
	}
	int num = 0;
	int sum = 0;
	for (auto i : m) {
		if (num < i.second) {
			num = i.second;
			sum = i.first;
		}
	}
	cout << num / 10000 << endl;
	int used = -1;
	for (int i = 0; i < N; i++) {
		int box = 0;
		for (int j = i; j >= 0; j--) {
			box += v[j];
			if (box == sum) {
				if (used < j) {
					used = i;
					cout << j + 1 << " " << i + 1 << endl;
				}
				break;
			}
		}
	}
	return 0;
}