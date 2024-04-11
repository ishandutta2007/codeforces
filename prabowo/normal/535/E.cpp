#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back

typedef long long LL;
typedef pair<LL, LL> pii;

int n;
pair<pii, int> comp[200002], comp2[200002];

LL cross (pii x, pii y, pii z) {
    return (x.fi * z.fi - y.fi * z.fi) * (x.se * y.se - x.se * z.se) - (x.se * z.se - y.se * z.se) * (x.fi * y.fi - x.fi * z.fi);
}

bool cmp (pair<pii, int> x, pair<pii, int> y) {
    return x.fi == y.fi;
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%I64d %I64d", &comp[i].fi.fi, &comp[i].fi.se);
        comp[i].se = i;
    }


    sort(comp, comp+n);
    int unik = 1;
    comp2[0] = comp[0];
    for (int i=0; i<n-1; i++) {
        if (comp[i].fi != comp[i+1].fi) comp2[unik++] = comp[i+1];
    }

    vector <int> hull;
    for (int i=0; i<unik; i++) {
        while (hull.size() >= 2 && cross(comp2[hull[hull.size()-2]].fi, comp2[hull.back()].fi, comp2[i].fi) > 0) hull.pop_back();
        hull.push_back(i);
    }

    //for (int i=0; i<hull.size(); i++) cout << comp2[hull[i]].fi.fi << " " << comp2[hull[i]].fi.se << endl;

    vector <int> ans;
    while (hull.size() >= 2) {
        pii bef = comp2[hull[hull.size()-2]].fi;
        pii now = comp2[hull.back()].fi;

        if (bef.se <= now.se) break;

        ans.pb(hull.back());
        hull.pop_back();
    }
    ans.pb(hull.back());
    //for (int i=0; i<ans.size(); i++) cout << comp2[ans[i]].fi.fi << " " << comp2[ans[i]].fi.se << endl;

    set <pii> s;
    for (int i=0; i<ans.size(); i++) s.insert(comp2[ans[i]].fi);

    vector <int> ans2;
    for (int i=0; i<n; i++) if (s.count(comp[i].fi)) ans2.pb(comp[i].se);
    sort(ans2.begin(), ans2.end());

    for (int i=0; i<ans2.size(); i++) printf("%d ", ans2[i] + 1);
    printf("\n");

    return 0;
}