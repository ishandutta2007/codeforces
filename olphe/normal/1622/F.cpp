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

//constexpr long long int MOD = 1000000007;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	int p[1000001] = {};
	for (int i = 2; i <= 1000000; i++) {
		if (p[i])continue;
		p[i] = i;
		for (int j = i * 2; j <= 1000000; j += i) {
			p[j] = max(p[j], i);
		}
	}
	cin >> N;
	vector<unsigned long long>num(N + 1);
	vector<unsigned long long>hs(N + 1);
	random_device rd;
	mt19937_64 mt(rd());
	unsigned long long tot = 0;
	for (int i = 2; i <= N; i++) {
		hs[i] = mt();
		num[i] = num[i - 1];
		int box = i;
		while (box > 1) {
			num[i] ^= hs[p[box]];
			box /= p[box];
		}
		tot ^= num[i];
	//	cout << i << " " << num[i] << endl;
	}
//	cout << tot << endl;
	if (tot == 0) {
		cout << N << endl;
		for (int i = 1; i <= N; i++)cout << i << " ";
		cout << endl;
		return;
	}
	for (int i = 2; i <= N; i++) {
		if (num[i] == tot) {
			cout << N - 1 << endl;
			for (int j = 1; j <= N; j++) {
				if (i != j)cout << j << " ";
			}
			cout << endl;
			return;
		}
	}
	unordered_map<unsigned long long, int>mp;
	for (int i = 2; i <= N; i++) {
		mp[num[i]] = i;
		auto it = mp.find(tot ^ num[i]);
		if (it != mp.end()) {
			cout << N - 2 << endl;
			for (int j = 1; j <= N; j++) {
				if (j != i && j != it->second)cout << j << " ";
			}
			cout << endl;
			return;
		}
	}
	cout << N - 3 << endl;
	for (int i = 1; i < N; i++) {
		if (i != 2 && i != (N - 1) / 2)cout << i << " ";
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	//cin >> T;
	while (T--) {
		Solve();
	}
}