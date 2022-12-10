#include <bits/stdc++.h>

using namespace std;

int n, a, b, k;
const int D = 1e9 + 7;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> a >> b >> k;
	vector<int> dp, s;
	dp.resize(n + 1, 1);
	s.resize(n + 1);
	dp[0] = dp[b] = 0;
	s[0] = 0;
	for(int i = 1; i <= n; i++)
		s[i] = s[i - 1] + dp[i];
	for(int i = 0; i < k; i++){
		vector<int> dp2(n + 1), s2(n + 1);
		s[0] = 0;
		for(int i = 1; i <= n; i++){
			dp2[i] = s[min(n, i + abs(i - b) - 1)] - s[max(0, i - abs(i - b))] - dp[i];
			dp2[i] %= D;
			dp2[i] += D;
			dp2[i] %= D;
			s2[i] = s2[i - 1] + dp2[i];
			s2[i] %= D;
		}
		dp = dp2;
		s = s2;
	}
	cout << (dp[a] + D) % D << endl;
	return 0;
}