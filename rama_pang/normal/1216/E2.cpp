#include <bits/stdc++.h>
using namespace std;
using lint = long long;

/*  Let S(n) = 123...n
    Sum(n) = S(1) + S(2) + ... + S(N)

    Sum(n) > 1e18 at n = 482720320 



*/

lint pw(lint n, lint k) {
    if (k == 0) return 1;
    if (k & 1) return n * pw(n, k - 1);
    lint res = pw(n, k / 2);
    return res * res;
}

lint get_block_size_up_to_nth_block(lint n) { // n is included
    // n <= 10, return 1 + 2 + 3 + ... + (n - 1)
    // 10 < n <= 100, return get(10) * (n - 10) + 2 + 4 + 6 + ... + (2n - 2)
    lint lg = log10(n);
    lint add = 0;
    lint res = 0;
    for (lint len = 0; len <= lg; len++) {
        lint cnt = (len == lg)? n - lint(pw(10ll, len)) + 1 : lint(pw(10ll, len + 1)) - lint(pw(10ll, len));

        res += add * cnt + ((cnt * (cnt + 1)) / 2) * (len + 1);
        add += cnt * (len + 1);
    }

    return res;
}

lint get_in_block(lint n) {
    lint lg = log10(n);
    lint add = 0;
    lint res = 0;
    for (lint len = 0; len <= lg; len++) {
        lint cnt = (len == lg)? n - lint(pw(10ll, len)) + 1 : lint(pw(10ll, len + 1)) - lint(pw(10ll, len));
        res += cnt * (len + 1);
    }
    return res;
}

char solve(lint k) {
    lint le = 1, ri = 1e9;
    lint block = 0;
    while (le <= ri) {
        lint mid = (le + ri) / 2;
        if (get_block_size_up_to_nth_block(mid) >= k) {
            block = mid;
            ri = mid - 1;
        } else {
            le = mid + 1;
        }
    }

    k -= get_block_size_up_to_nth_block(block - 1);
    le = 1, ri = 1e9;
    lint ans = -1;
    while (le <= ri) {
        lint mid = (le + ri) / 2;
        if (get_in_block(mid) >= k) {
            ans = mid;
            ri = mid - 1;
        } else {
            le = mid + 1;
        }
    }

    return to_string(ans)[k - get_in_block(ans - 1) - 1];

}

int main() {
    lint q; cin >> q;
    for (int i = 0; i < q; i++) {
        lint k; cin >> k;
        cout << solve(k) << "\n";
    }
}