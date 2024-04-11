#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(v) ((int)v.size())
#define all(v) v.begin(), v.end()
#define db(v) cout << #v << " is " << v << endl
using namespace std;
using lint = long long;
using pii = pair<int, int>;
using pll = pair<lint, lint>;

int main() {
    int n; cin >> n;
    int a[n][n], done[n];
    memset(a, 0, sizeof(a));
    memset(done, 0, sizeof(done));
    for (int i = 0; i < n; i++) cin >> a[0][i];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = (i) * a[0][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0) a[i][j] = 0;
            a[i][j]++;
            // cout << a[i][j] << " ";
        }
        // cout << "\n";
    }
    stack<int> ans;
    int res = 0;
    for (int i = n - 1; i >= 0; i--) {
        int minim = 1e9, ai = -1;
        for (int j = 0; j < n; j++) {
            if (done[j]) continue;
            if (a[i][j] < minim) {
                minim = a[i][j];
                ai = j;
            }
        }
        done[ai] = 1;
        ans.push(ai);
        res += a[i][ai];
    }
    cout << res << "\n";
    while (ans.size()) {
        cout << ++ans.top() << " ";
        ans.pop(); 
    }
}
/*
minimize ai(i - 1), ai valid order

*/