#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

int n, m;
int a[N];

bool check(int u) {
    int last = 0;
    for (int i = 1; i <= n; i++) {
        int now = a[i];
        int nxt = (a[i] + u) % m;
        if (now <= nxt) {
            if (last > nxt) return 0;
            last = max(last, now);
        } else {
            if (last <= nxt) continue;
            last = max(last, now);
        }
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int low = -1, high = m + 1;
    while (high - low > 1) {
        int mid = low + high >> 1;
        if (check(mid)) high = mid;
        else low = mid;
    }
    cout << high << endl;
    return 0;
}