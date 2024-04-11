#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;

void run() {
    int n, k; cin >> n >> k;
    vector<int> s(k);
    for (int i = 0; i < k; ++i) {
        cin >> s[i];
    }
    for (int i = k-1; i; --i) {
        s[i] -= s[i-1];
        if (i + 1 < k && s[i+1] < s[i]) {
            cout << "No\n";
            return;
        }
    }

    if (k == 1) {
        cout << "Yes\n";
        return;
    }
    int mx = s[1];
    if ((ll) mx * (n-k+1) < s[0]) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
}


signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}