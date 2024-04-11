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
constexpr double EPS = 1e-5;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

class Segment_Tree {
	vector<vector<long long int>>mi;
	vector<vector<long long int>>ma;
	int num;
	bool is_min;
public:
	Segment_Tree(int n) {
		n++;
		num = 1;
		while (num < n * 2) {
			num *= 2;
		}
		mi.resize(2, vector<long long int>(num, 0));
		ma.resize(2, vector<long long int>(num, 0));
		for (int i = 0; i < num; i++) {
			mi[1][i] = MOD * MOD;
			ma[1][i] = -MOD * MOD;
		}
	}
	void Insert(int place, long long int num) {
		place += mi[0].size() / 2;
		mi[1][place] = num;
		ma[1][place] = num;
		place /= 2;
		while (place) {
			mi[0][place] = min({ mi[0][place * 2] + mi[0][place * 2 + 1],mi[1][place * 2] - ma[1][place * 2 + 1] });
			mi[1][place] = min({ mi[1][place * 2] - ma[0][place * 2 + 1],mi[0][place * 2] + mi[1][place * 2 + 1] });
			ma[0][place] = max({ ma[0][place * 2] + ma[0][place * 2 + 1],ma[1][place * 2] - mi[1][place * 2 + 1] });
			ma[1][place] = max({ ma[1][place * 2] - mi[0][place * 2 + 1],ma[0][place * 2] + ma[1][place * 2 + 1] });
			place /= 2;
		}
	}
	long long int RMQ() {
		return ma[1][1];
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N >> K;
		vector<int>v(N);
		for (auto &i : v)cin >> i;
		Segment_Tree sg(N);
		for (int i = 0; i < N; i++) {
			sg.Insert(i, v[i]);
		}
		cout << sg.RMQ() << endl;
		while (K--) {
			cin >> L >> R;
			L--, R--;
			swap(v[L], v[R]);
			sg.Insert(L, v[L]);
			sg.Insert(R, v[R]);
			cout << sg.RMQ() << endl;
		}
	}
}