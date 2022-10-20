#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 110

using namespace std;

int n, m;
int a[N][N];

bool check(int x) {
    for(int i = 1; i <= x / 2; i++)
        for(int j = 1; j <= m; j++)
            if(a[i][j] != a[x - i + 1][j]) return 0;
    return 1;
}

int main() {
   // fi, fo;
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++)
    for(int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
    int cur = n;
    while(cur % 2 == 0) {
        if(check(cur)) cur /= 2;
        else break;
    }
    cout << cur;
    return 0;
}