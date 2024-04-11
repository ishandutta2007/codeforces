#include <bits/stdc++.h>
#define int long long
#define pii pair<int, int>

using namespace std;
const int inf = 1e9 + 7;
const int max_n = 1e5 + 34;
int deg[max_n];

signed main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int a1, a2;
    cin >> a1 >> a2;
    if (a1 > a2 || (a2 - a1) % 2 == 1) {
    	cout << -1;
    	return 0;
    }
    int num1 = a1;
    int num2 = (a2 - a1) / 2;

 	if (a2 == 0) cout << 0;
 	else if (a2 == a1) cout << 1 << '\n' << num1;
	else if ((num1 & num2) == 0) cout << 2 << '\n' << num1 + num2 << " " << num2;
    else cout << 3 << '\n' << num1 << " " << num2 << " " << num2;
}