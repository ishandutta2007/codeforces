#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, p, ans=0, lb=1e9, rb=-1;
string s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> p >> s, p--;
	if (p >= n/2) p = n-1-p;

	for (int i=0; i<n/2; ++i) {
		if (s[i] != s[n-1-i]) {
			lb = min(lb , i);
			rb = i;
			int change = max(s[i], s[n-1-i])-min(s[i],s[n-1-i]);
			ans += min(change, 26-change);
		}
	}
	if (lb == 1e9) ans = 0;
	else if (p < lb) ans += rb-p;
	else if (p > rb) ans += p-lb;
	else ans += rb-lb+min(rb-p, p-lb);
	
	cout << ans;
	return 0;
}