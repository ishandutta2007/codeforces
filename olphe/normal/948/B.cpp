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

list<int> Prime(int num) {
	list<int>P;
	for (int i = 5; i <= num; i += 6) {
		bool flag = true;
		for (auto j : P) {
			if (j*j > i) {
				break;
			}
			if (i%j == 0) {
				flag = false;
				break;
			}
		}
		if (flag)P.push_back(i);
		flag = true;
		for (auto j : P) {
			if (j*j > i + 2) {
				break;
			}
			if ((i + 2) % j == 0) {
				flag = false;
				break;
			}
		}
		if (flag)P.push_back(i + 2);
	}
	P.push_front(3);
	P.push_front(2);
	return P;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	auto p = Prime(1000000);
	cin >> N;
	vector<int>v(1000001);
	v[3] = 3;
	for (int i = 4; i <= 1000000; i++) {
		v[i] = i;
		int box = i;
		for (auto j : p) {
			if (j > 1000) {
				break;
			}
			if (box%j == 0) {
				v[i] = min(v[i], i - j + 1);
				while (box%j == 0) {
					box /= j;
				}
			}
		}
		if (box > 1) {
			v[i] = min(v[i], i - box + 1);
		}
	}
	for (auto i : p) {
		v[i] = i;
	}
	int ans = N;
	for (int i = v[N]; i <= N; i++) {
		ans = min(v[i], ans);
	}
	cout << ans << endl;
	return 0;
}