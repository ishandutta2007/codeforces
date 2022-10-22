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

	cin >> N >> R;
	vector<int>v(N);
	vector<long double>ans(N);
	vector<long double>xh(1001);
	vector<bool>flag(1001);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	ans[0] = R;
	xh[v[0]] = R;
	flag[v[0]] = true;
	for (int i = 1; i < N; i++) {
		long double box = 0;
		long double x = v[i];
		for (int j = max(0, v[i] - (int)R * 2); j <= min(1000, v[i] + (int)R * 2); j++) {
			double w = j;
			double h = sqrt((long double)R*(long double)R * 4 - (w - x)*(w - x));
			if (flag[j]) {
				box = max(box, xh[j] + h);
			}
			else {
				box = max(box, (long double)R);
			}
		}
		ans[i] = box;
		xh[v[i]] = ans[i];
		flag[v[i]] = true;
	}
	for (int i = 0; i < N; i++) {
		if (i) {
			cout << " ";
		}
		cout << setprecision(15) << ans[i];
	}
	cout << endl;
	return 0;
}