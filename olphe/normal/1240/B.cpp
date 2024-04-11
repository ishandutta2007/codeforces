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
#include "functional"
#include "ctime"

using namespace std;

//constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N;
		vector<long long int>v(N);
		for (auto &i : v)cin >> i;
		vector<int>l(N + 1, MOD);
		vector<int>r(N + 1, -1);
		for (int i = 0; i < N; i++) {
			l[v[i]] = min(l[v[i]], i);
			r[v[i]] = max(r[v[i]], i);
		}
		int num = 0;
		for (int i = 0; i <= N; i++) {
			num += l[i] != MOD;
		}
		int ans = num - 1;
		int used = 0;
		int bef = 0;
		//cout << "num " << num << endl;
		//r[0] = MOD;
		for (int i = 1; i <= N; i++) {
			if (l[i] == MOD)continue;
		//	cout << i << " " << l[i] << " " << r[i] << endl;
			if (r[bef] > l[i]) {
				ans = min(ans, num - used);
				used = 1;
				bef = i;
			}
			else {
				used++;
				bef = i;
			}
			//cout << i << " " << used << endl;
		}
		ans = min(ans, num - used);
		cout << ans << endl;
	}
}