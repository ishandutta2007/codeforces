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

inline int gcd(int a, int b) {
	if (a < b)swap(a, b);
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

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
	auto P = Prime(sqrt(15100000));
	vector<int>v(N);
	for (int i = 0; i < N; i++)cin >> v[i];
	long long int bag = v[0];
	for (int i = 1; i < N; i++) {
		bag = gcd(bag, v[i]);
	}
	for (int i = 0; i < N; i++) {
		v[i] /= bag;
	}
	map<int, int>m;
	long long int ans = MOD;
	for (auto &i : v) {
		for (auto j :P) {
			if (i < j)continue;
			if (i%j == 0) {
				m[j]++;
				while(i%j==0)i /= j;
			}
		}
		if (i != 1)m[i]++;
	}
	for (auto i : m) {
		ans = min(ans, N - i.second);
	}
	if (ans == MOD)ans = -1;
	cout << ans << endl;
	return 0;
}