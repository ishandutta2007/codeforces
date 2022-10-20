#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 10;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        long long a[20];
        for(int i = 0; i < n; i++) cin >> a[i];
        long long p = 1;
        for(int i = 0; i < n; i++) {
            while(a[i]%2 == 0) {
                p *= 2;
                a[i] /= 2;
            }
        }
        sort(a, a+n);
        p -= 1;
        long long s = 0;
        for(int i = 0; i < n; i++) {
            s += a[i];
        }
        s += p * a[n-1];
        cout << s << endl;
    }
    return 0;
}