#include <bits/stdc++.h>

using namespace std;
vector<pair<int, int> > sz[4];
int n, x, y, a, b;
char c;
void add(int a, int b, int c) {
    sz[a].push_back({b, c});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> x >> y;
    for (int i=0; i<4; i++) {
        add(i, 0, -1);
    }
    for (int i=1; i<=n; i++) {
        cin >> c >> a >> b;
        a-=x, b-=y;
        if (!a) {
            if (c=='B') add(0, b, -2);
            else add(0, b, 1);
        }
        if (!b) {
            if (c=='B') add(1, a, -2);
            else add(1, a, 1);
        }
        if (a==b) {
            if (c=='R') add(2, a, -2);
            else add(2, a, 1);
        }
        if (a==-b) {
            if (c=='R') add(3, a, -2);
            else add(3, a, 1);
        }
    }
    for (int i=0; i<4; i++) {
        sort(sz[i].begin(), sz[i].end());
        int si=sz[i].size();
        for (int j=1; j<si; j++) {
            if (sz[i][j-1].second+sz[i][j].second==0) {
                cout << "YES\n";
                return 0;
            }
        }
    }
    cout << "NO\n";
    return 0;
}