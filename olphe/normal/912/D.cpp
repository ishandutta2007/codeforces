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

	cin >> N >> M >> K >> H;
	vector<long long int>x(50001);
	vector<long long int>y(50001);
	long long int x_max = 0;
	long long int y_max = 0;
	for (long long int i = 1; i <= N; i++) {
		long long int box = min({ i, N - K + 1,K, N + 1 - i });
		x[box]++;
		x_max = max(x_max, box);
	}
	for (long long int i = 1; i <= M; i++) {
		long long int box = min({ i, M - K + 1,K, M + 1 - i });
		y[box]++;
		y_max = max(y_max, box);
	}
	long long int get = 0;
	long long int num = 0;
	priority_queue<pair<long long int, int>>PQ;
	for (long long int i = 1; i <= x_max; i++) {
		PQ.push({ i*y_max,i });
	}
	while (!PQ.empty()) {
		auto box = PQ.top();
		long long int cx = box.second;
		long long int cy = box.first / cx;
		PQ.pop();
		PQ.push({ cx*(cy - 1),cx });
		long long int add = x[cx] * y[cy];
		if (add + num <= H) {
			num += add;
			get += add*box.first;
		}
		else {
			get += box.first*(H - num);
			break;
		}
	}
	long double ans = get;
	long double divide = (N - K + 1)*(M - K + 1);
	cout << setprecision(15) << ans / divide << endl;
	return 0;
}