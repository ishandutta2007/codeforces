#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n;
int a[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    long long tot = 0;
    long long res = 0;
    for (int i = n; i; i--) {
        tot += a[i] / 2;
        if (a[i] % 2 && tot > 0) {
            res++;
            tot--;
        }
    }
    res += tot * 2 / 3;
    cout << res << endl;
    return 0;
}