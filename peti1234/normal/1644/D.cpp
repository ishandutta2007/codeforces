#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long w, n, m, db, q, sor[c], oszlop[c], sdb, odb, mod=998244353;
vector<pair<int, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> m >> db >> q;
        for (int i=1; i<=q; i++) {
            int a, b;
            cin >> a >> b;
            sz.push_back({a, b});
        }
        reverse(sz.begin(), sz.end());
        long long ans=1;
        for (auto p:sz) {
            int a=p.first, b=p.second;
            if (sor[a] && oszlop[b] || sdb==n || odb==m) continue;
            ans=ans*db%mod;
            if (!sor[a]) sor[a]=1, sdb++;
            if (!oszlop[b]) oszlop[b]=1, odb++;
        }

        cout << ans << "\n";

        for (auto p:sz) {
            int a=p.first, b=p.second;
            sor[a]=0, oszlop[b]=0;
        }
        sdb=0, odb=0;
        sz.clear();
    }

    return 0;
}