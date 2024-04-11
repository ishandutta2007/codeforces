#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
vector<int> a[maxn];
int n, m, resx, resy;
bool check(int x, int y) {
    for(int i = 0; i < n; i++) swap(a[i][x], a[i][y]);
    bool ok = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < m; j++) if(a[i][j] < a[i][j-1]) ok = 0;
    }
    for(int i = 0; i < n; i++) swap(a[i][x], a[i][y]);
    if(ok) {
        resx = x+1;
        resy = y+1;
    }
    return ok;
}
int main() {
    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) a[i].clear();
        for(int i = 0; i < n; i++) a[i].resize(m);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];
        if(check(0,0)) {
            cout << 1 << " " << 1 << endl;
            continue;
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            bool ok = 1;
            for(int j = 1; j < m; j++) {
                if(a[i][j] < a[i][j-1]) {
                    ok = 0;
                    for(int k = 0; k < m; k++) {
                        if(a[i][k] > a[i][j]) {
                            if(check(k, j)) ans = 1;
                            break;
                        }
                    }
                    for(int k = m-1; k >= 0; k--) {
                        if(a[i][k] <= a[i][j]) {
                            if(check(k, j-1)) ans = 1;
                            break;
                        }
                    }
                    break;
                }
            }
            if(!ok) {
                if(ans) cout << resx << " " << resy << endl;
                else cout << -1 << endl;
                break;
            }
        }
    }
}