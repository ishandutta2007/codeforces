#include "iostream"
#include "iomanip"
#include "climits"
#include "list"
#include "queue"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"

using namespace std;

int N,K;
int ans;

int main() {
	cin >> N >> K;
	K = 240 - K;
	ans = 0;
	while (1) {
		if ((ans + 1)*(ans + 2) / 2 * 5 > K) {
			cout << ans << "\n";
			return 0;
		}
		ans++;
		if (ans == N) {
			cout << ans << "\n";
			return 0;

		}
	}
	return 0;
}