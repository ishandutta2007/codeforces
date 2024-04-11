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

const long long int MOD = 1000000007;
//const int MOD = 998244353;
//const long long int MOD = 998244353;
const double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
 
	cin >> N >> M;
	deque<int>Q;
	for (int i = 0; i < N; i++) {
		cin >> K;
		Q.push_back(K);
	}
	vector<pair<int, int>>ans(N * 2);
	for (int i = 1; i < N * 2; i++) {
		int a = Q.front();
		Q.pop_front();
		int b = Q.front();
		ans[i] = make_pair(a, b);
		Q.pop_front();
		if (a > b) {
			Q.push_back(b);
			Q.push_front(a);
		}
		else {
			Q.push_back(a);
			Q.push_front(b);
		}
	}
	for (int i = 0; i < M; i++) {
		cin >> K;
		if (K < 2 * N)cout << ans[K].first << " " << ans[K].second << endl;
		else {
			long long amari = K - 2 * N;
			amari %= (N - 1);
			cout << Q.front() << " " << Q[amari + 1] << endl;
		}
	}
}