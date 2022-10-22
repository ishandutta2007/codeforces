#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int main() {
	int n, k, h[150000];
	cin >> n >> k;
    for (int i=0; i<n; ++i) cin >> h[i];

    int sum = 0;
    for (int i=0; i<k; ++i) sum+=h[i];

    int L = sum;
    int ans = 1;
    for (int i=0; i<n-k; ++i) {
        sum += h[i+k] - h[i];
        if (sum < L) {
            L = sum;
            ans = i+2;
        }
    }
	
    cout << ans << '\n';
	return 0;
}