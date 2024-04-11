#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N

using namespace std;

int n, m, vong = 0, du = 1;

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x;
        cin >> x;
        if(x < du) vong++;
        du = x;
    }
    cout << 1ll * vong * n + du - 1;
    return 0;
}