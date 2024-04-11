#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    vector<long long> a(26);
    for (int i = 0; i < s.length(); i++) {
        a[(int)s[i] - 65] += 1;
    }

    sort(a.begin(), a.end());

    long long c = 0;
    for (int i = 25; i >= 0; i--) {
        if (a[i] <= k) {
            k -= a[i];
            c += a[i] * a[i];
        }
        else {
            c += k * k;
            break;
        }
    }

    cout << c;
    return 0;
}