#include<bits/stdc++.h>

using namespace std;
const int c=300005, k=26;
int n, q, fel[c], ut[c], kov[c][k], suf[c], pos[c], vis[c], ert[c], cnt=1;
vector<pair<int, int> > sor;
multiset<int> m[c];
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=1; i<=n; i++) {
        string s;
        cin >> s;
        int p=1, db=0;
        for (auto c:s) {
            db++;
            int cc=c-'a';
            if (!kov[p][cc]) {
                kov[p][cc]=++cnt;
                sor.push_back({db, cnt});
                fel[cnt]=p;
                ut[cnt]=cc;
            }
            p=kov[p][cc];
        }
        pos[i]=p;
        m[p].insert(0);
    }
    for (int i=0; i<k; i++) {
        if (!kov[1][i]) {
            kov[1][i]=1;
        }
        suf[1]=1;
    }
    sort(sor.begin(), sor.end());
    for (auto x:sor) {
        int db=x.first, id=x.second;
        if(db==1) {
            suf[id]=1;
        } else {
            suf[id]=kov[suf[fel[id]]][ut[id]];
        }
        for (int i=0; i<k; i++) {
            if (!kov[id][i]) {
                kov[id][i]=kov[suf[id]][i];
            }
        }
    }
    for (int I=1; I<=q; I++) {
        int id;
        cin >> id;
        if (id==1) {
            int a, b;
            cin >> a >> b;
            int p=pos[a];
            if (m[p].find(ert[a])!=m[p].end()) {
                m[p].erase(m[p].find(ert[a]));
            }
            ert[a]=b;
            m[p].insert(ert[a]);
        } else {
            string s;
            cin >> s;
            int maxi=-1, p=1;
            for (auto c:s) {
                int cc=c-'a';
                p=kov[p][cc];
                for (int pp=p; vis[pp]<I; pp=suf[pp]) {
                    if (m[pp].size()>0) {
                        auto val=m[pp].end();
                        val--;
                        maxi=max(maxi, *val);
                    }
                    vis[pp]=I;
                }
            }
            cout << maxi << "\n";
        }
    }
	return 0;
}