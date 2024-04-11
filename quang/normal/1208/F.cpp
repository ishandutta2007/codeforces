#include <bits/stdc++.h>

using namespace std;

const int LOG = 21;
const int N = (1 << LOG);

int n;
int a[N];
pair<int, int> rightMost[N];

void add(int mask, int val) {
    if (val > rightMost[mask].second) swap(rightMost[mask].second, val);
    if (rightMost[mask].second > rightMost[mask].first) swap(rightMost[mask].second, rightMost[mask].first);
}

bool check(int res, int keep) {
    for (int i = 1; i <= n; i++) {
        int mask = (a[i] ^ res) & keep;
        if (rightMost[mask].second > i) return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        add(a[i], i);
    }
    for (int i = 0; i < LOG; i++) {
        for (int j = 0; j < N; j++) {
            if (j & 1 << i) {
                add(j ^ (1 << i), rightMost[j].first);
                add(j ^ (1 << i), rightMost[j].second);
            }
        }
    }
    int res = 0;
    int keep = 0;
    for (int i = LOG - 1; i >= 0; i--) {
        keep |= (1 << i);
        if (check(res | (1 << i), keep)) res |= (1 << i);
    }
    cout << res << endl;
    return 0;
}