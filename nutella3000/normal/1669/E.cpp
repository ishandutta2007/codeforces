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
    int n; cin >> n;
    vector<int> cnt(10000);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        int a = (s[0] - 'a' + 1) * 30 + (s[1] - 'a');
        for (int j = 0; j < 30; j++)
            res += cnt[a/30*30 + j];
        for (int j = 0; j < 30; j++)
            res += cnt[a%30 + j*30];
        res -= 2*cnt[a];
        ++cnt[a];
    }
    cout << res << endl;
}


signed main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}