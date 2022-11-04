#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 105;

int a[MAXN + 1], b[MAXN + 1];
int l[MAXN + 1], c[MAXN + 1];
int sol[MAXN + 1][MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(i = 1; i <= m; i++) {
        cin >> b[i];
    }
    for(int bit = 0; bit < 30; bit++) {
        int cnt1 = 0, cnt2 = 0;
        for(i = 1; i <= n; i++) {
            l[i] = ((a[i] & (1 << bit)) > 0);
            cnt1 += l[i];
        }
        for(i = 1; i <= m; i++) {
            c[i] = ((b[i] & (1 << bit)) > 0);
            cnt2 += c[i];
        }
        if(cnt1 % 2 != cnt2 % 2) {
            cout << "NO";
            return 0;
        }
        for(i = 1; i < n; i++) {
            sol[i][m] += (1 << bit) * l[i];
        }
        int val = l[n];
        for(i = 1; i < m; i++) {
            sol[n][i] += (1 << bit) * c[i];
            val ^= c[i];
        }
        sol[n][m] += (1 << bit) * val;
    }
    cout << "YES" << "\n";
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            cout << sol[i][j] << " ";
        }
        cout << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}