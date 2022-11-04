#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
// 97

using namespace std;

const int MAXN = (int) 2e3;

char mat[MAXN + 1][MAXN + 1];


int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, m, k, i, j;
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            cin >> mat[i][j];
        }
    }
    int ans = 0;
    for(i = 1; i <= n; i++) {
        int cnt = 0;
        for(j = 1; j <= m; j++) {
            if(mat[i][j] == '.')
                cnt++;
            else
                cnt = 0;
            if(cnt >= k)
                ans++;
        }
    }
    if(k > 1) {
        for(j = 1; j <= m; j++) {
            int cnt = 0;
            for(i = 1; i <= n; i++) {
                if(mat[i][j] == '.')
                    cnt++;
                else
                    cnt = 0;
                if(cnt >= k)
                    ans++;
            }
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}