#include <bits/stdc++.h>

using namespace std;
int n, m, spos, opos;
int sok=1e9+1, nagy=2*sok+10;
set<pair<int, int> > sor, oszlop, mezo;
bool jo(pair<int, int> a, pair<int, int> b) {
    return (a.first==b.first && a.second<=b.second);
}
bool kissor(pair<int, int> p) {
    auto it=sor.lower_bound(p);
    it--;
    pair<int, int> k=*it;
    return jo(k, p);
}
bool kisoszlop(pair<int, int> p) {
    auto it=oszlop.lower_bound(p);
    it--;
    pair<int, int> k=*it;
    return jo(k, p);
}
bool solve(int a, int b) {
    pair<int, int> p={a, b}, q={b, a};
    if (sor.find(p)!=sor.end()) {
        return 0;
    }
    if (kissor(p) || kisoszlop(q)) {
        return 1;
    }
    auto it=mezo.upper_bound(p);
    it--;
    int dif1=a-b, dif2=(*it).first-(*it).second;
    return (dif1!=dif2);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int a, b;
        cin >> a >> b;
        sor.insert({a, b});
        oszlop.insert({b, a});
    }
    sor.insert({0, 0}), oszlop.insert({0, 0}), mezo.insert({0, 0});
    sor.insert({nagy, nagy}), oszlop.insert({nagy, nagy});
    while (min(spos, opos)<sok) {
        while (sor.find({spos, opos})!=sor.end()) {
            spos++, opos++;
        }
        bool ks=kissor({spos, opos}), ko=kisoszlop({opos, spos});
        if (ks || ko) {
            if (ks) {
                spos++;
            }
            if (ko) {
                opos++;
            }
        } else {
            mezo.insert({spos, opos});
            auto it1=sor.lower_bound({spos, opos}), it2=oszlop.lower_bound({opos, spos});
            int mini=max(1, min((*it1).first-spos, (*it2).first-opos));
            spos+=mini, opos+=mini;
        }
    }
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        bool ans=solve(a, b);
        cout << (ans ? "WIN" : "LOSE") << "\n";
    }
    return 0;
}