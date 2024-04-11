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
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		cin >> N;
		vector<int>num(N + 1);
		for (int i = 0; i < N; i++) {
			cin >> M;
			num[M]++;
		}
		L = 0, R = N - 1;
		while (R - L > 1) {
			int mid = (R + L) / 2;
			priority_queue<pair<int, int>>PQ;
			for (int i = 1; i <= N; i++) {
				if (num[i]) {
					PQ.push({ num[i],i });
				}
			}
			vector<pair<int, int>>in(N, {-1,-1});
			bool flag = true;
			for (int i = 0; i < N; i++) {
				if (PQ.empty()) {
					flag = false;
					break;
				}
				auto box = PQ.top();
				PQ.pop();
				if (box.first > 1) {
					box.first--;
					if (i + mid < N)in[i + mid] = box;
				}
				if (in[i].first != -1) {
					PQ.push(in[i]);
				}
			}
			if (flag)L = mid;
			else R = mid;
		}
		cout << L << endl;
	}
}