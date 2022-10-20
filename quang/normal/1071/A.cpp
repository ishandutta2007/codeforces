#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int a, b;
vector<int> aa, bb;

bool check(int u, int f = 0) {
    long long sum = 1ll * u * (u + 1) / 2ll;
    if (sum > a + b) return 0;
    int tot = 0;
    for (int i = u; i; i--) {
        if (tot + i <= a) {
            tot += i;
            if (f) aa.push_back(i);
        } else if (f) bb.push_back(i);
    }
    if (tot > a || sum - tot > b) return 0;
    if (f) {
        reverse(aa.begin(), aa.end());
        reverse(bb.begin(), bb.end());
        cout << (int)aa.size() << '\n';
        for (int u : aa) cout << u << ' ';
        cout << '\n';
        cout << (int)bb.size() << '\n';
        for (int u : bb) cout << u << ' ';
        cout << '\n';
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> a >> b;
    int low = -1, high = 1e9;
    while (high - low > 1) {
        int mid = (1ll * high + low) >> 1ll;
        if (check(mid)) {
            low = mid;
        } else {
            high = mid;
        }
    }
    check(low, 1);
    return 0;
}