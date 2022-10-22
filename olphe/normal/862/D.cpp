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
#include "random"

using namespace std;

const long long int MOD = 1000000007;
const long double EPS = 0.00000001;
const long double PI = 3.1415926535897932384626433;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	int one, zero;
	cout << "? ";
	for (int i = 0; i < N; i++) {
		cout << "0";
	}
	cout << endl;
	cin >> M;
	one = M;
	zero = N - M;
	cout << "? 1";
	for (int i = 1; i < N; i++) {
		cout << "0";
	}
	cout << endl;
	cin >> K;
	int o_place = 0;
	int z_place = 0;
	if (M > K) {
		o_place = 1;
	}
	else {
		z_place = 1;
	}
	if (!z_place) {
		L = 1;
		R = N + 1;
		while (R - L > 1) {
			int mid = (L + R + 1) / 2;
			cout << "? ";
			for (int i = 1; i < L; i++) {
				cout << "0";
			}
			for (int i = L; i < mid; i++) {
				cout << "1";
			}
			for (int i = mid; i <= N; i++) {
				cout << "0";
			}
			cout << endl;
			cin >> W;
			if (M - (mid - L) != W) {
				R = mid;
			}
			else {
				L = mid;
			}
		}
		z_place = L;
	}
	else {
		L = 1;
		R = N + 1;
		while (R - L > 1) {
			int mid = (L + R + 1) / 2;
			cout << "? ";
			for (int i = 1; i < L; i++) {
				cout << "0";
			}
			for (int i = L; i < mid; i++) {
				cout << "1";
			}
			for (int i = mid; i <= N; i++) {
				cout << "0";
			}
			cout << endl;
			cin >> W;
			if (M + (mid - L) != W) {
				R = mid;
			}
			else {
				L = mid;
			}
		}
		o_place = L;
	}
	cout << "! " << z_place << " " << o_place << endl;
	return 0;
}