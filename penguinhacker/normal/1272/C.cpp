#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	int n, k;
    string s;
	cin >> n >> k >> s;
    char c[26];
    for (int i=0; i<k; ++i) cin >> c[i];

    ll ans = 0;
    ll cur = 0;
    for (int i=0; i<n; ++i) {
        bool isIn = false;
        for (int j=0; j<k; ++j) {
            if (s[i] == c[j]) {
                isIn = true;
                break;
            }
        }
        if (isIn) cur++;
        else {
            ans += cur*(cur+1)/2;
            cur = 0;
        }
    }
    ans += cur*(cur+1)/2;

	cout << ans << '\n';
	return 0;
}