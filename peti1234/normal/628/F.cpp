#include <bits/stdc++.h>

using namespace std;
const int k=32;
int n, m, q, si, cnt[k];
vector<pair<int, int> > sz;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> q;
    sz.push_back({0, 0});
    sz.push_back({m, n});
    for (int i=1; i<=q; i++) {
        int a, b;
        cin >> a >> b;
        sz.push_back({a, b});
    }
    sort(sz.begin(), sz.end());
    si=sz.size();
    for (int p=1; p<si; p++) {
        int a=sz[p].first+5, b=sz[p-1].first+5, dif=sz[p].second-sz[p-1].second;
        if (dif<0 || a-b<dif) {
            cout << "unfair\n";
            return 0;
        }
        int db[5];
        for (int i=0; i<5; i++) {
            db[i]=(a-i)/5-(b-i)/5;
        }
        for (int mask=0; mask<32; mask++) {
            int ert=0;
            for (int i=0; i<5; i++) {
                if (mask & (1<<i)) ert+=db[i];
            }
            cnt[mask]+=min(ert, dif);
        }
    }
    for (int mask=1; mask<32; mask++) {
        if (cnt[mask]/__builtin_popcount(mask)<n/5) {
            cout << "unfair\n";
            return 0;
        }
    }
    cout << "fair\n";
    return 0;
}