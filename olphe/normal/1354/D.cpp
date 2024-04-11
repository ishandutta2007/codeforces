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

int N, M, K, H, W, L, R;
//long long int N, M, K, H, W, L, R;

int a[1000005];
int b[1000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)cin >> a[i];
	for (int i = 0; i < K; i++)cin >> b[i];
	L = 0, R = 1000004;
	while (R - L > 1) {
		int num = 0;
		int mid = (R + L) / 2;
		for (int i = 0; i < N; i++)num += a[i] <= mid;
		for (int i = 0; i < K; i++) {
			if (b[i] > 0) {
				num += b[i] <= mid;
			}
			else {
				int box = -b[i];
				if (box <= num)num--;
			}
		}
	//	cout << mid << " " << num << endl;
		if (num > 0)R = mid;
		else L = mid;
	}
	if (R == 1000004)R = 0;
	cout << R << endl;
}