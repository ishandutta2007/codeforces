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
const long double EPS = 1e-8;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	string s, t;
	cin >> s >> t;
	vector<int>v(N);
	for (int i = 0; i < N; i++) {
		if (i + M > N)break;
		string u;
		for (int j = 0; j < M; j++) {
			u.push_back(s[i + j]);
		}
		if (t == u)v[i]++;
	}
	for (int i = 1; i < N; i++) {
		v[i] += v[i - 1];
	}
	for (int i = 0; i < K; i++) {
		cin >> L >> R;
		L--;
		R--;
		R -= M - 1;
		if (R >= 0&&R>=L) {
			if (!L) {
				cout << v[R] << endl;
			}
			else {
				cout << v[R] - v[L - 1] << endl;
			}
		}
		else  {
			cout << 0 << endl;
		}
	}
	return 0;
}