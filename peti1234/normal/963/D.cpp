#include <bits/stdc++.h>

using namespace std;
const int c=100005, k=26;
int n, cnt=1, fel[c], ut[c], len[c], kov[c][k], suf[c], fsuf[c], pos[c], veg[c], t[c];
vector<pair<int, int> > sor;
vector<int> sz[c];
string ss;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> ss;
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        string s;
        cin >> s;
        int h=0, p=1;
        for (auto ch:s) {
            int id=ch-'a';
            h++;
            if (!kov[p][id]) {
                kov[p][id]=++cnt;
                ut[cnt]=id, fel[cnt]=p, len[cnt]=h;
                sor.push_back({len[cnt], cnt});
            }
            p=kov[p][id];
        }
        pos[i]=p, veg[p]=i;
    }

    sort(sor.begin(), sor.end());
    suf[1]=1, fsuf[1]=1;
    for (int i=0; i<k; i++) {
        if (!kov[1][i]) {
            kov[1][i]=1;
        }
    }
    for (auto x:sor) {
        int fi=x.first, id=x.second;
        suf[id]=(fi==1 ? 1 : kov[suf[fel[id]]][ut[id]]);
        fsuf[id]=(veg[suf[id]] ? suf[id] : fsuf[suf[id]]);
        for (int i=0; i<k; i++) {
            if (!kov[id][i]) {
                kov[id][i]=kov[suf[id]][i];
            }
        }
    }

    int h=0, p=1;
    for (auto ch:ss) {
        int id=ch-'a';
        h++;
        p=kov[p][id];
        int pp=p;
        while (pp!=1) {
            if (veg[pp]) {
                sz[veg[pp]].push_back(h);
            }
            pp=fsuf[pp];
        }
    }

    for (int i=1; i<=n; i++) {
        int si=sz[i].size();
        if (si<t[i]) {
            cout << -1 << "\n";
        } else {
            int mini=2e9;
            for (int j=t[i]-1; j<si; j++) {
                mini=min(mini, sz[i][j]-sz[i][j-t[i]+1]);
            }
            cout << mini+len[pos[i]] << "\n";
        }
    }
    return 0;
}