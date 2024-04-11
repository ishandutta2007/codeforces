#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	string s;
	cin >> s;
	
    int n = s.size();

    if (n <= 2) {
        cout << 0 << '\n';
        return 0;
    }

    //dp counts number of "QA" is the first n letters and stores
    int q, dp[100];

    dp[0] = 0;
    q = s[0] == 'Q';
    for (int i=1; i<n; ++i) {
        dp[i] = dp[i-1];
        if (s[i] == 'A') dp[i] += q;
        else if (s[i] == 'Q') q++;
    }

    int count = 0;
    for (int i=1; i<n; ++i) {
        count += dp[i-1]*(s[i] == 'Q');
    }

    cout << count << '\n';
	return 0;
}