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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	set<int>o;
	set<int>z;
	N = s.size();
	for (int i = 0; i < N; i++) {
		if (s[i] == '0') {
			z.insert(i);
		}
		else {
			o.insert(i);
		}
	}
	M = (int)z.size() - (int)o.size();
	if (M <= 0) {
		cout << -1 << endl;
		return 0;
	}
	vector<vector<int>>ret(M);
	K = N - M;
	if (K & 1) {
		cout << -1 << endl;
		return 0;
	}
	K /= 2;
	for (int i = 0; i < M; i++) {
		ret[i].push_back(*z.begin());
		z.erase(z.begin());
		while (K) {
			auto box = o.upper_bound(ret[i].back());
			if (box == o.end()) {
				break;
			}
			auto bag = z.upper_bound(*box);
			if (bag == z.end()) {
				break;
			}
			K--;
			ret[i].push_back(*box);
			ret[i].push_back(*bag);
			o.erase(box);
			z.erase(bag);
		}
	}
	if (!o.empty() || !z.empty()) {
		cout << -1 << endl;
		return 0;
	}
	cout << M << endl;
	for (auto i : ret) {
		cout << i.size();
		for (auto j : i) {
			cout << " " << j + 1;
		}
		cout << endl;
	}
	return 0;
}