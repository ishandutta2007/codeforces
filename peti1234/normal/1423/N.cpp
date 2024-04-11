#include <bits/stdc++.h>

using namespace std;
const int c=12502;
int n, m, cnt, ert[c], t[c];
vector<int> sz[c], s[c];
set<int> p;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        ert[a]++, ert[b]++;
        if (a<b) swap(a, b);
        sz[a].push_back(b), s[a].push_back(1);
    }
    for (int i=1; i<=n; i++) {
        int a=0, b=0, st=ert[i], fi;
        p.clear();
        for (int j=0; j<sz[i].size(); j++) {
            int x=sz[i][j];
            if (!t[x]) a++;
            else b++;
            p.insert(ert[x]);
        }
        for (int i=st-a; i<=st+b; i++) {
            if (p.find(i)==p.end()) {
                fi=i;
            }
        }
        ert[i]=fi;
        cnt+=st-fi;
        for (int j=0; j<sz[i].size(); j++) {
            int x=sz[i][j];
            if (st>fi && !t[x]) {
                s[i][j]--, t[x]=1, st--;
            }
            if (st<fi && t[x]) {
                s[i][j]++, t[x]=0, st++;
            }
        }
    }
    cout << cnt << "\n";
    for (int i=1; i<=n; i++) {
        if (t[i]) cout << i << " ";
    }
    cout << "\n";
    for (int i=1; i<=n; i++) {
        for (int j=0; j<sz[i].size(); j++) {
            cout << i << " " << sz[i][j] << " " << s[i][j] << "\n";
        }
    }
    return 0;
}