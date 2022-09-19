#include <bits/stdc++.h>

using namespace std;
int n, q;
set<int> s;
set<pair<int, int> > l;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    for (int i=0; i<=n+1; i++) {
        s.insert(i);
    }
    l.insert({0, 0}), l.insert({n+1, n+1});

    for (int i=1; i<=q; i++) {
        int id;
        cin >> id;
        if (id==0) {
            int a, b, c;
            cin >> a >> b >> c;
            if (c==0) {
                while (*s.lower_bound(a)<=b) {
                    s.erase(s.lower_bound(a));
                }
            } else {
                auto it=l.lower_bound({a, b});
                if ((*it).second<=b) continue;
                it=l.lower_bound({a, 0});
                it--;
                while ((*it).second>=b) {
                    l.erase(it);
                    it=l.lower_bound({a, 0});
                    it--;
                }
                l.insert({a, b});
            }
        }
        if (id==1) {
            int x;
            cin >> x;
            if (s.find(x)==s.end()) {
                cout << "NO\n";
            } else {
                auto it=s.lower_bound(x);
                int kezd, veg;
                it++, veg=*it;
                it--, it--, kezd=*it;
                auto it2=l.lower_bound({kezd+1, 0});
                if ((*it2).first<=x && (*it2).second<veg) {
                    cout << "YES\n";
                } else {
                    cout << "N/A\n";
                }
            }
        }
    }
    return 0;
}