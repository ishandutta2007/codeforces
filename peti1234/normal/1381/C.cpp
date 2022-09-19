#include <bits/stdc++.h>

using namespace std;
#define rep() for (int i=1; i<=n; i++)
const int c=100002;
int w, n, t[c], db[c], fix[c], x, y, ki, ans[c], h1, h2;
vector<int> sz[c], s[c], sor;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n >> x >> y, y-=x, ki=n+1, h1=0, h2=0, db[n+1]=0, sor.clear();
        rep() db[i]=0, fix[i]=0, ans[i]=0, sz[i].clear(), s[i].clear();
        rep() cin >> t[i], db[t[i]]++, sz[db[t[i]]].push_back(t[i]), s[db[t[i]]].push_back(i);
        for (int i=n; i>=1; i--) {
            int si=sz[i].size();
            for (int j=si-1; j>=0 && x; j--) x--, fix[sz[i][j]]++, sz[i].pop_back(), s[i].pop_back();
            for (int j=0; j<sz[i].size(); j++) sor.push_back(s[i][j]);
        }
        rep() {
            int si=sz[i].size();
            if (db[i]==0) ki=i;
            if (si>1) h2=i;
            if (si) h1=i;
        }
        for (int i=n; i>=1; i--) if (fix[t[i]]) fix[t[i]]--, ans[i]=t[i];
        for (int i=0; i<sor.size(); i++) {
            int a=sz[h1].back(), si=sz[h2].size(), b=0, x=sor[i], p=t[x];
            if (h2) b=sz[h2][si-1];
            if (y) {
                if (p!=a) {
                    sz[h1].pop_back(), ans[x]=a, y--;
                    if (sz[h1].size()==0) h1--;
                    if (sz[h2].size()==1) h2--;
                } else if (h2) {
                    sz[h2].pop_back(), y--;
                    if (a!=b) ans[x]=b;
                    else ans[x]=sz[h2].back(), sz[h2].pop_back(), sz[h2].push_back(a);
                    if (sz[h2].size()==1) h2--;
                } else ans[x]=ki;
            } else ans[x]=ki;
        }
        if (x || y) cout << "NO\n";
        else {
            cout << "YES\n";
            rep() cout << ans[i] << " ";
            cout << "\n";
        }
    }
    return 0;
}