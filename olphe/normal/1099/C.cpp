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
	cin >> N;
	for (auto i : s) {
		if (i == '?')M++;
		if (i == '*')K++;
	}
	if (s.size() - M - M - K - K > N) {
		cout << "Impossible\n";
		return 0;
	}
	if (K) {
		string t;
		for (auto i : s) {
			if (i == '?')t.pop_back();
			else if (i == '*'&&K > 1) {
				t.pop_back();
				K--;
			}
			else t.push_back(i);
		}
		L = t.size() - 1;
		string u;
		for (auto i : t) {
			if (i == '*') {
				if (N - L == -1) {
					u.pop_back();
				}
				for (int j = 0; j < N - L; j++) {
					u.push_back(u.back());
				}
			}
			else u.push_back(i);
		}
		cout << u << endl;
		return 0;
	}
	if (s.size() - M < N) {
		cout << "Impossible\n";
		return 0;
	}
	L = N - (s.size() - M - M);
	string t;
	for (auto i : s) {
		if (i == '?') {
			if (L) {
				L--;
				continue;
			}
			else {
				t.pop_back();
			}
		}
		else t.push_back(i);
	}
	cout << t << endl;
	return 0;
}