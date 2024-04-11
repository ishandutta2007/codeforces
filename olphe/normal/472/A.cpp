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
#include "ctime"

using namespace std;

const long long int MOD = 1000000007;
//const long long  int MOD = 998244353;
//long long int N, M, K, H, W, L, R;

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

	cin >> N;
	auto P = Prime(N);
	vector<int>v(N + 1);
	for (auto i : P)v[i] = 1;
	for (int i = 2; i < N; i++) {
		if (!v[i] && !v[N - i]) {
			cout << i << " " << N - i << endl;
			return 0;
		}
	}
	return 0;
}