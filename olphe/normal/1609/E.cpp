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

class Add_Segment_Tree {
	vector<vector<vector<long long>>>v;
	long long int ret;
	int num;
	void Merge(int place) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j <= i; j++) {
				v[place][i][j] = MOD;
				for (int k = j; k <= i; k++) {
					v[place][i][j] = min(v[place][i][j], v[place * 2][k][j] + v[place * 2 + 1][i][k]);
				}
			}
		}
	}
public:
	Add_Segment_Tree(int n) {
		n++;
		num = 1;
		while (num < n * 2)num *= 2;
		v.resize(num, vector<vector<long long>>(3, vector<long long>(3)));
	}
	void Add(int place, long long int num) {
		place += v.size() / 2;
		for (auto& i : v[place])for (auto& j : i)j = MOD;
		if (num == 0) {
			v[place][0][0] = 1;
			v[place][1][0] = 0;
			v[place][1][1] = 0;
			v[place][2][1] = 1;
			v[place][2][2] = 0;
		}
		else if (num == 1) {
			v[place][0][0] = 0;
			v[place][1][0] = 1;
			v[place][1][1] = 1;
			v[place][2][1] = 0;
			v[place][2][2] = 0;
		}
		else {
			v[place][0][0] = 0;
			v[place][1][0] = 0;
			v[place][1][1] = 0;
			v[place][2][1] = 0;
			v[place][2][2] = 1;
		}
		place /= 2;
		while (place) {
			Merge(place);
			place /= 2;
		}
	//	for (int i = 1; i < v.size(); i ++) {
	//		cout << "---" << i << "---" << endl;
	//		for (auto j : v[i]) {
	//			for (auto k : j)cout << k << " ";
	//			cout << endl;
	//		}
	//	}
	}
	long long int Solve() {
		ret = min({ v[1][0][0] ,v[1][1][0],v[1][2][0] });
		return ret;
	}
};

void Solve() {
	cin >> N >> K;
	string s;
	cin >> s;
	Add_Segment_Tree asg(N);
	for (int i = 0; i < N; i++) {
		asg.Add(i, s[i] - 'a');
	}
	while (K--) {
		int p;
		cin >> p;
		p--;
		char c;
		cin >> c;
		asg.Add(p, c - 'a');
		cout << asg.Solve() << endl;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	T = 1;
//	cin >> T;
	while (T--) {
		Solve();
	}
}