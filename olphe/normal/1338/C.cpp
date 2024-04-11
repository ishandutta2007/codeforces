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
constexpr double EPS = 1e-9;

//int N, M, K, H, W, L, R;
long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	vector<int>a({ 0,1,2,3 });
	vector<int>b({ 0,2,3,1 });
	vector<int>c({ 0,3,1,2 });
	cin >> K;
	while (K--) {
		cin >> N;
		if (N <= 3) {
			cout << N << endl;
			continue;
		}
		N--;
		long long int add = 1;
		long long int sum = 0;
		while (N / 3 >= add + sum) {
			sum += add;
			add <<= 2;
		}
		long long int ans = add * (N % 3 + 1);
		long long int amari =  N / 3-sum;
		add >>= 2;
		if (N % 3 == 0) {
			while (add) {
				ans += add * a[amari / add];
				amari %= add;
				add >>= 2;
			}
		}
		else if (N % 3 == 1) {
			while (add) {
				ans += add * b[amari / add];
				amari %= add;
				add >>= 2;
			}
		}
		else {
			while (add) {
				ans += add * c[amari / add];
				amari %= add;
				add >>= 2;
			}
		}
		cout << ans << endl;
	}
}