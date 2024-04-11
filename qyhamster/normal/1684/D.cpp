#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
long long a[maxn];
int main() {
    int T;
    cin >> T;
    while(T--) {
        long long n,k;
        cin >> n >> k;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++) a[i] += i;
        long long ans = -((n-k)*(n-k-1)/2);
        sort(a, a+n);
        for(int i = 0; i < n-k; i++) ans += a[i];
        cout << ans << endl;
    }
}