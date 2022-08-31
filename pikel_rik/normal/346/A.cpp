#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 5e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    int g = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        g = __gcd(g, a[i]);
    }

    int m = *max_element(all(a));
    int val = (m / g - n);

    if (val % 2 == 0)
        cout << "Bob\n";
    else cout << "Alice\n";

    return 0;
}