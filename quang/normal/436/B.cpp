#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 2020

using namespace std;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m, k;
string s[N];
int res[N];

int Get(int x, int y, int d) {
    int x2 = x + dir[d][0] * x;
    int y2 = y + dir[d][1] * x;
    if(x2 < 0 || y2 < 0 || x2 >= n || y2 >= m) return 0;
    if(!d) return s[x2][y2] == 'U';
    if(d == 1) return s[x2][y2] == 'L';
    if(d == 2) return s[x2][y2] == 'D';
    return s[x2][y2] == 'R';
}

int main() {
    //fi, fo;
    scanf("%d%d%d", &n ,&m, &k);
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++)
        for(int l = 0; l < 4; l++)
        res[j] += Get(i, j, l);
        printf("%d ", res[j]);
    }
    return 0;
}