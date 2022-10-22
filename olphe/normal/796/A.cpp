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

int N,M,K;
int num[200];
int ans = INT_MAX;

int main(){
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)cin >> num[i];
	for (int i = M + 1; i <= N; i++) {
		if (num[i] && num[i] <= K) {
			ans = i - M;
			break;
		}
	}
	for (int i = M - 1; i > 0; i--) {
		if (num[i] && num[i] <= K) {
			ans = min(ans, M - i);
			break;
		}
	}
	cout << ans * 10 << endl;
	return 0;
}