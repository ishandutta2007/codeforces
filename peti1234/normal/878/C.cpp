#include <bits/stdc++.h>

using namespace std;
int n, k;
struct cs {
    int e[12], gy[12], db;
    bool operator< (const cs&x) const{
        for (int i=1; i<=k; i++) if (e[i]>x.gy[i]) return 0;
        return 1;
    }
}p;
set<cs> sz;
int main()
{
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        p.db=1;
        for (int i=1; i<=k; i++) {int x; cin >> x; p.e[i]=x, p.gy[i]=x;}
        auto x=sz.lower_bound(p), y=sz.upper_bound(p);
        while(x!=y) {
            for (int i=1; i<=k; i++) {
                p.e[i]=max(p.e[i], x->e[i]);
                p.gy[i]=min(p.gy[i], x->gy[i]);
            }
            p.db+=x->db; sz.erase(x++);
        }
        sz.insert(p);
        cout << sz.rbegin()->db << "\n";
    }
    return 0;
}