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
#include "cmath"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int gcd(int a, int b) {
	if (a < b) {
		swap(a, b);
	}
	int num = 0;
	while (b) {
		a %= b;
		swap(a, b);
		num++;
	}
	return a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>v(N);
	int one = 0;
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		if (v[i] == 1) {
			one++;
		}
	}
	if (one) {
		cout << N - one << endl;
		return 0;
	}
	int fig = 100000;
	for (int i = 1; i < N; i++) {
		int box = v[i - 1];
		for (int j = i; j < N; j++) {
			box = gcd(box, v[j]);
			if (box == 1) {
				fig = min(fig, j - i + 1);
			}
		}
	}
	if (fig==100000) {
		cout << "-1\n";
		return 0;
	}
	cout << N + fig - 1 << endl;
	return 0;
}