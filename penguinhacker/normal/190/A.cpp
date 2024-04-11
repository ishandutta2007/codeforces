#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	if (n==0&&m) {
		cout << "Impossible";
		return 0;
	}
	int a1=max(m, n);
	int a2=m?n+m-1:n;
	cout << a1 << ' ' << a2;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/