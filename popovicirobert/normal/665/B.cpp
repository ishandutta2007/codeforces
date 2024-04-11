#include <bits/stdc++.h>
#define MAXN 100

using namespace std;

int p[MAXN + 1], aux[MAXN + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, k, j, a;
    //ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(i = 1; i <= k; i++)
        cin >> p[i];
    int ans = 0;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            cin >> a;
            int pos = 1;
            while(p[pos] != a)
                pos++;
            for(int k = pos - 1; k >= 1; k--)
                p[k + 1] = p[k];
            p[1] = a;
            ans += pos;
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}