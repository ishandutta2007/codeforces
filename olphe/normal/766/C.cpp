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

int N;
char letter[2000];
int num[100];
int far[2000];
long long int dp[2000][2000] = {};
int ans;
int max_far;
int box;

int main() {
	cin >> N;
	cin >> letter;
	for (int i = 0; i < 26; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < N; i++) {
		far[i] = INT_MAX;
	}
	dp[0][1] = 1;
	max_far = 1;
	for (int i = 1; i <= num[letter[0] - 'a']; i++) {
		far[i] = num[letter[0] - 'a'];
	}
	for (int i = 1; i < N; i++) {
		for (int j = i; j <= i + num[letter[i] - 'a']; j++) {
			far[j] = min(far[j], num[letter[i] - 'a']);
		}
		for (int j = 1; j < N; j++) {
			dp[i][1] += dp[i - 1][j];
			dp[i][1] %= MOD;
			if (dp[i - 1][j] == 0)break;
		}
		for (int j = 2; j <= far[i]; j++) {
			dp[i][j] = dp[i - 1][j - 1];
			if(dp[i][j])max_far = max(max_far, j);
		}
	}
	for (int i = 1; i <= N; i++) {
		ans += dp[N - 1][i];
		ans %= MOD;
	}
	cout << ans << endl;
	cout << max_far << endl;
	box = N - 1;
	ans = 0;
	while (box>=0) {
		for (int i = N; i >= 0; i--) {
			if (dp[box][i]) {
				ans++;
				box -= i;
				break;
			}
		}
	}
	cout << ans << endl;
	return 0;
}