#include <bits/stdc++.h>

using namespace std;
const int c=1002, k=1<<20;
int n, m, q, ert[c], mini, inv[k], ts[c], cnt;
vector<int> sz[c];
bool v[c], sp[c];
string s;
void add(int a, int b, int c) {
    if (c) cout << "+ ";
    else cout << "- ";
    cout << a << " " << b << "\n";
}
void valt(int a, int b) {
    if (ert[a]&(1<<b)) add(a, ts[b], 0);
    else add(a, ts[b], 1);
}
void dfs(int a) {
    v[a]=true;
    for (int x:sz[a]) {
        if (!v[x]) dfs(x);
        ert[a]+=ert[x]*sp[x];
    }
    ts[cnt]=a;
    if (cnt<mini) {
        sp[a]=1;
        ert[a]=(1<<cnt);
    }
    cnt++;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    mini=min(n, 20);
    cout << mini*(mini-1)/2+4*(n-mini) << "\n";
    for (int i=1; i<=m; i++) {
        int a, b; cin >> a >> b;
        sz[a].push_back(b);
    }
    for (int i=1; i<=n; i++) {
        if (!v[i]) dfs(i);
    }

    for (int id=1; id<=n; id++) {
        if (sp[id]) {
            for (int i=1; i<=n; i++) {
                if (sp[i] && ert[id]>ert[i]) add(id, i, 1);
            }
        } else {
            bool jo=0;
            add(id, id, 1);
            for (int i=0; i<mini; i++) {
                for (int j=i+1; j<mini; j++) {
                    for (int k=j+1; k<mini; k++) {
                        int cel=ert[id]^(1<<i)^(1<<j)^(1<<k);
                        if (!jo && !inv[cel]) {
                            jo=1;
                            inv[cel]=id;
                            valt(id, i), valt(id, j), valt(id, k);
                        }
                    }
                }
            }
        }
    }
    while(q--) {
        int ans=0, kul=0;
        for (int i=0; i<mini; i++) {
            cout.flush() << "? " << 1 << " " << ts[i] << "\n";
            string s;
            cin >> s;
            if (s=="Lose") kul=ts[i];
            if (s=="Win") ans+=(1<<i);
        }
        ans=inv[ans];
        if (kul) ans=kul;
        cout.flush() << "! " << ans << "\n";
        cin >> s;
    }
    return 0;
}