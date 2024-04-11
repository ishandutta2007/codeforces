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

using namespace std;

const long long int MOD = 1000000007;

long long int N, M, K, H, W, L, R;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	s = 'Q' + s;
	N = s.size();
	vector<int>num(N);
	for (int i = 1; i < N; i++) {
		num[i] = num[i - 1];
		if (s[i] == 'a') {
			num[i]++;
		}
	}
	int ans = 0;
	for (int i = 0; i <N ; i++) {
		for (int j = i; j < N; j++) {
			ans = max(ans, num[i] + j - i - num[j] + num[i] + num[N - 1] - num[j]);
		}
	}
	cout << ans << endl;
	return 0;
}