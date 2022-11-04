#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 100;

int mat[MAXN + 1][MAXN + 1];

int sp[MAXN + 1][MAXN + 1];



int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m, k;
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            cin >> mat[i][j];
            sp[i][j] = sp[i - 1][j] + mat[i][j];
        }
    }
    int tot = 0;
    int cnt = 0;
    for(j = 1; j <= m; j++) {
        int mx = -1;
        int ind;
        for(i = n; i >= 1; i--)
            if(mat[i][j] == 1) {
                if(n - i + 1 <= k) {
                   mx = max(mx, sp[n][j] - sp[i - 1][j]);
                   if(mx == sp[n][j] - sp[i - 1][j])
                      ind = i;
                }
                else {
                   mx = max(mx, sp[i + k - 1][j] - sp[i - 1][j]);
                   if(mx == sp[i + k - 1][j] - sp[i - 1][j])
                      ind = i;
                }
            }
        if(mx > -1) {
           tot += mx;
           cnt += sp[ind - 1][j];
        }
    }
    cout << tot << " " << cnt;
    //cin.close();
    //cout.close();
    return 0;
}