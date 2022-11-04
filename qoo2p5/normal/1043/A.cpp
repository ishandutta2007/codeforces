#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int INF = (int) 1e9 + 1e6 + 123;
const ll LINF = (ll) 1e18 + 1e9 + 123;

template<typename A, typename B> bool mini(A &x, const B &y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> bool maxi(A &x, const B &y) {
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

// Solution

void run() {
    int n;
    cin >> n;
    ll sum = 0;
    ll t = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        maxi(t, x);
    }
    ll k = 2 * sum / n + 1;
    maxi(k, t);
    cout << k << "\n";
}