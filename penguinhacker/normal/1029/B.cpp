#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int n, a[200000];
	cin >> n;
	for (int i=0; i<n; ++i) cin >> a[i];
	
    int ans = 1;
    int current = 1;
    for (int i=n-2; i>=0; --i) {
        if (a[i+1] <= 2*a[i]) current++;
        else {
            ans = max(ans, current);
            current = 1;
        }
    }
    ans = max(ans, current);

    cout << ans << '\n';
	return 0;
}