#include <bits/stdc++.h>

using namespace std;
const int c=305;
int n, m;
deque<char> s[c][c];
vector<pair<pair<int, int>, pair<int, int> > > ans[2];
void add(int a, int b, int c, int d, int id) {
    ans[id].push_back({{a, b}, {c, d}});
    s[c][d].push_front(s[a][b].back());
    s[a][b].pop_back();
}
void cl(int a, int b, int c, int d, int e, int f, int id) {
    while (s[a][b].size()>0) {
        bool x=(s[a][b].back()=='0');
        add(a, b, (x ? c : e), (x ? d : f), id);
    }
}
void solve(int id) {
    int s1=0;
    while (s1<s[1][1].size() && s[1][1][s1]=='0') {
        s1++;
    }
    while (s[1][1].size()>s1) {
        int x=(s[1][1].back()=='1');
        add(1, 1, (x ? 1 : 2), (x ? 2 : 1), id);
    }
    s1=0;
    while (s1<s[1][2].size() && s[1][2][s1]=='1') {
        s1++;
    }
    while (s[1][2].size()>s1) {
        int x=(s[1][2].back()=='0');
        add(1, 2, (x ? 1 : 2), (x ? 1 : 2), id);
    }
    for (int i=1; i<=n; i++) {
        for (int j=3; j<=m; j++) {
            cl(i, j, i, 1, i, 2, id);
        }
    }
    for (int i=2; i<=n; i++) {
        cl(i, 1, 1, 1, i, 2, id);
        cl(i, 2, i, 1, 1, 2, id);
        cl(i, 1, 1, 1, i, 2, id);
    }
}
int main()
{
    cin >> n >> m;
    for (int id=0; id<2; id++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=m; j++) {
                string s2;
                cin >> s2;
                if (id) {
                    reverse(s2.begin(), s2.end());
                }
                for (char x:s2) {
                    s[i][j].push_back(x);
                }
            }
        }
        solve(id);
    }
    cout << ans[0].size()+ans[1].size() << "\n";
    for (auto x:ans[0]) {
        cout << x.first.first << " " << x.first.second << " " << x.second.first << " " << x.second.second << "\n";
    }
    //cout << "...................\n";
    reverse(ans[1].begin(), ans[1].end());
    for (auto x:ans[1]) {
        cout << x.second.first << " " << x.second.second << " " << x.first.first << " " << x.first.second << "\n";
    }

    return 0;
}
/*
2 3
0 0 0
011 1 0
0 0 1
011 0 0
*/