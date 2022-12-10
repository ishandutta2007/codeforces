#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

const int maxn = 2e3 + 10;
int dp[maxn], pd[maxn];
ll ans;
string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> s;
	for(int cen = 0; cen < s.size(); cen++)
		for(int i = 0; cen + i < s.size() and cen - i >= 0 and s[cen - i] == s[cen + i]; i++)
			dp[cen - i]++, pd[cen + i]++;
	for(int cen = 0; cen < s.size() - 1; cen++)
		for(int i = 0; cen - i >= 0 and cen + i + 1 < s.size() and s[cen - i] == s[cen + i + 1]; i++)
			dp[cen - i]++, pd[cen + i + 1]++;
	ll sum = 0;	
	for(int i = (int)s.size() - 1; i >= 0; i--){
		sum += dp[i + 1];
		ans += 1LL * pd[i] * sum;
	}
	cout << ans << endl;
	return 0;
}