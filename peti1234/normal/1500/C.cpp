#include<bits/stdc++.h>

using namespace std;
const int c=1502;
int n, m, a[c][c], b[c][c], db[c];
bool fix[c];
queue<int> q;
vector<int> r, ans;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> b[i][j];
            if (b[i][j]<b[i-1][j]) {
                db[j]++;
            }
        }
    }
    for (int j=1; j<=m; j++) {
        if (!db[j]) {
            q.push(j);
        }
    }
    while (q.size()>0) {
        int x=q.front();
        q.pop();
        ans.push_back(x);
        for (int i=2; i<=n; i++) {
            if (!fix[i] && b[i][x]>b[i-1][x]) {
                fix[i]=1;
                for (int j=1; j<=m; j++) {
                    if (b[i-1][j]>b[i][j]) {
                        db[j]--;
                        if (!db[j]) {
                            q.push(j);
                        }
                    }
                }
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i=1; i<=n; i++) {
        r.push_back(i);
    }
    for (int j:ans) {
        stable_sort(r.begin(), r.end(), [&](int x, int y) {return a[x][j]<a[y][j];});
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (a[r[i-1]][j]!=b[i][j]) {
                cout << -1 << "\n";
                return 0;
            }
        }
    }
    cout << ans.size() << "\n";
    for (int i:ans) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}