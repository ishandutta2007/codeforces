#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e5 + 10;

const ll inf = 1e18;

ll n, x, y, q[maxn];

int main(){
    //ifstream cin("tetris.dat");
    //ofstream cout("tetris.sol");
    ios::sync_with_stdio(0);
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++)
        cin >> q[i];
    sort(q, q + n);
    int l = -1, r = n;
    while (r - l > 1){
        int m = (l + r) / 2;
        ll sch = 0, snch = 0, sz = 0, a = x, b = y;
        for (int i = 0; i <= m; i++)
            if (q[i] % 2 == 0)
                sch += q[i];
            else
                snch += q[i] - 1, sz++;
        if (sch <= 2 * a)
            a -= sch / 2, sch = 0;
        else
            sch -= 2 * a, a = 0;
        b -= sch;
        if (b < 0){
            r = m;
            continue;
        }
        if (b >= sz)
            b -= sz, sz = 0;
        else
            sz -= b, b = 0;
        a -= sz;
        if (a < 0){
            r = m;
            continue;
        }
        snch -= 2 * a + b;
        if (snch > 0)
            r = m;
        else
            l = m;
    }
    cout << l + 1;
}