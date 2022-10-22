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
//const int MOD = 998244353;

long long int N, M, K, H, W, L, R;
//int N, M, K, H, W, L, R


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	vector<int>v(1, 0);
	N = 1;
	for (int i = 0; i < 30; i++) {
		v.push_back(N);
		N <<= 1;
	}
	while (s == "start") {
		char t;
		for (int i = 0; i < 30; i++) {
			cout << "? " << v[i] << " " << v[i + 1] << endl;
			cin >> t;
			if (t == 'x') {
				L = v[i] + 1;
				R = v[i + 1] + 1;
				break;
			}
		}
		if (!L) {
			L = v.back() + 1;
			R = MOD;
		}
		while (R - L > 1) {
			long long int mid = (R + L - 1) / 2;
			cout <<"? "<< L - 1 << " " << mid << endl;
			cin >> t;
			if (t == 'x') {
				R = mid + 1;
			}
			else {
				L = mid + 1;
			}
		}
		cout << "! " << L << endl;
		L = 0;
		R = 0;
		cin >> s;
	}
	return 0;
}