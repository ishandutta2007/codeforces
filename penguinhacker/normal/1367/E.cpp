#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int t, n, k, cnt[26];
string s;

int gcd(int a, int b) {
	if (a<b) swap(a, b);
	if (a%b==0) return b;
	return gcd(b, a%b);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while(t--) {
		cin >> n >> k >> s;
		memset(cnt, 0, sizeof(cnt));
		for (char c : s)
			++cnt[c-'a'];
		int ans=0;
		for (int i=1; i<=n; ++i) {
			int x=i/gcd(i, k);
			int oc=0;
			for (int j=0; j<26; ++j)
				oc+=cnt[j]/x;
			if (oc>=gcd(i, k))
				ans=i;
		}
		cout << ans << '\n';
	}
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/