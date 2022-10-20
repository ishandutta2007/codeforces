#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 45

using namespace std;

int n, m, q;
string s[N];
int sum[N][N];
int cnt[N][N][N][N];

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) cin >> s[i], s[i] = '1' + s[i] + '1';
    for(int i = 0; i <= n; i++)
    for(int j = 0; j <= m; j++)
    if(!i || !j) sum[i][j] = 0;
    else sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + (s[i][j] == '1');
    for(int xa = 1; xa <= n; xa++)
        for(int ya = 1; ya <= m; ya++)
            for(int xb = xa; xb <= n; xb++)
                for(int yb = ya; yb <= m; yb++) {
                    int ss = sum[xb][yb] + sum[xa - 1][ya - 1] - sum[xb][ya - 1] - sum[xa - 1][yb];
                    cnt[xa][ya][xb][yb] = !ss;
                }
    for (int xa = n; xa >= 2; xa--)
        for (int ya = 1; ya <= m; ya++)
            for (int xb = xa; xb <= n; xb++)
                for (int yb = ya; yb <= m; yb++) cnt[xa - 1][ya][xb][yb] += cnt[xa][ya][xb][yb];
    for (int xa = 1; xa <= n; xa++)
        for (int ya = m; ya >= 2; ya--)
            for (int xb = xa; xb <= n; xb++)
                for (int yb = ya; yb <= m; yb++) cnt[xa][ya - 1][xb][yb] += cnt[xa][ya][xb][yb];
    for (int xa = 1; xa <= n; xa++)
        for (int ya = 1; ya <= m; ya++)
            for (int xb = xa; xb <= n; xb++)
                for (int yb = ya; yb <= m; yb++) cnt[xa][ya][xb + 1][yb] += cnt[xa][ya][xb][yb];
    for (int xa = 1; xa <= n; xa++)
        for (int ya = 1; ya <= m; ya++)
            for (int xb = xa; xb <= n; xb++)
                for (int yb = ya; yb <= m; yb++) cnt[xa][ya][xb][yb + 1] += cnt[xa][ya][xb][yb];
    while(q--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << cnt[a][b][c][d] << endl;
    }
    return 0;
}