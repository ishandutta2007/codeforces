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
const long double EPS = 1e-9;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M >> K;
	vector<long double>l;
	vector<long double>r;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		if (b == 1) {
			r.push_back(a);
		}
		else l.push_back(a);
	}
	sort(l.begin(), l.end());
	sort(r.begin(), r.end());
	int lindex = 0;
	long long int ans = 0;
	for (auto i : r) {
		while (1) {
			if (lindex == l.size()) {
				cout << ans << endl;
				return 0;
			}
			if (i > l[lindex]) {
				lindex++;
				continue;
			}
			if (l[lindex] < 0 && l[lindex] + M>0) {
				break;
			}
			long double dis = l[lindex] + M;
			long double t = (l[lindex] + M - i) / 2;
			//cout << dis / t << endl;
			if (abs(dis / t - 1) + EPS > K) {
				lindex++;
			}
			else break;
		}
		ans += l.size() - lindex;
		//cout << ans << endl;
	}
	cout << ans << endl;
	return 0;
}