#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
typedef long long ll;
#define loop(i, a, n) for (int (i) = (a); (i) < (n); i++)
#define endl '\n'
using namespace std;

int main() {
	int n, cnt[100002] = { 0 }, a;
	ll dp[3];
	cin >> n;
	loop(i, 0, n) cin >> a, cnt[a]++;
	dp[1] = cnt[1], dp[2] = max(cnt[1], cnt[2] * 2);
	for (int i = 3; i <= 100000; i++)
		dp[i % 3] = max((ll)cnt[i] * i + dp[(i - 2) % 3], dp[(i - 1) % 3]);
	cout << dp[1] << endl;
}