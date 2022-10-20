#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 1010

using namespace std;

int n, k;
int a[6][N], dai[N];
int vt[6][N];

bool check(int x, int y) {
    for(int i = 2; i <= k; i++) {
        if(vt[i][y] > vt[i][x]) return 0;
    }
    return 1;
}

int main() {
    //fi, fo;
    cin >> n >> k;
    memset(vt, 0 ,sizeof(vt));
    for(int i = 1; i <= k; i++)
    for(int j = 1; j <= n; j++) {
        cin >> a[i][j];
        vt[i][a[i][j]] = j;
    }
    memset(dai, 0 ,sizeof(dai));
    for(int i = 1; i <= n; i++) {
        int l = 1;
        for(int j = 1; j < i; j++)
        if(check(a[1][i], a[1][j]))
           l = max(l, dai[j] + 1);
        dai[i] = l;
    }
    int res = 0;
    for(int i = 1; i <= n; i++) res = max(res, dai[i]);
    cout << res;
    return 0;
}