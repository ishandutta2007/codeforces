#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

int gcd(int a, int b) {
    if (a == 0 or b == 0)
        return a + b;
    return gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int r, b, k;
        cin >> r >> b >> k;

        int g = gcd(r, b);
        r /= g;
        b /= g;

        if (b > r)
            swap(r, b);

        if (k > (r - 1 + b - 1) / b)
            cout << "OBEY\n";
        else
            cout << "REBEL\n";
    }
    return 0;
}