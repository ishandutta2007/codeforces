#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5 + 5;

ll n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int sum = (accumulate(a, a + n, 0LL) + n - 2) / (n - 1);

    if (sum < *max_element(a, a + n))
        cout << *max_element(a, a + n);
    else cout << sum;
    return 0;
}