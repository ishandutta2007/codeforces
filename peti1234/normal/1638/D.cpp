#include <bits/stdc++.h>

using namespace std;
const int c=1005;
int n, m, t[c][c];
vector<pair<pair<int, int>, int > > ans;
void solve(int a, int b) {
    if (a==0 || b==0 || a==n || b==m) return;

    int p=t[a][b], q=t[a][b+1], r=t[a+1][b], s=t[a+1][b+1];
    if (p==0 && q==0 && r==0 && s==0) return;

    int ert=(p>0 ? p : q>0 ? q : r>0 ? r : s);
    if (p>0 && p!=ert || q>0 && q!=ert || r>0 && r!=ert || s>0 && s!=ert) return;

    ans.push_back({{a, b}, ert});
    t[a][b]=t[a][b+1]=t[a+1][b]=t[a+1][b+1]=0;
    for (int i=-1; i<=1; i++) {
        for (int j=-1; j<=1; j++) {
            solve(a+i, b+j);
        }
    }
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
    for (int i=1; i<n; i++) {
        for (int j=1; j<m; j++) {
            solve(i, j);
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (t[i][j]) {
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << "\n";
    for (auto p:ans) {
        cout << p.first.first << " " << p.first.second << " " << p.second << "\n";
    }
    return 0;
}