#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    long n;
    int m;
    long k;
    cin >> n >> m >> k;
    vector<long> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        a[i]--;
    }
    long c = 0;
    long res = 0;
    for (int i = 0; i < m; i++) {
        res++;
        long x = (a[i] - c) / k;
        int cc = 1;
        while (i + 1 < m && ((a[i + 1] - c) / k) == x) {
            i++;
            cc++;
        }
        c += cc;
    }
    cout << res << "\n";

    return 0;
}