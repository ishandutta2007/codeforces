#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e6 + 5;

int n, a[N], bit[N];

void add(int i, int x){
    while (i < N) {
        bit[i] += x;
        i += i & -i;
    }
}

int sum(int i) {
    int ans = 0;
    while (i > 0) {
        ans += bit[i];
        i -= i & -i;
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int q;
    cin >> n >> q;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        add(x, 1);
    }

    int c = 0;
    while (q--) {
        int k;
        cin >> k;

        if (k > 0) {
            add(k, 1);
            c -= 1;
        }
        else {
            c += 1;
            k = -k;
            int lo = 1, hi = 1e6;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (sum(mid) >= k)
                    hi = mid;
                else lo = mid + 1;
            }

            add(lo, -1);
        }
    }

    int lo = 1, hi = 1e6;

    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (sum(mid) >= 1)
            hi = mid;
        else lo = mid + 1;
    }

    if (n - c > 0)
        cout << lo << "\n";
    else cout << "0\n";

    return 0;
}