#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int t;
	cin >> t;
	
    while (t--) {
        int n, m, a[100000];
        cin >> n >> m;
        int total = 0;
        for (int i=0; i<n; ++i) {
            cin >> a[i];
            total+=a[i];
        }
        if (n!=m || n==2) {
            cout << -1 << '\n';
            continue;
        }
        cout << 2*total << '\n';
        for (int i=1; i<n; ++i) {
            cout << i << ' ' << i+1 << '\n';
        }
        cout << n << ' ' << 1 << '\n';
    }
	return 0;
}