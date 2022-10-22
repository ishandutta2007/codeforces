#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	int n, x[100000];
	cin >> n;
    for (int i=0; i<n; ++i) cin >> x[i];
    sort(x, x+n);
    int q;
    cin >> q;
    while (q--) {
        int a;
        cin >> a;
        cout << upper_bound(x, x+n, a)-x << '\n';
    }
	return 0;
}