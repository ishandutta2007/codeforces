#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const ll inf = 1e15;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void run() {
    int n; string s; cin >> n >> s;

    int r = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] != s[i+1])
            ++r;
    }
    cout << max(0, r - (s[0] == '0')) << '\n';
}


signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}