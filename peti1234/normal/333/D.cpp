#include <bits/stdc++.h>

using namespace std;
const int c=1005;
int n, m, t[c][c];
bool jo[c][c];

bool solve(int x) {
    for (int i=1; i<=n; i++) {
        vector<int> sz;
        for (int j=1; j<=m; j++) {
            if (t[i][j]>=x) {
                for (auto y:sz) {
                    if (jo[y][j]) {
                        return true;
                    }
                    jo[y][j]=1;
                }
                sz.push_back(j);
            }
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> t[i][j];
        }
    }
    int lo=0, hi=1e9+1, mid;
    while (hi-lo>1) {
        mid=(hi+lo)/2;
        if (solve(mid)) {
            lo=mid;
        } else {
            hi=mid;
        }
        for (int i=1; i<=m; i++) {
            for (int j=1; j<=m; j++) {
                jo[i][j]=0;
            }
        }
    }
    cout << lo << "\n";
    return 0;
}