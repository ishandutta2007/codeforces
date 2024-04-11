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
#include "ctime"

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> K;
	L = 1;
	R = N;
	string s;
	srand((unsigned int)time(NULL));
	if (!K) {
		L = 0;
		R = N;
		while (R - L > 1) {
			long long int mid = (L + R + 1) / 2;
			cout << 1 <<" " << mid << endl;
			cin >> s;
			if (s == "Yes") {
				if (L == mid) return 0;
				R = mid;
			}
			else {
				L = mid;
			}
		}
		cout << R << " " << R << endl;
		cin >> s;
		return 0;
	}
	for (int i = 0; i < 4500; i++) {
		if (R - L <= K * 5) {
			long long int box = L + (rand() % (R - L + 1));
			cout << box << " " << box << endl;
			cin >> s;
			if (s == "Yes") return 0;
			else {
				R += K;
				R = min(R, N);
				L -= K;
				L = max(1LL, L);
			}
		}
		else {
			long long int mid = (L + R) / 2;
			cout << L << " " << mid << endl;
			cin >> s;
			if (s == "Yes") {
				L -= K;
				R = mid + K;
			}
			else {
				L = mid - K;
				R += K;
			}
			L = max(1LL, L);
			R = min(R, N);
		}
	}
	
	return 0;
}