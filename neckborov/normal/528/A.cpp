//#pragma GCC optimize("O3")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
//#pragma GCC optimize ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;


const ld INF = 1e18;

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int w, h, n;
    cin >> w >> h >> n;
    set<int> a, b;
    multiset<int, greater<int>> al, bl;
    a.insert(0);
    a.insert(h);
    b.insert(0);
    b.insert(w);
    al.insert(h);
    bl.insert(w);
    for (int i = 0; i < n; i++) {
        char c;
        int x;
        cin >> c >> x;
        if (c == 'H') {
            auto l = a.lower_bound(x);
            auto r = l--;
            al.erase(al.find(*r - *l));
            al.insert(x - *l);
            al.insert(*r - x);
            a.insert(x);
        } else {
            auto l = b.lower_bound(x);
            auto r = l--;
            bl.erase(bl.find(*r - *l));
            bl.insert(x - *l);
            bl.insert(*r - x);
            b.insert(x);
        }
        cout << ll(*al.begin()) * (*bl.begin()) << '\n';
    }
    return 0;
}