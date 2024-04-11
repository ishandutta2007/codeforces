#include <bits/stdc++.h>

using namespace std;
int n, m;
map<int, vector<int> > k;
int kov(int pos, set<pair<int, int> > &r) {
    if (r.size()==0) {
        return n+1;
    }
    if (pos<=(*r.begin()).first) {
        return ((*r.begin()).first);
    }
    auto ut=r.end();
    ut--;
    if (pos>(*ut).second) {
        return n+1;
    }
    auto it=r.upper_bound({pos, 0});
    int ert=(*it).first;
    it--;
    if ((*it).second>=pos) {
        ert=pos;
    }
    return ert;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=m; i++) {
        int x, y;
        cin >> x >> y;
        k[x].push_back(y);
    }
    set<pair<int, int> > r={{1, 1}};
    int el=0;
    for (auto p:k) {
        //cout << "proba " << p.first << " " << el << "\n";
        if (el+1!=p.first) {
            int fi=(*r.begin()).first;
            r.clear();
            r.insert({fi, n});
        }
        set<int> u;
        for (auto x:p.second) {
            u.insert(x);
        }
        u.insert(n+1);
        set<pair<int, int> > r2;
        int pos=0;
        auto ut=r.end();
        ut--;
        while (pos<=(*ut).second) {
            pos=kov(pos, r);
            while (u.find(pos)!=u.end()) {
                pos++;
            }
            if (kov(pos, r)==pos) {
                auto pos2=u.upper_bound(pos);
                r2.insert({pos, (*pos2)-1});
                pos=*pos2;
            }
        }
        r=r2;
        //cout << "vege " << r.size() << "\n";
        for (auto x:r) {
            //cout << x.first << " " << x.second << "\n";
        }
        el=p.first;
        if (r.size()==0) {
            break;
        }

    }

    if (el!=n && r.size()>0) {
        int fi=(*r.begin()).first;
        r.clear();
        r.insert({fi, n});
    }

    cout << (kov(n, r)==n ? 2*n-2 : -1) << "\n";
    return 0;
}
/*
10 3
1 3
2 2
3 1
*/