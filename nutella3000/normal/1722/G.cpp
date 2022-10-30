#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;

void run() {
    int n; cin >> n;
    if (n == 3) {
        cout << "1 2 3" << '\n';
        return;
    }
    if (n % 2 == 1) {
        cout << "0 ";
        n -= 1;
    }
    if (n % 4 != 0) {
        cout << "4 1 2 12 3 8 ";
        n -= 6;
    }
    for (int i = 20; i < n+20; ++i)
        cout << i << " ";
    cout << '\n';
}

signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}