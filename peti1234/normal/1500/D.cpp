#include <bits/stdc++.h>

using namespace std;

const int c=1502;
int n, q, t[c][c], db[c][c], ki[c][c][11], ans;
bool jo[c][c];
void torol(int i, int j) {
    if (!jo[i][j]) {
        ans--;
        jo[i][j]=1;
    }
}
queue<pair<pair<int, int>, int> > e;
void add(int i, int j, int cl) {
    if (min(i, j)<1 || jo[i][j]) {
        return;
    }
    for (int k=0; k<db[i][j]; k++) {
        if (ki[i][j][k]==cl) {
            return;
        }
    }
    ki[i][j][db[i][j]++]=cl;
    if (db[i][j]>q) {
        torol(i, j);
    }
    e.push({{i, j}, cl});
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> q;
    ans=n*n;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> t[i][j];
            add(i, j, t[i][j]);
        }
    }
    for (int s=1; s<=n; s++) {
        cout << ans << "\n";
        for (int i=1; i<=n; i++) {
            torol(i, n-s+1);
            torol(n-s+1, i);
        }
        int si=e.size();
        for (int i=0; i<si; i++) {
            auto p=e.front();
            e.pop();
            int a=p.first.first, b=p.first.second, cl=p.second;
            add(a-1, b, cl), add(a, b-1, cl), add(a-1, b-1, cl);
        }
    }
    return 0;
}