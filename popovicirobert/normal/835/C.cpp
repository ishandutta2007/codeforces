#include <bits/stdc++.h>
#define ll long long


using namespace std;

int sp[11][101][101];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, q, c, x, y, s;
    cin >> n >> q >> c;
    for(i = 1; i <= n; i++) {
        cin >> x >> y >> s;
        sp[s][x][y]++;
    }
    for(i = 0; i <= c; i++)
        for(x = 1; x <= 100; x++)
           for(y = 1; y <= 100; y++)
              sp[i][x][y] += sp[i][x - 1][y] + sp[i][x][y - 1] - sp[i][x - 1][y - 1];
    while(q > 0) {
        q--;
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;
        ll ans = 0;
        for(i = 0; i <= c; i++) {
            int z = (i + t) % (c + 1);
            ans += 1LL * (sp[i][x2][y2] - sp[i][x1 - 1][y2] - sp[i][x2][y1 - 1] + sp[i][x1 - 1][y1 - 1]) * z;
        }
        cout << ans << endl;
    }
    //cin.close();
    //cout.close();
    return 0;
}