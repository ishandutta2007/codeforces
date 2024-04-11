#include <bits/stdc++.h>

using namespace std;
const int c=200005;
int w, n, k, ki[c], t[c];
map<int, vector<pair<int, int> > > sor, oszlop;
int holvan(int a) {
    return (ki[a] ? ki[a]=holvan(ki[a]) : a);
}
void unio(int a, int b) {
    a=holvan(a), b=holvan(b);
    if (a!=b) {
        t[a]=min(t[a], t[b]);
        ki[b]=a;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n >> k;
        for (int i=1; i<=n; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            t[i]=c;
            sor[a].push_back({b, i});
            oszlop[b].push_back({a, i});
        }

        for (auto pp:sor) {
            auto p=pp.second;
            sort(p.begin(), p.end());
            int si=p.size();
            for (int i=1; i<si; i++) {
                if (p[i].first-p[i-1].first<=k) {
                    unio(p[i].second, p[i-1].second);
                }
            }
        }
        for (auto pp:oszlop) {
            auto p=pp.second;
            sort(p.begin(), p.end());
            int si=p.size();
            for (int i=1; i<si; i++) {
                if (p[i].first-p[i-1].first<=k) {
                    unio(p[i].second, p[i-1].second);
                }
            }
        }

        vector<int> ert;
        for (int i=1; i<=n; i++) {
            if (holvan(i)==i) {
                ert.push_back(t[i]);
            }
        }
        sort(ert.begin(), ert.end());
        int si=ert.size(), ans=si-1;
        for (int i=0; i<si; i++) {
            ans=min(ans, max(ert[i], si-i-2));
        }

        cout << ans << "\n";
        for (int i=0; i<=n; i++) {
            ki[i]=0, t[i]=0;
        }
        sor.clear(), oszlop.clear();
    }
    return 0;
}