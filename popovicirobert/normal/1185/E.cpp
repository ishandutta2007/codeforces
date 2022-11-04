#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = 2005;

char mat[MAXN + 1][MAXN + 1];
int n, m;

int main() {
    //ifstream cin("B.in");
    //ofstream cout("B.out");
    int t, i, j;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> t;

    while(t--) {

        cin >> n >> m;

        vector <int> l1(26, n + 1), l2(26), c1(26, m + 1), c2(26);

        for(i = 1; i <= n; i++) {
            cin >> mat[i] + 1;
            for(j = 1; j <= m; j++) {
                if(isalpha(mat[i][j])) {
                    int ch = mat[i][j] - 'a';
                    l1[ch] = min(l1[ch], i);
                    l2[ch] = max(l2[ch], i);
                    c1[ch] = min(c1[ch], j);
                    c2[ch] = max(c2[ch], j);
                }
            }
        }

        bool ans = 1;
        for(int ch = 0; ch < 26; ch++) {
            if(l1[ch] == n + 1) {
                l1[ch] = l2[ch] = c1[ch] = c2[ch] = 0;
            }
            if(l1[ch] != l2[ch] && c1[ch] != c2[ch]) {
                ans = 0;
            }
        }

        if(ans == 0) {
            cout << "NO\n";
            continue;
        }

        for(int ch = 0; ch < 26; ch++) {
            int l = l1[ch], c = c1[ch];
            int dl = 0, dc = 0;

            if(l1[ch] < l2[ch]) {
                dl = 1;
            }
            else if(l1[ch] > l2[ch]) {
                dl = -1;
            }

            if(c1[ch] < c2[ch]) {
                dc = 1;
            }
            else if(c1[ch] > c2[ch]) {
                dc = -1;
            }

            while(l != l2[ch] || c != c2[ch]) {
                if(mat[l][c] == '.') {
                    ans = 0;
                }
                else if(mat[l][c] - 'a' < ch) {
                    ans = 0;
                }
                l += dl, c += dc;
            }
        }

        int mx = -1;
        for(i = 0; i < 26; i++) {
            if(l1[i] != 0) {
                mx = max(mx, i);
            }
        }

        if(ans == 0) {
            cout << "NO\n";
            continue;
        }

        for(i = 0; i <= mx; i++) {
            if(l1[i] == 0) {
                l1[i] = l2[i] = l1[mx];
                c1[i] = c2[i] = c1[mx];
            }
        }

        cout << "YES\n" << mx + 1 << "\n";
        for(i = 0; i < 26; i++) {
            if(l1[i] != 0) {
                cout << l1[i] << " " << c1[i] << " " << l2[i] << " " << c2[i] << "\n";
            }
        }

    }

    //cin.close();
    //cout.close();
    return 0;
}