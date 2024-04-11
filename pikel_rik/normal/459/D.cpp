#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef tree <int, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef unsigned long long ull;
typedef long long ll;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e6 + 5;

int n, a[N], cnt[N], suf[N], bit[N], arr[N], sz;

void add(int i, int val) {
    i++;
    while (i <= n) {
        bit[i] += val;
        i += i & -i;
    }
}

int get(int i) {
    int sum = 0;

    while (i > 0) {
        sum += bit[i];
        i -= i & -i;
    }
    return sum;
}

int sum(int i, int j) {
    return get(j) - get(i);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], arr[sz++] = a[i];

    sort(arr, arr + sz);
    sz = unique(arr, arr + n) - arr;

    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(arr, arr + sz, a[i]) - arr;
    }

    for (int i = n - 1; i >= 0; i--) {
        cnt[a[i]] += 1;
        add(cnt[a[i]], 1);

        suf[i] = cnt[a[i]];
    }

    ll ans = 0;
    memset(cnt, 0, sizeof(cnt));

    for (int i = 0; i < n; i++) {
        add(suf[i], -1);
        cnt[a[i]] += 1;
        ans += sum(1, cnt[a[i]]);
    }

    cout << ans << "\n";
    return 0;
}