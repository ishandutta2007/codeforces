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
//constexpr int MOD = 998244353;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

void Solve() {
	cin >> N >> M;
	string s;
	cin >> s;
	if (N % M) {
		cout << -1 << endl;
		return;
	}
	set<int>st;
	int idx = -1, nx = -1;
	vector<int>use(256);
	for (int i = 0; i < N; i++) {
		for (int j = 'z'; j >= s[i]+(i+1!=N); j--) {
			use[j]++;
			int add = 0;
			int sum = 0;
			for (int k = 'a'; k <= 'z'; k++) {
				sum += use[k];
				add += (M - use[k] % M) % M;
			}
			if (sum + add <= N) {
				idx = i, nx = j;
			}
			use[j]--;
		}
		use[s[i]]++;
	}
	if (idx == -1) {
		cout << -1 << endl;
		return;
	}
	vector<int>used(256);
	string fst;
	string snd;
	for (int i = 0; i < idx; i++) {
		fst.push_back(s[i]);
		used[s[i]]++;
	}
	fst.push_back(nx);
	used[nx]++;
	for (auto i : fst)st.insert(i);
	for (auto i : st) {
		while (used[i] % M) {
			used[i]++;
			snd.push_back(i);
		}
	}
	while (fst.size() + snd.size() < N) {
		fst.push_back('a');
	}
	cout << fst + snd << endl;
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