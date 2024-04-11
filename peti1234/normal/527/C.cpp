#include <bits/stdc++.h>

using namespace std;
multiset<long long> t[2];
set<int> s[2];
long long h, w, q;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0);
    cin >> w >> h >> q;
    t[0].insert(-h), t[1].insert(-w);
    s[0].insert(0), s[0].insert(h), s[1].insert(0), s[1].insert(w);
    for (int i=1; i<=q; i++) {
        char c;
        int x, ert;
        cin >> c >> ert;
        if (c=='H') {
            x=0;
        } else {
            x=1;
        }
        auto i1=s[x].lower_bound(ert), i2=i1;
        i1--;
        s[x].insert(ert);
        int a=*i1, b=*i2;
        t[x].erase(t[x].find(a-b));
        t[x].insert(ert-b), t[x].insert(a-ert);
        auto m1=t[0].begin(), m2=t[1].begin();
        long long aa=*m1, bb=*m2;
        cout << aa*bb << "\n";
    }
    return 0;
}
/*
4 3 4
H 2
V 2
V 3
V 1
*/