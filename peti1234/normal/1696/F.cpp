#include <bits/stdc++.h>

using namespace std;
const int c=105;
bool tav[c][c][c];
int n, dist[c][c], cnt;
vector<pair<int, int> > el;
void dfs(int a, int b) {
    if (cnt>=n) return;
    for (int a2=1; a2<=n; a2++) {
        if (cnt>=n) return;
        if (tav[b][a][a2] || tav[b][a2][a]) {
            cnt++;
            el.push_back({b, a2});
            dfs(b, a2);
        }
    }

}
bool check() {
    if (cnt!=n-1) return false;
    for (auto x:el) {
        //cout << x.first << " " << x.second << "\n";
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            dist[i][j]=c;
        }
        dist[i][i]=0;
    }
    for (auto x:el) {
        int a=x.first, b=x.second;
        dist[a][b]=dist[b][a]=1;
    }
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    bool jo=1;
    for (int koz=1; koz<=n; koz++) {
        for (int a=1; a<n; a++) {
            for (int b=a+1; b<=n; b++) {
                bool x=tav[koz][a][b], y=(dist[koz][a]==dist[koz][b]);
                if (x!=y) {
                    //cout << "fontos " << koz << " " << a << " " << b << "\n";
                }
                if (x!=y) jo=0;
            }
        }
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            dist[i][j]=0;
        }
    }
    return jo;
}
void solve() {
    cin >> n;
    for (int i=1; i<n; i++) {
        for (int s=1; i+s<=n; s++) {
            int j=i+s;
            for (int k=1; k<=n; k++) {
                char c;
                cin >> c;
                if (c=='1') {
                    //cout << "fontos " << k << " " << i << " " << j << "\n";
                }
                if (c=='1') tav[k][i][j]=1;
            }
        }
    }
    bool jo=0;
    for (int i=2; i<=n; i++) {
        el.push_back({1, i});
        cnt=1;
        dfs(1, i);
        dfs(i, 1);
        if (check()) {
            jo=1;
            cout << "Yes\n";
            for (auto x:el) {
                cout << x.first << " " << x.second << "\n";
            }
        }

        cnt=0;
        el.clear();

        if (jo) break;
    }
    if (!jo) {
        cout << "No\n";
    }

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            for (int k=1; k<=n; k++) {
                tav[i][j][k]=0;
            }
        }
    }


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
/*
1
3
001 000
000
*/