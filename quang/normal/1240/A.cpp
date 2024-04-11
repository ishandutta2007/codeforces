#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int p[N];
int x, a, y, b;
long long k;

bool check(int lim) {
    int numX = 0, numY = 0, numBoth = 0;
    for (int i = 1; i <= lim; i++) {
        if (i % a == 0 && i % b == 0) numBoth++;
        else if (i % a == 0) numX++;
        else if (i % b == 0) numY++;
    }
    long long tot = 0;
    for (int i = 1; i <= lim; i++) {
        if (numBoth) {
            numBoth--;
            tot += 1ll * (x + y) * p[i] / 100;
        } else if (numX) {
            numX--;
            tot += 1ll * x * p[i] / 100;
        } else if (numY) {
            numY--;
            tot += 1ll * y * p[i] / 100;
        }
    }
    return tot >= k;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        cin >> x >> a;
        cin >> y >> b;
        if (x < y) {
            swap(x, y);
            swap(a, b);
        }
        cin >> k;
        sort(p + 1, p + n + 1, greater<int>());
        int low = 0, high = n + 1;
        while (high - low > 1) {
            int mid = low + high >> 1;
            if (check(mid)) high = mid;
            else low = mid;
        }
        cout << (high == n + 1 ? -1 : high) << '\n';
    }
    return 0;
}