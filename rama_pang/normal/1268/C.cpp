#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using lint = long long;

int N;
lint P[200005];
lint pos[200005];
lint ans[200005];

using namespace __gnu_pbds;
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// change null_type for map

lint BIT[200005];
void update(lint n, lint x) {
    for (int i = n; i < 200005; i += (i & -i)) {
        BIT[i] += x;
    }
}

lint sum(lint n) {
    lint res = 0;
    for (int i = n; i > 0; i -= (i & -i)) {
        res += BIT[i];
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> P[i];
        pos[P[i]] = i;
    }

    Tree<int> tree;
    auto arithmetic = [&](lint l, lint r) {
        return 1ll * (r - l + 1) * (l + r) / 2;
    };
    lint inversion = 0;

    for (int i = 1; i <= N; i++) {
        /* Count inversions */
        inversion += (int)tree.size() - tree.order_of_key(pos[i]);
        ans[i] = inversion;
        tree.insert(pos[i]);
        update(pos[i], pos[i]);

        /* Cost of making a contiguous segment */
        int id = tree.size() / 2;
        int mid = *tree.find_by_order(id);
        lint low, high;
        low = sum(mid - 1);
        high = sum(N) - sum(mid);

        ans[i] += 1ll * (mid - id) * id + arithmetic(0, id - 1) - low;
        ans[i] += high - arithmetic(id + 1, i - 1) - 1ll * (i - id - 1) * (mid - id);
    }


    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";

}