#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int w;
    cin >> w;
    while (w--) {
        int n, m;
        cin >> n >> m;
        map<string, pair<int, int> > s;
        for (int i=1; i<=n; i++) {
            string p;
            cin >> p;
            for (int len=2; len<=3; len++) {
                for (int j=0; j+len<=m; j++) {
                    s[p.substr(j, len)]={i, j+1};
                }
            }
        }
        string p;
        cin >> p;
        bool jo[1005];
        for (int i=0; i<=m; i++) jo[i]=0;
        jo[0]=1;
        for (int i=0; i<m; i++) {
            for (int len=2; len<=3; len++) {
                pair<int, int> g={0, 0};
                if (jo[i] && i+len<=m && s[(p.substr(i, len))]!=g) {
                    jo[i+len]=1;
                }
            }
        }
        if (!jo[m]) {
            cout << -1 << "\n";
        } else {
            vector<pair<pair<int, int>, int> > ans;
            int pos=m;
            while (pos) {
                if (jo[pos-2]) ans.push_back({s[p.substr(pos-2, 2)], 2}), pos-=2;
                else ans.push_back({s[p.substr(pos-3, 3)], 3}), pos-=3;
            }
            cout << ans.size() << "\n";
            reverse(ans.begin(), ans.end());
            for (auto x:ans) {
                cout << x.first.second << " " << x.first.second+x.second-1 << " " << x.first.first << "\n";
            }
        }
    }
    return 0;
}
/*
1
4 8
12340219
20215601
56782022
12300678
12345678
*/