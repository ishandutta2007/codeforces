#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MAXN = 100;

char mat[5][MAXN + 1];

bool fr[26];

char dl[] = {-1, 0, 1, 0}, dc[] = {0, -1, 0, 1};

int n;

inline bool ok(int l, int c) {
    if(l > 0 && l <= 4 && c > 0 && c <= n && mat[l][c] > -1)
        return 1;
    return 0;
}

inline char check(int l1, int c1, int l2, int c2) {
    memset(fr, 0, sizeof(fr));
    int i;
    for(i = 0; i < 4; i++) {
        if(ok(l1 + dl[i], c1 + dc[i]))
            fr[mat[l1 + dl[i]][c1 + dc[i]]] = 1;
        if(ok(l2 + dl[i], c2 + dc[i]))
            fr[mat[l2 + dl[i]][c2 + dc[i]]] = 1;
    }
    i = 0;
    while(fr[i] == 1)
        i++;
    return i;
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, j;
    ios::sync_with_stdio(false);
    cin >> n;
    memset(mat, -1, sizeof(mat));
    for(i = 1; i < n; i++) {
        if(i % 2 == 1)
            mat[1][i] = mat[1][i + 1] = check(1, i, 1, i + 1);
        else
            mat[3][i] = mat[3][i + 1] = check(3, i, 3, i + 1);
    }
    if(n % 2 == 0) {
        for(j = 1; j <= n; j += 2)
            mat[2][j] = mat[2][j + 1] = check(2, j, 2, j + 1);
        mat[3][1] = mat[4][1] = check(3, 1, 4, 1);
        mat[3][n] = mat[4][n] = check(3, n, 4, n);
        for(j = 2; j < n; j += 2)
            mat[4][j] = mat[4][j + 1] = check(4, j, 4, j + 1);
    }
    else {
        mat[1][n] = mat[2][n] = check(1, n, 2, n);
        mat[3][1] = mat[4][1] = check(3, 1, 4, 1);
        for(j = 1; j < n; j += 2)
            mat[2][j] = mat[2][j + 1] = check(2, j, 2, j + 1);
        for(j = 2; j <= n; j += 2)
            mat[4][j] = mat[4][j + 1] = check(4, j, 4, j + 1);
    }
    for(i = 1; i <= 4; i++) {
        for(j = 1; j <= n; j++)
            cout << (char) (mat[i][j] + 'a');
        cout << endl;
    }
    //cin.close();
    //cout.close();
    return 0;
}