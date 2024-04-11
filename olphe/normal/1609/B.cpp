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
	cin >> N >> K;
	string s;
	cin >> s;
	set<int>st;
	for (int i = 0; i + 2 < s.size(); i++) {
		if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')st.insert(i);
	}
	while (K--) {
		cin >> L;
		char c;
		cin >> c;
		L--;
		s[L] = c;
		st.erase(L);
		st.erase(L - 1);
		st.erase(L - 2);
		for (int i = L - 2; i <= L; i++) {
			if (i < 0)continue;
			if (i + 2 >= s.size())break;
			if (s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')st.insert(i);
		}
		cout << st.size() << endl;
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