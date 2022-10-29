#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define pb push_back
#define ii pair<int, int>
#define x first
#define y second
#define bit(x, y) ((x >> y) & 1)

int main() {
    ios::sync_with_stdio(false); cin.tie(0); 
    cout.tie(0);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        cin >> n;
        vector<int> cnt(n + 1);
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        int ndis = 0;
        int mx = 0;
        for (int i = 1; i <= n; i++) {
            if (cnt[i]) ndis++;
            mx = max(mx, cnt[i]);
        }
        int u = min(mx, ndis);
        cout << (mx == ndis ? u - 1 : u) << '\n';
    }
    return 0;
}