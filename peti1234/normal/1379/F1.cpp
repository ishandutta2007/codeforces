#include <bits/stdc++.h>

using namespace std;
const int c=400005;
int n, m, q;
bool baj;
set<pair<int, int> > o, e;
void add(int a, int b, int c) {
    if (c) {
        o.insert({a, b});
    } else {
        e.insert({a, b});
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    add(0, c, 0), add(c, 0, 0);
    add(0, c, 1), add(c, 0, 1);
    cin >> n >> m >> q;
    for (int i=1; i<=q; i++) {
        int a, b;
        cin >> a >> b;
        if (a%2) {
            auto it=o.upper_bound({a, b});
            while (b<=(*it).second) {
                auto s=*it;
                o.erase(it);
                it=o.upper_bound({a, b});
            }
            it--;
            if (b<(*it).second) {
                add(a, b, 1);
            }
            auto it2=e.upper_bound({a, b});
            if (b<=(*it2).second) {
                baj=1;
            }
        } else {
            auto it=e.upper_bound({a, b});
            it--;
            while (b>=(*it).second) {
                e.erase(it);
                it=e.upper_bound({a, b});
                it--;
            }
            it++;
            if (b>(*it).second) {
                add(a, b, 0);
            }
            auto it2=o.upper_bound({a, b});
            it2--;
            if (b>=(*it2).second) {
                baj=1;
            }
        }
        cout << (baj ? "NO" : "YES") << "\n";
    }
    return 0;
}