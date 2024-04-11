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

	cin >> N;
	vector<long long int>v(N*2);
	for (int i = 0; i < N*2; i++)cin >> v[i];
	sort(v.begin(), v.end());
	L = v[0];
	R = v[N - 1];
	long long int l = v[N];
	long long int r = v.back();
	long long int ans = (R - L)*(r - l);
	for (int i = 0; i < N - 1; i++) {
		L = v[i + 1];
		R = v[i + N];
		l = min(l, v[i]);
		ans = min(ans, (R - L)*(r - l));
	}
	cout << ans << endl;
	return 0;
}