#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, t, a[30000];
	cin >> n >> t;
    for (int i=0; i<n-1; ++i) cin >> a[i];
	
    int current = 0;
    bool pos = false;
    while(current < n) {
        if (current == t-1) {
            pos = true;
            break;
        }
        if (current == n-1) break;
        current += a[current];
    }
	
    if (pos) cout << "YES" << '\n';
    else cout << "NO" << '\n';
	return 0;
}