#include <bits/stdc++.h>

using namespace std;
const int c=400005;
int n, m, kis[c], cnt, ans;
vector<int> t[c];
vector<int> sz[c];
void add(int a, int b, int s) {
    if (a==b) return;
    if (a<b) swap(a, b);
    kis[a]+=s;
    if (s==1 && kis[a]==1) {
        cnt++;
    }
    if (s==-1 && kis[a]==0) {
        cnt--;
    }
}
void solve() {
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        t[i].resize(m+1);
        for (int j=1; j<=m; j++) {
            cin >> t[i][j];
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (i<n) {
                int x=t[i][j], y=t[i+1][j];
                sz[x].push_back(y), sz[y].push_back(x);
                add(x, y, 1);
            }
            if (j<m) {
                int x=t[i][j], y=t[i][j+1];
                sz[x].push_back(y), sz[y].push_back(x);
                add(x, y, 1);
            }
        }
    }
    int pos=0;
    n=n*m;
    for (int i=2; i<=n; i++) {
        if (!kis[i]) {
            pos=i;
        }
    }
    //cout << "vege " << pos << "\n";
    if (!pos) {
        cout << 0 << "\n";
        return;
    }
    vector<int> f;
    f.push_back(pos);
    for (auto x:sz[pos]) f.push_back(x);
    for (auto a:f) {
        for (int b=1; b<=n; b++) {
            if (b==pos) continue;
            //if (a!=2 || b!=6) continue;
            //cout << "proba " << a << " " << b << "\n";
            for (auto x:sz[a]) {
                if (x==b) continue;
                add(a, x, -1);
                add(b, x, 1);
            }
            //cout << "kozep " << kis[6] << "\n";
            for (auto y:sz[b]) {
                if (y==a) continue;
                //cout << "valt " << y << "\n";
                add(b, y, -1);
                add(a, y, 1);
            }
            /*cout << "vege\n";
            for (int i=1; i<=n; i++) {
                cout << kis[i] << " ";
            }
            cout << "\n";*/
            if (cnt==n-1) {
                //cout << "jo " << a << " " << b << "\n";
                ans++;
            }
            for (auto x:sz[a]) {
                if (x==b) continue;
                add(a, x, 1);
                add(b, x, -1);
            }
            for (auto y:sz[b]) {
                if (y==a) continue;
                add(b, y, 1);
                add(a, y, -1);
            }

        }
    }
    if (!ans) {
        cout << 2 << "\n";
    } else {
        cout << 1 << " " << ans << "\n";
    }
}
int main()
{
    solve();
    return 0;
}

// ugyanaz ketszer?
/*
2 3
1 6 4
3 2 5
*/