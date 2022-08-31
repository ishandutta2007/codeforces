#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int a, b;
    cin >> a >> b;

    int g = __gcd(a, b);

    vector<int> div;
    for (int i = 1; i * (ll)i <= g; i++) {
        if (g % i == 0) {
            div.push_back(i);
            if (i != g / i)
                div.push_back(g / i);
        }
    }

    sort(all(div));

    int n;
    cin >> n;

    while (n--) {
        int l, r;
        cin >> l >> r;

        int it = lower_bound(all(div), l) - div.begin();

        if (it == div.size() or div[it] > r) {
            cout << "-1\n";
            continue;
        }

        int lo = it, hi = div.size() - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (div[mid] > r)
                hi = mid - 1;
            else lo = mid;
        }

        cout << div[lo] << "\n";
    }
    return 0;
}