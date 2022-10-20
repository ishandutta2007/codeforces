#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N

using namespace std;

int n, s;

int main() {
    //fi, fo;
    cin >> n >> s;
    int res = -1;
    for(int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        if(x < s && y) res = max(res, 100 - y);
        if(x < s || (x == s && !y)) res = max(res, 0);
    }
    cout << res;
    return 0;
}