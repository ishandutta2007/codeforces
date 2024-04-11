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

	cin >> N;
	vector<vector<int>>edge(N + 1);
	vector<int>dis(N + 1, INT_MAX);
	dis[1] = 0;
	for (int i = 0; i < N - 1; i++) {
		cin >> L >> R;
		edge[L].push_back(R);
		edge[R].push_back(L);
	}
	queue<int>Q;
	Q.push(1);
	while (!Q.empty()) {
		int cn = Q.front();
		Q.pop();
		for (auto i : edge[cn]) {
			if (dis[i] > dis[cn] + 1) {
				dis[i] = dis[cn] + 1;
				Q.push(i);
			}
		}
	}
	long long int odd = 0;
	long long int even = 0;
	for (int i = 1; i <= N; i++) {
		if (dis[i] % 2) {
			odd++;
		}
		else {
			even++;
		}
	}
	cout << odd*even - (N - 1) << endl;
	return 0;
}