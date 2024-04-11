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

long long int gcd(long long int a, long long int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> K;
	while (K--) {
		cin >> N;
		vector<long long int>w(N);
		for (auto &i : w)cin >> i;
		long long int fp, fm, sp, sm;
		cin >> fp >> fm >> sp >> sm;
		cin >> M;
		L = 0;
		R = N+1;
		sort(w.begin(), w.end());
		reverse(w.begin(), w.end());
		while (R - L > 1) {
			//cout << "L R " << L << " " << R << endl;
			int mid = (R + L) / 2;
			vector<long long int>v;
			for (int i = 0; i < mid; i++)v.push_back(w[i]);
			sort(v.begin(), v.end());
			long long int lcm = fm * sm / gcd(fm, sm);
			long long int num = mid / lcm;
			long long int sum = 0;
			for (int i = 0; i < num; i++) {
				sum += v.back() * (fp + sp) / 100;
				v.pop_back();
			}
			if (sp > fp) {
				swap(sp, fp);
				swap(fm, sm);
			}
			for (int i = 0; i < mid / fm - num; i++) {
				sum += v.back()*fp / 100;
				v.pop_back();
			}
			for (int i = 0; i < mid / sm - num; i++) {
				sum += v.back()*sp / 100;
				v.pop_back();
			}
			//cout << sum << endl;
			if (sum < M) {
				L = mid;
			}
			else {
				R = mid;
			}
		}
		if (R == N + 1) {
			cout << -1 << endl;
		}
		else {
			cout << R << endl;
		}
	}
}