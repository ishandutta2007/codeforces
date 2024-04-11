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

long long int ans = 0;

void hojuu(multiset<int>&used, multiset<int>&unused, int& num) {
	while (used.size() < num && !unused.empty()) {
		auto it = prev(unused.end());
		ans += *it;
		used.insert(*it);
		unused.erase(it);
	}
}

void sakujo(multiset<int>&used, multiset<int>&unused, int& num) {
	while (used.size() > num) {
		auto it = used.begin();
		ans -= *it;
		unused.insert(*it);
		used.erase(it);
	}
}

void irekae(multiset<int>&used, multiset<int>&unused, int& num) {
	while (!used.empty() && !unused.empty() && *unused.rbegin() > *used.begin()) {
		auto it = prev(unused.end());
		ans += *it;
		used.insert(*it);
		unused.erase(it);
		it = used.begin();
		ans -= *it;
		unused.insert(*it);
		used.erase(it);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	vector<set<int>>vs(2);
	int num = 0;
	multiset<int>used;
	multiset<int>unused;
	while (T--) {
		cin >> L >> R;
		ans += R;
		if (R < 0) {
			vs[L].erase(-R);
			if (L == 1) {
				num--;
				if (vs[L].empty()) {

				}
				else if (*vs[L].begin() > -R) {
					if (used.find(*vs[L].begin()) == used.end()) {
						unused.erase(unused.find(*vs[L].begin()));
					}
					else {
						ans -= *vs[L].begin();
						used.erase(used.find(*vs[L].begin()));
					}
				}
				else {
					if (used.find(-R) == used.end()) {
						unused.erase(unused.find(-R));
					}
					else {
						ans += R;
						used.erase(used.find(-R));
					}
				}
			}
			else {
				if (used.find(-R) == used.end()) {
					unused.erase(unused.find(-R));
				}
				else {
					used.erase(used.find(-R));
					ans += R;
				}
			}
			sakujo(used, unused, num);
			hojuu(used, unused, num);
			irekae(used, unused, num);
		}
		else {
			if (L == 1) {
				num++;
				if (!vs[L].empty() && *vs[L].begin() > R) {
					unused.insert(*vs[L].begin());
				}
				else if (vs[L].empty()) {

				}
				else if (*vs[L].begin()<R) {
					unused.insert(R);
				}
			}
			else {
				unused.insert(R);
			}
			hojuu(used, unused, num);
			irekae(used, unused, num);
			vs[L].insert(R);
		}
		cout << ans << endl;
	}
}