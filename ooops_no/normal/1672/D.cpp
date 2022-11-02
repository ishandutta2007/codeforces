#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll __int128
#define int long long

mt19937 rnd(51);

bool solve(int n, vector<int> a, vector<int> b) {
    map<int,int> cnt;
    int j = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (i + 1 < n && b[i] == b[i + 1]) {
            cnt[b[i]]++;
        } else {
            while (cnt[a[j]] > 0 && a[j] != b[i]) {
                cnt[a[j]]--;
                j--;
            }
            if (a[j] != b[i]) {
                return 0;
            }
            j--;
        }
    }
    return 1;
}

signed main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }
        cout << (solve(n, a, b) ? "YES\n" : "NO\n");
    }
    return 0;
}