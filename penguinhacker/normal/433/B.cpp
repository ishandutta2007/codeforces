#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, a[100000], b[100000];
ll dp1[100001], dp2[100001];
int main() {
	cin >> n;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b, b+n);

    dp1[0] = 0;
    dp2[0] = 0;
    
    for (int i=1; i<=n; ++i) {
        dp1[i] = dp1[i-1] + a[i-1];
        dp2[i] = dp2[i-1] + b[i-1];
    }

    int t;
    cin >> t;
    while (t--) {
        int type, l, r;
        cin >> type >> l >> r;
        if (type == 1) {
            cout << dp1[r] - dp1[l-1] << '\n';
        }
        else {
            cout << dp2[r] - dp2[l-1] << '\n';
        }
    }
	
	return 0;
}