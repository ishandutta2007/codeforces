#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"
#include "string"
#include "map"
#include "unordered_map"
#include "iomanip"
#include "random"

using namespace std;
const long long int MOD = 1000000007;

long long int power(long long int x, long long int n, long long int M) {
	long long int tmp = 1;

	if (n > 0) {
		tmp = power(x, n / 2, M);
		if (n % 2 == 0) tmp = (tmp*tmp) % M;
		else tmp = (((tmp*tmp) % M)*x) % M;
	}
	return tmp;
}

long long int N, M, K, Q, W, H, L, R;
long long int ans;



int main() {
	ios::sync_with_stdio(false);
	cin >> N >> M;
	L = N;
	R = M;
	if (R > L)swap(R, L);
	while (R) {
		L %= R;
		swap(R, L);
	}
	N /= L;
	M /= L;
	while (M) {
		if (M%N == 0) {
			ans += M / N;
			break;
		}
		long long int box =LLONG_MAX;
		list<long long int>div;
		for (long long int i = 2; i <= sqrt(N); i++) {
			if (N%i == 0) {
				div.push_back(i);
				div.push_back(N / i);
			}
		}
		div.push_back(N);
		for (auto i : div) {
			box = min(box, M%i);
		}
		ans += box;
		M -= box;
		L = N;
		R = M;
		if (L < R)swap(L, R);
		while (R) {
			L %= R;
			swap(L, R);
		}
		N /= L;
		M /= L;
	//	cout << N << " " << M << endl;
	}
	cout << ans << endl;
	return 0;
}