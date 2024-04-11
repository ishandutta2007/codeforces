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

void Solve() {
	cin >> K;
	string s;
	cin >> s;
	cin >> M;
	vector<int>l(1 << K);
	vector<int>r(1 << K);
	for (int i = 0; i < 1 << (K - 1); i++) {
		l[i] = r[i] = 1;
	}
	int idx = 0;
	vector<int>nx(1 << K, -1);
	vector<int>bef(1 << K, -1);
	for (int i = 1 << (K - 1); i < s.size(); i++) {
		nx[idx] = i;
		nx[idx + 1] = i;
		bef[i] = idx;
		idx += 2;
	}
	for (int i = 0; i < s.size(); i++) {
		if (nx[i] == -1)continue;
		if (i & 1) {
			if (s[i] == '0') {
				r[nx[i]] = l[i];
			}
			else if (s[i] == '1') {
				r[nx[i]] = r[i];
			}
			else {
				r[nx[i]] = l[i] + r[i];
			}
		}
		else {
			if (s[i] == '0') {
				l[nx[i]] = l[i];
			}
			else if (s[i] == '1') {
				l[nx[i]] = r[i];
			}
			else {
				l[nx[i]] = l[i] + r[i];
			}
		}
	}
	while (M--) {
		cin >> N;
		char c;
		cin >> c;
		N--;
		s[N] = c;
		int i = N;
		while (nx[i] != -1) {
			if (i & 1) {
				if (s[i] == '0') {
					r[nx[i]] = l[i];
				}
				else if (s[i] == '1') {
					r[nx[i]] = r[i];
				}
				else {
					r[nx[i]] = l[i] + r[i];
				}
			}
			else {
				if (s[i] == '0') {
					l[nx[i]] = l[i];
				}
				else if (s[i] == '1') {
					l[nx[i]] = r[i];
				}
				else {
					l[nx[i]] = l[i] + r[i];
				}
			}
			i = nx[i];
		}
		if (s.back() == '0') {
			cout << l[s.size() - 1] << endl;
		}
		else if (s.back() == '1') {
			cout << r[s.size() - 1] << endl;
		}
		else {
			cout << l[s.size() - 1] + r[s.size() - 1] << endl;
		}
	}
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