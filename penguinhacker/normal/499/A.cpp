#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, x, cur=1, ans=0;
	cin >> n >> x;
	while(n--) {
		int l, r;
		cin >> l >> r;
		while(cur<=r) {
			if (cur+x<=l)
				cur+=x;
			else
				++ans, ++cur;
		}
	}
	cout << ans;
	return 0;
}