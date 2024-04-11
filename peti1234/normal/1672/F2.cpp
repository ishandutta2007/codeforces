#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, kezd[c], veg[c], db[c], ert, cnt, ord[c];
bool v[c];
vector<int> sz[c];
void dfs(int a) {
    v[a]=true;
    for (auto x:sz[a]) {
        if (!v[x]) {
            dfs(x);
        }
    }
    ord[a]=++cnt;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> kezd[i];
            db[kezd[i]]++;
        }
        for (int i=1; i<=n; i++) {
            cin >> veg[i];
        }
        for (int i=1; i<=n; i++) {
            if (db[i]>db[ert]) {
                ert=i;
            }
        }
        for (int i=1; i<=n; i++) {
            if (kezd[i]!=ert && veg[i]!=ert) {
                sz[kezd[i]].push_back(veg[i]);
            }
        }
        for (int i=1; i<=n; i++) {
            if (!v[i]) {
                dfs(i);
            }
        }
        bool jo=1;
        for (int i=1; i<=n; i++) {
            for (auto x:sz[i]) {
                if (ord[x]>=ord[i]) {
                    jo=0;
                }
            }
        }

        cout << (jo ? "AC" : "WA") << "\n";

        for (int i=1; i<=n; i++) {
            kezd[i]=0, veg[i]=0, db[i]=0, ord[i]=0, v[i]=0;
            sz[i].clear();
        }
        cnt=0, ert=0;
    }
    return 0;
}
/*
1
3
1 2 3
2 3 1
*/