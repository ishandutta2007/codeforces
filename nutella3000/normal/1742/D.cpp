#include<bits/stdc++.h>
using namespace std;
 
#define all(a) a.begin(), a.end()
using ll = long long;
using ld = long double;
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int M = 1001;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void run() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& i : a)
        cin >> i;

    vector<int> pos(M, -1);
    int res = -1;
    for (int i = n-1; i >= 0; --i) {
        if (pos[a[i]] != -1) continue;
        pos[a[i]] = i;
        for (int j = 1; j < M; ++j) {
            if (pos[j] != -1 && gcd(a[i], j) == 1)
                chmax(res, i + pos[j] + 2);
        }
    }
    cout << res << '\n';
}


signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}