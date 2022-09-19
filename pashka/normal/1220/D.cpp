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

    int n;
    cin >> n;
    vector<long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    map<int, vector<long>> m;
    int t = 0;
    int max = 0;
    for (int i = 0; i < n; i++) {
        int k = 0;
        long x = a[i];
        while (x % 2 == 0) {
            x /= 2;
            k++;
        }
        m[k].push_back(a[i]);
        if (m[k].size() > max) {
            max = m[k].size();
            t = k;
        }
    }
    cout << n - m[t].size() << "\n";
    for (auto p : m) {
        if (p.first == t) continue;
        for (long x : p.second) {
            cout << x << " ";
        }
    }

    return 0;
}