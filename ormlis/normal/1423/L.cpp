#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cstring>
#include <bitset>
#include <unordered_map>

#define ar array
#define all(arr) arr.begin(), arr.end()
#define rall(arr) arr.rbegin(), arr.rend()
#define range(i, n) for (int i=0; i < n; ++i)

typedef long long ll;
using namespace std;

const int mxn = 1e3;
const int mxs = 30;
const int mxk = 13;
bitset<mxn> a[mxs];
bitset<mxn> b[1 << mxk];
int cnt1[1 << mxk];

void solve() {
    int n, s, d;
    cin >> n >> s >> d;
    range(i, s) {
        int c;
        cin >> c;
        range(j, c) {
            int x;
            cin >> x;
            a[i][x] = true;
        }
    }
    int k = min(13, s / 2);
    range(mask, 1 << k) {
        range(i, k) {
            if ((1 << i) & mask) {
                cnt1[mask]++;
                b[mask] ^= a[i];
            }
        }
    }
    unordered_map<bitset<mxn>, int> cntt;
    int kk = s - k;
    range(mask, 1 << kk) {
        bitset<mxn> bb;
        int w = 0;
        range(i, kk) {
            if ((1 << i) & mask) {
                bb ^= a[i + k];
                w++;
            }
        }
        if (cntt.count(bb)) cntt[bb] = min(w, cntt[bb]);
        else cntt[bb] = w;
    }
    range(_, d) {
        int tt;
        cin >> tt;
        bitset<mxn> cur;
        range(__, tt) {
            int i;
            cin >> i;
            cur[i] = true;
        }
        int ans = 35;
        range(mask, 1 << k) {
            bitset<mxn> cur2 = cur ^ b[mask];
            if (!cntt.count(cur2)) continue;
            ans = min(ans, cntt[cur2] + cnt1[mask]);
        }
        if (ans == 35) {
            cout << "-1\n";
        } else {
            cout << ans << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}