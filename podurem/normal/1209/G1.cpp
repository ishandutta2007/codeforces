#include <bits/stdc++.h>

using namespace std;

const int dd = (int)2e5 + 7;

int mx[dd], cnt[dd];

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
        mx[A[i]] = i;
        cnt[A[i]]++;
    }
    int l = 0, r = 1;
    while (r != n + 1) {
        int mxCnt = 0, start = l;
        while (l != r) {
            int x = A[l];
            r = max(r, mx[x] + 1);
            mxCnt = max(mxCnt, cnt[x]);
            ++l;
        }
        ans += r - start - mxCnt;
        ++r;
    }
    cout << ans << "\n";
    return 0;
}