#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == b[i]) {
            continue;
        }
        if (i + 1 < n && a[i + 1] != b[i + 1] && a[i + 1] != a[i]) {
            ans++;
            i++;
        } else {
            ans++;
        }
    }
    cout << ans << "\n";

    return 0;
}