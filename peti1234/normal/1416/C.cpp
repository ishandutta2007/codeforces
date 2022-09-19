#include <bits/stdc++.h>

using namespace std;
const int c=300002;
long long n, db, ans, t[c], st=(1<<30), x, y, cnt=1, kis, nagy, pos=0;
vector<int> sz[3*c];
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i], sz[1].push_back(i);
    while(st>0) {
        for (int i=1; i<=cnt; i++) {
            sz[i+n].clear(), sz[i+2*n].clear();
            for (int j=0; j<sz[i].size(); j++) {
                int e=sz[i][j], p=t[e]/st;
                if (p%2) nagy++, y+=kis, sz[i+n].push_back(e);
                else kis++, x+=nagy, sz[i+2*n].push_back(e);
            }
            kis=0, nagy=0;
            sz[i].clear();
        }
        db+=min(x, y);
        if (y<x) ans+=st;
        st/=2, x=0, y=0, pos=0;
        for (int i=1; i<=cnt; i++) {
            if (sz[i+n].size()>1) {
                pos++;
                for (int j=0; j<sz[i+n].size(); j++) sz[pos].push_back(sz[i+n][j]);
            }
            if (sz[i+2*n].size()>1) {
                pos++;
                for (int j=0; j<sz[i+2*n].size(); j++) sz[pos].push_back(sz[i+2*n][j]);
            }
        }
        cnt=pos;
    }
    cout << db << " " << ans << "\n";
    return 0;
}