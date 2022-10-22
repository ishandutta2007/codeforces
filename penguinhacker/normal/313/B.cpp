#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	int m;
    string s;
	cin >> s >> m;
    
    int dp[100000];
    dp[0] = 0;
    for (int i=1; i<s.size(); ++i) {
        dp[i] = dp[i-1] + (s[i-1] == s[i]);
    }

    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << dp[b-1] - dp[a-1] << '\n';
    }
	return 0;
}