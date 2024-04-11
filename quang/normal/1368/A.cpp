#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        int res=  0;
        while (1) {
            if (a < b) swap(a, b);
            if (a > c) break;
            b += a;
            res++;
        }
        cout << res << endl;
    }
    return 0;
}