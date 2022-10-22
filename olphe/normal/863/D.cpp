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
#include "iomanip"
#include "random"

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 0.00000001;
const long double PI = 3.1415926535897932384626433;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	vector<int>num(N+1);
	for (int i = 1; i <= N; i++) {
		cin >> num[i];
	}
	vector<int>query(M);
	vector<int>l(M);
	vector<int>r(M);
	for (int i = 0; i < M; i++) {
		cin >> query[i] >> l[i] >> r[i];
	}
	vector<int>ans(K);
	for (int i = 0; i < K; i++) {
		cin >> L;
		int box = L;
		for (int j = M - 1; j >= 0; j--) {
			if (box<l[j] || box>r[j]) {
				continue;
			}
			if (query[j] == 1) {
				box--;
				if (box < l[j]) {
					box = r[j];
				}
			}
			else {
				box = l[j] + r[j] - box;
			}
		}
		ans[i] = num[box];
	}
	for (int i = 0; i < K; i++) {
		if (i)cout << " ";
		cout << ans[i];
	}
	cout << endl;
	return 0;
}