#include <iostream>

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

const int N = 1005;

int n;
int l[N], r[N], a[N];

void run() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }
    for (int i = 0; i < n; i++) {
        int L = i - l[i];
        int R = (n - i - 1) - r[i];
        if (L < 0 || R < 0) {
            cout << "NO\n";
            return;
        }
        a[i] = L + R + 1;
    }
    for (int i = 0; i < n; i++) {
        int L = 0;
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i]) {
                L++;
            }
        }
        int R = 0;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) {
                R++;
            }
        }
        if (L != l[i] || R != r[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
}