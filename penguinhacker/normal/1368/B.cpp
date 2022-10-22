#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

ll n, cnt[10];
string s, c="codeforces";

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	fill(cnt, cnt+10, 1);
	ll cur=1;
	while (cur<n) {
		for (int i=0; i<10; ++i) {
			++cnt[i];
			cur=cur*cnt[i]/(cnt[i]-1);
			if (cur>=n)
				break;
		}
	}
	for (int i=0; i<10; ++i)
		for (int j=0; j<cnt[i]; ++j)
			cout << c[i];
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/