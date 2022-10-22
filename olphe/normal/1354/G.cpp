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

int N, M, K, H, W, L, R;
//long long int N, M, K, H, W, L, R;

string Ask(const vector<int>&a, const vector<int>&b) {
	cout << "? " << a.size() << " " << a.size() << endl;
	for (int i = 0; i < a.size(); i++) {
		if (i)cout << " ";
		cout << a[i];
	}
	cout << endl;
	for (int i = 0; i < a.size(); i++) {
		if (i)cout << " ";
		cout << b[i];
	}
	cout << endl;
	string s;
	cin >> s;
	return s;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N >> M;
		L = 1, R = N + 1;
		while (R - L > 1) {
			vector<int>a;
			vector<int>b;
			int mid = (R + L) / 2;
			for (int i = L; i < mid; i++)a.push_back(i);
			for (int i = mid; i < R; i++)b.push_back(i);
			auto s = Ask(a, b);
			if (s[0] == 'W')return 0;
			if (s[0] == 'S'||s[0]=='E')L = mid;
			else R = mid;
			if ((R - L) % 2&&R-L>1) {
				if (R != N + 1)R++;
				else L--;
			}
		}
		vector<int>flag(N + 1, 0);
		flag[L] = 1;
		vector<int>stone(1, L);
		vector<int>cand;
		while (cand.empty()) {
			vector<int>a;
			for (int i = 1; i <= N; i++) {
				if (flag[i])continue;
				a.push_back(i);
				flag[i] = 1;
				if (a.size() == stone.size())break;
			}
			auto s = Ask(a, stone);
			if (s[0] == 'W') return 0;
			if (s[0] == 'S') {
				cand = a;
				break;
			}
			for (auto i : a)stone.push_back(i);
		}
		while (cand.size() > 1) {
			int mid = cand.size() / 2;
			auto a = cand;
			a.resize(mid);
			auto s = Ask(a, stone);
			if (s[0] == 'W') return 0;
			if (s[0] == 'S') {
				cand = a;
			}
			else {
				vector<int>nx;
				for (int i = mid; i < cand.size(); i++)nx.push_back(cand[i]);
				cand = nx;
			}
		}
		cout << "! " << cand[0] << endl;
	}
}