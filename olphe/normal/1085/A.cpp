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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s, t;
	cin >> s;
	list<char>l;
	for (auto i : s)l.push_back(i);
	while (!l.empty()) {
		if (l.size() % 2) {
			t.push_back(l.front());
			l.pop_front();
		}
		else {
			t.push_back(l.back());
			l.pop_back();
		}
	}
	reverse(t.begin(), t.end());
	cout << t << endl;
	return 0;
}