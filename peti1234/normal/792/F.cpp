#include <bits/stdc++.h>

using namespace std;
using ld = long double;
int q, ut, m2=1e6;
ld m;
set<pair<ld, ld> > s;
int ii;
bool jo(pair<ld, ld> p) {
    pair<ld, ld> p1, p2;
    if (s.find(p)!=s.end()) {
        auto it=s.find(p);
        ++it;
        if (it==s.end()) return true;
        p2=*it;
        --it, --it;
        p1=*it;
    } else {
        auto it=s.upper_bound(p);
        if (it==s.end()) return true;
        p2=*it;
        --it;
        p1=*it;
    }
    ld s=(p2.second-p1.second)*(p.first-p1.first)-(p2.first-p1.first)*(p.second-p1.second);
    return s>=1e-9;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> q >> m;
    s.insert({0, 0});
    for (int i=1; i<=q; i++) {
        ii=i;
        int id, a, b;
        cin >> id >> a >> b;
        a=(a+ut)%m2+1, b=(b+ut)%m2+1;
        pair<ld, ld> p={a, b};
        if (id==1) {
            if (jo(p)) {
                s.insert(p);
                while (true) {
                    auto it=s.find(p);
                    it++;
                    if (it==s.end() || jo(*it)) break;
                    s.erase(it);
                }
                while (true) {
                    auto it=s.find(p);
                    it--;
                    if (it==s.begin()) break;
                    if (jo(*it)) break;
                    s.erase(it);
                }
            }
        }
        if (id==2) {
            long double t=a;
            if (jo({b/t-1e-15, m/t})) {
                cout << "NO\n";
            } else {
                cout << "YES\n";
                ut=i;
            }
        }
    }
    return 0;
}