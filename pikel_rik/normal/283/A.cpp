#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;

const int N = 2e5 + 5;

int sz = 1, bit[N];

void add(int i, int val) {
    while (i < N) {
        bit[i] += val;
        i += i & -i;
    }
}

int sum(int i) {
    int sum = 0;

    while (i > 0) {
        sum += bit[i];
        i -= i & -i;
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n;
    cin >> n;

    cout << fixed << setprecision(10);

    double ans = 0;

    while (n--) {
        int t;
        cin >> t;

        if (t == 1) {
            int a, x;
            cin >> a >> x;

            add(1, x);
            add(a + 1, -x);

            ans = (sz * ans + a * x) / sz;
            cout << ans << "\n";
        }
        else if (t == 2) {
            int k;
            cin >> k;

            ans = (sz * ans + k) / (sz + 1);
            sz += 1;
            add(sz, k);
            add(sz + 1, -k);

            cout << ans << "\n";
        }
        else {
            int val = sum(sz);
            ans = (sz == 1 ? 0 : (sz * ans - val) / (sz - 1));
            add(sz, -val);
            add(sz + 1, val);

            sz -= 1;
            cout << ans << "\n";
        }
    }
    return 0;
}