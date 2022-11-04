#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int MAXN = 500;

int dl[] = {-1, -1, 1, 1}, dc[] = {-1, 1, -1, 1};

int n;

inline bool in(int l, int c) {
    return l > 0 && c > 0 && l <= n && c <= n;
}

char mat[MAXN + 1][MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> mat[i] + 1;
    }
    int ans = 0;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            if(mat[i][j] == 'X') {
                int cnt = 0;
                for(int p = 0; p < 4; p++) {
                    int l = i + dl[p];
                    int c = j + dc[p];
                    if(in(l, c) && mat[l][c] == 'X') {
                        cnt++;
                    }
                }
                if(cnt == 4) {
                    ans++;
                }
            }
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}