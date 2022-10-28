#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e2+10, MOD = 1e9+7;

int n, m, k;
string s[MAXN];
bool hit[MAXN][MAXN];

bool valid(int i, int j, int c) {
    for (int x = 0; x < c; x++) {
        int ni = i - x;
        for (int nj : {j - x, j + x}) {
            if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
                return 0;
            }
            if (s[ni][nj] == '.') return 0;
        }
    }
    return 1;
}
void mark(int i, int j, int c) {
    assert(valid(i, j, c));
    for (int x = 0; x < c; x++) {
        int ni = i - x;
        for (int nj : {j - x, j + x}) {
            hit[ni][nj] = 1;
        }
    }
}
void solve() {
    cin >> n >> m >> k; k++;
    for (int i = 0; i < n; i++) cin >> s[i];
    memset(hit, 0, sizeof(hit));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (valid(i, j, k)) {
                int c = k;
                while (valid(i, j, c)) c++;
                c--;
                mark(i, j, c);
            }
        }
    }
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (hit[i][j] != (s[i][j] == '*')) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}