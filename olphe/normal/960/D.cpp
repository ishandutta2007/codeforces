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

long long int N, M, K, H, W, L, R;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<long long int>shi(70);
	for (int i = 0; i < N; i++) {
		cin >> M;
		if (M == 1) {
			cin >> L >> R;
			int cnt = -1;
			while (L) {
				L >>= 1;
				cnt++;
			}
			cnt = max(cnt, 0);
			if (R < 0) {
				R = abs(R) % ((long long int)1 << cnt);
				R = ((long long int)1 << cnt) - R;
			}
			else {
				R %= (long long int)1 << cnt;
			}
			shi[cnt] += R;
			if (shi[cnt] >= (long long int)1 << cnt) {
				shi[cnt] -= (long long int)1 << cnt;
			}
		}
		else if (M == 2) {
			cin >> L >> R;
			int cnt = -1;
			while (L) {
				L >>= 1;
				cnt++;
			}
			cnt = max(cnt, 0);
			if (R < 0) {
				R = abs(R) % ((long long int)1 << cnt);
				R = ((long long int)1 << cnt) - R;
			}
			else {
				R %= (long long int)1 << cnt;
			}
			for (int j = cnt; j <= 60; j++) {
				shi[j] += R;
				if (shi[j] >= (long long int)1 << j) {
					shi[j] -= (long long int)1 << j;
				}
				R <<= 1;
			}
		}
		else {
			cin >> L;
			R = L;
			int cnt = -1;
			while (L) {
				L >>= 1;
				cnt++;
			}
			if (R == 1) {
				cout << 1 << endl;
				continue;
			}
			cout << R;
			R += shi[cnt];
			while (R >= (long long int)1 << (cnt + 1)) {
				R -= (long long int)1 << cnt;
			}
			cnt--;
			R >>= 1;
			while (cnt>0) {
				L = R;
				L -= shi[cnt];
				while (L < (long long int)1 << cnt) {
					L += (long long int)1 << cnt;
				}
				cout << " " << L;
				R >>= 1;
				cnt--;
			}
			cout << " 1" << endl;
		}
	}
	return 0;
}