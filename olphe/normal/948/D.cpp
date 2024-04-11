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
	vector<long long int>v(N);
	map<long long int,int>m;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> M;
		m[M]++;
	}
	for (int i = 0; i < N; i++) {
		int box = 0;
		for (int j = 30; j >= 0; j--) {
			bool flag = (v[i] >> j) & 1;
			long long int add = 1 << j;
			if (flag) {
				if (m.lower_bound(box + add) != m.lower_bound(box + add * 2)) {
					box += add;
				}
			}
			else {
				if (m.lower_bound(box) == m.lower_bound(box + add)) {
					box += add;
				}
			}
		}
		cout << (v[i] ^ box) << " ";
		m[box]--;
		if (m[box] == 0) {
			m.erase(box);
		}
	}
	cout << endl;
	return 0;
}