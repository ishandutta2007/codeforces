#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "set"
#include "functional"
#include "algorithm"
#include "math.h"
#include "utility"

using namespace std;
const long long int MOD = 1000000007;

int N, M, Z;
int ans;

int main() {
	cin >> N >> M >> Z;
	for (int i = N; i <= Z; i+=N) {
		if (i%M == 0) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}