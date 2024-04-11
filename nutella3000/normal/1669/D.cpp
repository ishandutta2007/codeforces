#include<bits/stdc++.h>
using namespace std;
 
#define int long long
#define all(a) a.begin(), a.end()
#define siz(a) (int)a.size()
#define eb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
template <typename T> bool chmin(T& a, T b) { if (a <= b) return false; a = b; return true; }
template <typename T> bool chmax(T& a, T b) { if (a >= b) return false; a = b; return true; }
 
 
const int inf = 1e9 + 7;
const int N = 500;

void run() {
    int n;
    cin >> n;
    string s; cin >> s;
    vector<int> cnt(2);

    for (int i = 0; i < n; ++i) {
        if (s[i] == 'W') {
            if (cnt[0] + cnt[1] && min(cnt[0], cnt[1]) == 0) {
                cout << "NO" << endl;
                return;
            }
            cnt[0] = cnt[1] = 0;
        } else if (s[i] == 'R') cnt[0]++;
        else cnt[1]++;
    }
    if (cnt[0] + cnt[1] && min(cnt[0], cnt[1]) == 0) {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
}


signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}