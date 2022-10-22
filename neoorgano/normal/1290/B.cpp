#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5, K = 400;
int ans[MAXN], cnt[MAXN], cur = 1;

string s;

bool cmp(array<int, 3> a, array<int, 3> b) {
    if (a[0] / K != b[0] / K) {
        return a[0] < b[0];
    }
    return a[1] < b[1];
}

void upd(int i, int val) {
    if (cnt[s[i]] != 0) {
        cur--;
    }
    cnt[s[i]] += val;
    if (cnt[s[i]] != 0) {
        cur++;
    }
}

main() {
    cin >> s;
    int q;
    cin >> q;
    vector<array<int, 3>> arr;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        if (s[l] != s[r] || l == r) {
            ans[i] = 1;
        } else {
            arr.push_back({l, r, i});
        }
    }
    sort(arr.begin(), arr.end(), cmp);
    int l = 0, r = 0;
    cnt[s[0]] = 1;
    for (auto elem : arr) {
        while (r < elem[1]) {
            upd(r + 1, 1);
            r++;
        }
        while (l > elem[0]) {
            upd(l - 1, 1);
            l--;
        }
        while (r > elem[1]) {
            upd(r, -1);
            r--;
        }
        while (l < elem[0]) {
            upd(l, -1);
            l++;
        }
        if (cur >= 3) {
            ans[elem[2]] = 1;
        }
    }
    for (int i = 0; i < q; ++i) {
        if (ans[i]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}