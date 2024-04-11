#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	int n, k, a[500];
	cin >> n >> k;
    for (int i=0; i<n; ++i) cin >> a[i];
    
    if (n == 1) {
        cout << 0 << '\n' << a[0] << '\n';
        return 0;
    }

    int count = 0;
    for (int i=1; i<n; ++i) {
        if (a[i]+a[i-1] < k) {
            count += k-a[i]-a[i-1];
            a[i] = k - a[i-1];
        }
    }

    cout << count << '\n';
    for (int i=0; i<n; ++i) cout << a[i] << ' ';
    cout << '\n';
	return 0;
}