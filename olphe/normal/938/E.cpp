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

long long int power(long long int x, long long int n, long long int M) {
	long long int tmp = 1;

	if (n > 0) {
		tmp = power(x, n / 2, M);
		if (n % 2 == 0) tmp = (tmp*tmp) % M;
		else tmp = (((tmp*tmp) % M)*x) % M;
	}
	return tmp;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<long long int>v(N);
	map<int, int>m;
	for (auto &i : v) {
		cin >> i;
		m[-i]++;
	}
	vector<long long int>by(N*2 + 1,1);
	vector<long long int>rev_by(N*2 + 1,1);
	for (int i = 2; i <= N * 2; i++) {
		by[i] = by[i - 1] * i;
		by[i] %= MOD;
		rev_by[i] = power(by[i], MOD - 2, MOD);
	}
	long long int ans = 0;
	long long int used = (*m.begin()).second;
	m.erase(m.begin());
	for (auto i : m) {
		long long int num = i.second;
		long long int add = -i.first;
		add *= by[used + num - 1];
		add %= MOD;
		add *= by[N];
		add %= MOD;
		add *= rev_by[used + num];
		add %= MOD;
		add *= by[used];
		add %= MOD;
		add *= by[num];
		add %= MOD;
		add *= rev_by[used];
		add %= MOD;
		add *= rev_by[num-1];
		add %= MOD;
		ans += add;
		ans %= MOD;
		used += num;
	//	cout << ans << endl;
	}
	cout << ans << endl;
	return 0;
}