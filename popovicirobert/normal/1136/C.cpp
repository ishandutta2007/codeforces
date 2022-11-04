#include <bits/stdc++.h>

using namespace std;

const int MAXN = 500;

map <int, int> fr[2 * MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n, m;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            int x;
            cin >> x;
            fr[i + j][x]++;
        }
    }
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= m; j++) {
            int x;
            cin >> x;
            fr[i + j][x]--;
            if(fr[i + j][x] < 0) {
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES";
    //cin.close();
    //cout.close();
    return 0;
}