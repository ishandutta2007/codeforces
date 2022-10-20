#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int MOD = 1000000007;

long long r, g, h;
long long sl[500010];

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> r >> g;
    sl[0] = 1;
    int h = 1;
    while(h * (h + 1) / 2 <= r + g) {
        for(int i = (h * (h + 1) / 2); i >= 0; i--)
            sl[h + i] = (sl[h + i] + sl[i]) % MOD;
        h++;
    }
    h--;
    long long res = 0;
    for(int i = r; i >= 0; i--) {
        if((h * (h + 1) / 2 - i) <= g)
            res = (res + sl[i]) % MOD;
    }
    cout << res;
    return 0;
}