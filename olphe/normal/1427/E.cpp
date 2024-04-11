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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

vector<string>ans;

void add(long long int a, long long int b) {
	ans.push_back(to_string(a) + " + " + to_string(b));
	//cout << a << " + " << b << endl;
}

void XOR(long long int a, long long int b) {
	ans.push_back(to_string(a) + " ^ " + to_string(b));
	//cout << a << " ^ " << b << endl;
}

int func(int num) {
	int ret = num;
	vector<long long int>by(21, num);
	for (int i = 1; i <= 20; i++) {
		by[i] = by[i - 1] * 2;
		add(by[i - 1], by[i - 1]);
	}
	int idx = 0;
	for (int i = 1; i <= 20; i++) {
		if (by[i] & by[0]) {
			idx = i;
			break;
		}
	}
	int tp = 0;
	for (int i = 0; i < 20; i++) {
		if ((num >> i) & 1) {
			tp = i;
		}
	}
	long long int a = by[idx];
	long long int b = by[idx] ^ by[0];
	XOR(by[idx], by[0]);
	for (int i = 1; i < 1 << 20; i++) {
		if ((min(a, b) + num * i) % (1 << (tp+1)) == 0) {
			for (int j = 0; j < 20; j++) {
				if ((i >> j) & 1) {
					add(a, by[j]);
					add(b, by[j]);
					a += by[j];
					b += by[j];
				}
			}
			ret = a ^ b;
			XOR(a, b);
			break;
		}
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	while (N > 1) {
		N = func(N);
	}
	cout << ans.size() << endl;
	for (auto i : ans)cout << i << endl;
}