#include <bits/stdc++.h>

using namespace std;
int n, m;
int t[51][10001];
bool szomsz(int a, int b)
{
    for (int i=1; i<=m; i++) {
        if (t[a][i] && t[b][i]) {
            return true;
        }
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        for (int j=1; j<=x; j++) {
            int a;
            cin >> a;
            t[i][a]=true;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (!szomsz(i, j)) {
                cout << "impossible" << endl;
                return 0;
            }
        }
    }
    cout << "possible" << endl;
    return 0;
}