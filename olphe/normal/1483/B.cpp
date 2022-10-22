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
//constexpr int MOD = 1000000007;
constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N;
	vector<int>v(N);
	for (auto& i : v)cin >> i;
	set<int>s;
	for (int i = 0; i < N; i++)s.insert(i);
	set<int>box;
	vector<int>ans;
	for (int i = 1; i < N; i++) {
		if (gcd(v[i], v[i - 1]) == 1) {
			box.insert(i);
		}
	}
	int bef = -1;
	if (gcd(v.front(), v.back())==1) {
		box.insert(0);
	}
	int tugi = 0;
	while (!box.empty()) {
//		cout << box.size() << endl;
		auto it = box.upper_bound(tugi);
		if (it == box.end()) {
			it = box.begin();
		}
		auto pv = s.find(*it);
		if (pv == s.begin()) {
			pv = s.end();
		}
		pv--;
	//	cout << *pv << " " << *it << endl;
		if (gcd(v[*pv], v[*it]) == 1) {
			ans.push_back(*it);
			bef = *it;
			auto nx = s.find(*it);
			nx++;
			if (nx == s.end())nx = s.begin();
			box.erase(*nx);
			if (gcd(v[*pv], v[*nx]) == 1) {
				box.insert(*nx);
			}
			if (s.size() > 1) {
				if (next(s.find(*it)) == s.end()) {
					tugi = *s.begin();
				}
				else {
					tugi = *next(s.find(*it));
				}
			}
			s.erase(*it);
			box.erase(*it);
		}
		else {
			box.erase(*it);
		}
	}
	cout << ans.size();
	for (auto i : ans) {
		cout << " " << i + 1;
	}
	cout << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
	cin >> T;
	while (T--) {
		Solve();
	}
}