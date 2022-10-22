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

using namespace std;

//const long long int MOD = 1000000007;
const long long int MOD = 1000003;
//const int MOD = 998244353;
//const long long int MOD = 998244353;

//long long int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<pair<pair<int, int>,int>>ru;
	vector<pair<pair<int, int>,int>>lu;
	for (int i = 1; i <= N; i++) {
		cin >> L >> R;
		if (R > L)ru.push_back({ { L,R },i });
		else lu.push_back({ { R,L },i });
	}
	if (ru.size() > lu.size()) {
		sort(ru.begin(), ru.end());
		reverse(ru.begin(), ru.end());
		cout << ru.size() << endl;
		for (auto i : ru)cout << i.second << " ";
		cout << endl;
	}
	else {
		sort(lu.begin(), lu.end());
		cout << lu.size() << endl;
		for (auto i : lu)cout << i.second << " ";
		cout << endl;
	}
}