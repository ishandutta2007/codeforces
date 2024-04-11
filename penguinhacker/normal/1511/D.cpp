#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, k;
string ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i=0; ans.size()<n; i=(i+1)%k) {
		ans+=char('a'+i);
		ans+=char('a'+i);
		for (int j=2; j<k; ++j) {
			int g=__gcd(j, k);
			if (i<g) {
				int x=i;
				for (int l=1; l<=k/g; ++l) {
					x=(x+j)%k;
					ans+=char('a'+x);
				}
			}
		}
	}
	ans.resize(n);
	cout << ans;
	return 0;
}