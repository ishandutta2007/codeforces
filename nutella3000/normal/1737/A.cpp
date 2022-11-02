#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define all(a) a.begin(), a.end()
 
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }

const int inf = 1e9 + 7;

void run() {
    int n, k; 
    string s;
    cin >> n >> k >> s;
    vector<int> cnt(26);
    for (char i : s) {
        ++cnt[i - 'a'];
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j <= min(26, n / k); ++j) {
            if (j == n / k || !cnt[j]) {
                cout << char('a' + j);
                break;
            }
            --cnt[j];
        }
    }
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