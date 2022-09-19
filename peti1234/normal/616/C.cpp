#include <bits/stdc++.h>

using namespace std;
const int c=1005;
int n, m, si[c][c];
pair<int, int> ki[c][c];
pair<int, int> holvan(int a, int b) {
    auto s=ki[a][b];
    if (s.first==0 && s.second==0) return {a, b};
    ki[a][b]=holvan(s.first, s.second);
    return ki[a][b];
}
void unio(int a1, int a2, int b1, int b2) {
    auto a=holvan(a1, a2), b=holvan(b1, b2);
    if (a!=b) {
        si[a.first][a.second]+=si[b.first][b.second];
        ki[b.first][b.second]={a.first, a.second};
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        for (int j=1; j<=m; j++) {
            if (s[j-1]=='.') {
                si[i][j]=1;
                if (si[i-1][j]) unio(i-1, j, i, j);
                if (si[i][j-1]) unio(i, j-1, i, j);
            }
        }
    }

    for (int i=1; i<=n; i++) {
        string ans;
        for (int j=1; j<=m; j++) {
            if (si[i][j]) ans+='.';
            else {
                vector<pair<int, int> > p;
                if (si[i-1][j]) p.push_back({holvan(i-1, j)});
                if (si[i+1][j]) p.push_back({holvan(i+1, j)});
                if (si[i][j-1]) p.push_back({holvan(i, j-1)});
                if (si[i][j+1]) p.push_back({holvan(i, j+1)});
                sort(p.begin(), p.end());
                p.erase(unique(p.begin(), p.end()), p.end());
                int ert=1;
                for (auto x:p) {
                    ert+=si[x.first][x.second];
                }
                char k='0'+(ert%10);
                ans+=k;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}