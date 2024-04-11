#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 1010;

int n, m, sum, vtx, vty, sum2;
int a[N][N];
string s[N];

void Check() {
    for(int i = 1; i <= n; i++) {
        int sl = 0;
        for(int j = 1; j <= m; j++)
        if(s[i][j] == 'X' && s[i][j - 1] != 'X') sl++;
        if(sl >= 2) {
            cout << -1;
            exit(0);
        }
    }
    for(int j = 1; j <= m; j++) {
        int sl = 0;
        for(int i = 1; i <= n; i++)
        if(s[i][j] == 'X' && s[i - 1][j] != 'X') sl++;
        if(sl >= 2) {
            cout << -1;
            exit(0);
        }
    }
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    if(s[i][j] == '.' && s[i][j + 1] == 'X' && s[i + 1][j] == 'X') {
        cout << -1;
        exit(0);
    }
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    a[i][j] = a[i][j - 1] + a[i - 1][j] - a[i - 1][j - 1] + (s[i][j] == 'X');
}

void Checkrec() {
    int flag = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++)
            if(s[i][j] == 'X') {
            vtx = i;
            vty = j;
            flag = 1;
            break;
        }
        if(flag) break;
    }
    int x, y;
    for(int i = vty; i <= m; i++)
    if(s[vtx][i + 1] != 'X') {
        x = i - vty + 1;
        break;
    }
    for(int i = vtx; i <= n; i++)
    if(s[i + 1][vty] != 'X') {
        y = i - vtx + 1;
        break;
    }
    if(x * y == sum) {
        cout << min(x, y);
        exit(0);
    }
}

void SL() {
    sum = 0;
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++)
    sum += (s[i][j] == 'X');
    if(!sum) {
        cout << 0;
        exit(0);
    }
}

void Go(int x, int y ,int X, int Y) {
    int xd = x + X - 1;
    int yd = y + Y - 1;
    int sl1 = a[xd][yd + 1] + a[x - 1][yd] - a[xd][yd] - a[x - 1][yd + 1];
    int sl2 = a[xd + 1][yd] + a[xd][y - 1] - a[xd][yd] - a[xd + 1][y - 1];
    if(sl1)
        if(sl1 == X) {
            Go(x, y + 1, X, Y);
            sum2 += X;
            return;
        }
    if(sl2)
        if(sl2 == Y) {
            Go(x + 1, y, X, Y);
            sum2 += Y;
            return;
        }
}

void Find() {
    int X, Y, Xd, Yd;
    X = Y = 2020;
    for(int i = 1; i <= n; i++)
    if(a[i][m] - a[i - 1][m])
        Y = min(Y, a[i][m] - a[i - 1][m]);
    for(int i = 1; i <= m; i++)
    if(a[n][i] - a[n][i - 1])
        X = min(X, a[n][i] - a[n][i - 1]);
    Xd = vtx + X - 1;
    Yd = vty + Y - 1;
    if(a[Xd][Yd] - a[Xd][vty - 1] - a[vtx - 1][Yd] + a[vtx - 1][vty - 1] != X * Y) {
        cout << -1;
        exit(0);
    }
    sum2 = X * Y;
    bool flag = 0;
    int res = 10000000;
    Go(vtx, vty, X, Y);
    if(sum2 == sum) {
        flag = 1;
        res = min(res, X * Y);
    }
    for(int i = 1; i <= X; i++) {
        sum2 = i * Y;
        Go(vtx, vty, i, Y);
        if(sum2 == sum) {
            flag = 1;
            res = min(res, i * Y);
        }
    }
    for(int i = 1; i <= Y; i++) {
        sum2 = X * i;
        Go(vtx, vty, X, i);
        if(sum2 == sum) {
            flag = 1;
            res = min(res, X * i);
        }
    }
    if(flag) cout << res;
    else
    cout << -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> m;
    memset(a, 0, sizeof(a));
    for(int i = 0; i <= m + 1; i++) s[0] += '.', s[n + 1] += '.';
    for(int i = 1; i <= n; i++) cin >> s[i], s[i] = '.' + s[i] + '.';
    SL();
    Check();
    Checkrec();
    Find();
    return 0;
}