#include <bits/stdc++.h>

using namespace std;
const int c=200005;
long long n, m, kezd[c], len[c], cnt[c], fen[c], alen[c], acnt[c];
vector<pair<pair<int, int>, int> > sz;
multiset<pair<int, int> > r;
void add(int a, long long b) {
    while (a<=n) {
        fen[a]=max(fen[a], b);
        a+=(a & -a);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    sz.push_back({{0, 0}, 0});
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        sz.push_back({{a, b}, i});
    }
    sort(sz.begin(), sz.end());
    for (int i=1; i<=n; i++) {
        kezd[i]=sz[i].first.first, len[i]=sz[i].first.second;
        add(i, kezd[i]+len[i]);
    }
    for (int i=1; i<=m; i++) {
        int pos, h;
        cin >> pos >> h;
        int ert=0;
        for (int j=20; j>=0; j--) {
            int kov=ert+(1<<j);
            if (kov<=n && fen[kov]<pos) {
                ert=kov;
            }
        }
        ert++;
        if (ert<=n && kezd[ert]<=pos) {
            len[ert]+=h;
            cnt[ert]++;
            add(ert, kezd[ert]+len[ert]);
            auto ub=r.upper_bound({kezd[ert], -1});
            while (ub!=r.end() && (*ub).first<=kezd[ert]+len[ert]) {
                len[ert]+=(*ub).second;
                cnt[ert]++;
                add(ert, kezd[ert]+len[ert]);
                r.erase(ub);
                ub=r.upper_bound({kezd[ert], 0});
            }
        } else {
            r.insert({pos, h});
        }
    }

    for (int i=1; i<=n; i++) {
        int id=sz[i].second;
        alen[id]=len[i], acnt[id]=cnt[i];
    }
    for (int i=1; i<=n; i++) {
        cout << acnt[i] << " " << alen[i] << "\n";
    }
    return 0;
}