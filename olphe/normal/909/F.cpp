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
#include "iomanip"
#include "cmath"
#include "random"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int two[20] = {};
	two[0] = 1;
	for (int i = 1; i < 20; i++) {
		two[i] = two[i - 1] * 2;
	}
	if (N % 2) {
		cout << "NO\n";
	}
	else {
		for (int i = 0; i < 20; i++) {
			if (N >= two[i]) {
				M = two[i] * 2;
			}
		}
		vector<int>v(N + 1);
		for (int i = 1; i <= N; i++) {
			v[i] = i ^ (M - 1);
		}
		vector<vector<int>>husoku(20);
		for (int i = 1; i < M - 1 - N; i++) {
			husoku[0].push_back(i);
		}
		int xornum = 0;
		for (int i = 0; i < 20; i++) {
			if (husoku[0].size() >= two[i]) {
				xornum = two[i] * 2;
			}
		}
		xornum-=2;
		for (int loop = 1;; loop++) {
			if (husoku[loop-1].empty()) {
				break;
			}
			for (auto i : husoku[loop - 1]) {
				if (v[xornum]<=N) {
					husoku[loop].push_back(v[xornum]);
				}
				v[xornum] = i;
				xornum--;
			}
			for (int i = 0; i < 20; i++) {
				if (husoku[loop].size() >= two[i]) {
					xornum = two[i] * 2;
				}
			}
			xornum-=2;
		}
		cout << "YES\n";
		for (int i = 1; i <= N; i++) {
			if (i > 1) {
				cout << " ";
			}
			int a = i&v[i];
			cout << v[i];
			//cout << a;
		}
		cout << endl;
	}
	if (N <= 5) {
		cout << "NO\n";
		return 0;
	}
	for (int i = 0; i < 20; i++) {
		if (N == two[i]) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	vector<int>v(N + 1);
	for (int i = 1; i <= N; i++) {
		v[i] = i;
	}
	v[1] = 5;
	v[2] = 3;
	v[3] = 2;
	v[4] = 6;
	v[5] = 1;
	v[6] = 4;
	if (N % 2) {
		for (int i = 6; i < N; i += 2) {
			swap(v[i], v[i + 1]);
		}
	}
	else if(N>6){
		for (int i = 6; i < N; i += 2) {
			swap(v[i], v[i + 1]);
		}
		for (int i = 0; i < 20; i++) {
			if (N > two[i]) {
				M = two[i];
			}
		}
		swap(v[N], v[N - M]);
	}
	for (int i = 1; i <= N; i++) {
		if (i > 1) {
			cout << " ";
		}
		int a = v[i] & i;
		cout << v[i];
	}
	cout << endl;
	return 0;
}