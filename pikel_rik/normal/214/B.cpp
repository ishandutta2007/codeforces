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

    int n;
    cin >> n;

    int a;
    vector<int> cnt(10);
    for (int i = 0; i < n; i++) cin >> a, cnt[a] += 1;

    if (cnt[0] == 0) {
        cout << "-1\n";
        return 0;
    }

    vector<int> ncnt(3);
    for (int i = 0; i < 10; i++) {
        if (i % 3 == 0) continue;

        ncnt[i % 3] += cnt[i];
    }

    int c1 = ncnt[1] % 3, c2 = ncnt[2] % 3;

    if (c1 != c2) {
        int rem = c1 + 2 * c2, besti = c1, bestj = c2;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if ((c1 == ncnt[1] and c1 < i) or (c2 == ncnt[2] and c2 < j)) continue;

                int val = (c1 - i) + 2 * (c2 - j);
                if (val % 3 == 0 and i + j < besti + bestj) {
                    besti = i;
                    bestj = j;
                }
            }
        }
        ncnt[1] -= besti;
        ncnt[2] -= bestj;
    }

    bool flag = false;

    for (int i = 9; i >= 1; i--) {
        if (i % 3 == 0) {
            while (cnt[i]) {
                cout << i;
                cnt[i] -= 1;
                flag = true;
            }
            continue;
        }
        while (cnt[i] and ncnt[i % 3]) {
            cnt[i] -= 1;
            ncnt[i % 3] -= 1;
            cout << i;
            flag = true;
        }
    }

    if (flag) {
        while (cnt[0]) {
            cout << 0;
            cnt[0] -= 1;
        }
    }
    else {
        cout << 0 << "\n";
    }
    return 0;
}