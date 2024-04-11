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
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<long long int>v(N);
	for (auto &i : v)cin >> i;
	vector<long long int>w(N);
	for (auto &i : w)cin >> i;
	string s;
	long long int cnt = 0;
	while (1) {
		if (cnt <= 200000) {
			if (v.front() == w.front()) {
				if (v == w) {
					cout << "SMALL" << endl;
					cout << s.size() << endl;
					reverse(s.begin(), s.end());
					for (auto i : s)cout << i;
					cout << endl;
					return 0;
				}
			}
			if (v.back() == w.front()) {
				reverse(v.begin(), v.end());
				if (v == w) {
					s.push_back('R');
					cout << "SMALL" << endl;
					cout << s.size() << endl;
					reverse(s.begin(), s.end());
					for (auto i : s)cout << i;
					cout << endl;
					return 0;
				}
				reverse(v.begin(), v.end());
			}
		}
		else {
			if (v.front() == w.front()) {
				if (v == w) {
					cout << "BIG" << endl;
					cout << cnt << endl;
					return 0;
				}
			}
			if (v.back() == w.front()) {
				reverse(v.begin(), v.end());
				if (v == w) {
					cout << "BIG" << endl;
					cout << cnt << endl;
					return 0;
				}
				reverse(v.begin(), v.end());
			}
		}
		if (w.front() > w.back()) {
			reverse(w.begin(), w.end());
			s.push_back('R');
		}
		s.push_back('P');
		for (int i = N - 2; i >= 0; i--) {
			w[i + 1] -= w[i];
			if (w[i + 1] <= 0) {
				cout << "IMPOSSIBLE\n";
				return 0;
			}
		}
		cnt++;
		if (cnt > 4000000)break;
	}
	if (v.front() > v.back()) {
		swap(v.front(), v.back());
	}
	while (1) {
		if (w.front() > w.back()) {
			reverse(w.begin(), w.end());
		}
		if (w.front() < v.front()) {
			cout << "IMPOSSIBLE\n";
			return 0;
		}
		if (w.front() > v.front()) {
			cnt += w.back() / w.front();
			w.back() -= w.back() / w.front()*w.front();
		}
		else {
			if (w.back() >= v.back() && (w.back() - v.back()) % w.front() == 0) {
				cout << "BIG" << endl;
				cout << cnt + (w.back() - v.back()) / w.front() << endl;
			}
			else {
				cout << "IMPOSSIBLE\n";
			}
			return 0;
		}
	}
}