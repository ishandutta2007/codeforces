#include <bits/stdc++.h>

using namespace std;
const int c=505;
int n, m;
bool v[c][c];
void solve() {
    cin >> n >> m;
    int cnt=0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            char k;
            cin >> k;
            if (k=='1') {
                cnt++;
            }
            v[i][j]=(k=='1');
        }
    }
    if (cnt==n*m) {
        cout << n*m-2 << "\n";
        return;
    }
    bool jo=0;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            for (int di=-1; di<=1; di++) {
                for (int dj=-1; dj<=1; dj++) {
                    int ii=i+di, jj=j+dj;
                    if ((di || dj) && 1<=ii && ii<=n && 1<=jj && jj<=m && !v[i][j] && !v[ii][jj]) {
                        jo=1;
                    }
                }
            }
        }
    }
    if (!jo) {
        cnt--;
    }
    cout << cnt << "\n";

}
int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        solve();
    }
    return 0;
}