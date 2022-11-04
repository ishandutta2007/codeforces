#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) (1e9 + 1e6 + 123);
const ll LINF = (ll) (1e18 + 1e9 + 123);

bool mini(auto& x, const auto& y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

bool maxi(auto& x, const auto& y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    run();
    return 0;
}

const int N = 105;

bool can[N];
bool tmp[N];

void run() {
    int n;
    cin >> n;
    for (int i = 1; i <= 100; i++) {
        can[i] = true;
    }
    for (int i = 0;i < n; i++) {
        int r;
        cin >> r;
        memset(tmp, 0, sizeof tmp);
        for (int j = 0; j < r; j++) {
            int x;
            cin >> x;
            tmp[x] = true;
        }
        for (int j = 1; j <= 100; j++) {
            can[j] &= tmp[j];
        }
    }
    for (int i = 1; i <= 100; i++) {
        if (can[i]) {
            cout << i << " ";
        }
    }
    cout << "\n";
}