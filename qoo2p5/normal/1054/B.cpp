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

const int N = (int) 1e5 + 123;

int n;
int a[N];
bool used[N];

void run() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ptr = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > ptr) {
            cout << i + 1 << "\n";
            return;
        }
        if (a[i] < N) {
            used[a[i]] = true;
        }
        while (used[ptr]) {
            ptr++;
        }
    }
    cout << "-1\n";
}