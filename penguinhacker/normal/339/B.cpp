#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define arr array

int n, m, a, curr=1;
ll ans=0;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i=0; i<m; ++i) {
		cin >> a;
		ans+=(a>=curr?a-curr:a+n-curr);
		curr=a;
	}
	cout << ans;
	return 0;
}