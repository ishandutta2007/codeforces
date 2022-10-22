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
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N >> M >> L >> R;
		L--, R--;
		vector<vector<int>>edge(N);
		for (int i = 0; i < M; i++) {
			cin >> H >> W;
			H--, W--;
			edge[H].push_back(W);
			edge[W].push_back(H);
		}
		vector<int>a(N);
		vector<int>b(N);
		queue<int>Q;
		Q.push(L);
		a[L] = 1;
		while (!Q.empty()) {
			int cn = Q.front();
			Q.pop();
			for (auto i : edge[cn]) {
				if (i == R)continue;
				if (!a[i]) {
					a[i] = 1;
					Q.push(i);
				}
			}
		}
		Q.push(R);
		b[R] = 1;
		while (!Q.empty()) {
			int cn = Q.front();
			Q.pop();
			for (auto i : edge[cn]) {
				if (i == L)continue;
				if (!b[i]) {
					b[i] = 1;
					Q.push(i);
				}
			}
		}
		H = accumulate(a.begin(), a.end(),0);
		W = accumulate(b.begin(), b.end(),0);
		H--, W--;
		int box = H + W - N + 2;
		H -= box, W -= box;
		cout << H * W << endl;
	}
}