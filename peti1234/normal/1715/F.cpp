#include <bits/stdc++.h>

using namespace std;
using ld = long double;
long double eps=1e-9, f=0.5, e=1;
vector<pair<ld, ld> > sz;
ld ask(int id) {
    cout.flush() << "? " << sz.size() << endl;
    std::cout << std::setprecision(12) << std::showpoint << std::fixed;
    for (auto x:sz) {
        if (!id) cout.flush() << x.first << " " << x.second << endl;
        else cout.flush() << x.second << " " << x.first << endl;
    }
    sz.clear();
    ld ans;
    cin >> ans;
    return ans;
}
void pb(ld a, ld b) {
    sz.push_back({a, b});
}
int n, m;
ld solve(int id) {
    pb(0, 0);
    pb(eps, 0);
    for (int i=1; i<=m; i++) {
        pb(n, i-f);
        pb(eps, i);
    }
    pb(0, m);
    ld ert=ask(id), nn=n;
    ld x=ert+e/(2*nn);
    return (1-x)*n;
}
int main()
{
    cin >> n >> m;
    ld a, b;
    a=solve(0);
    swap(n, m);
    b=solve(1);
    std::cout << std::setprecision(12) << std::showpoint << std::fixed;
    cout << "! " << a << " " << b << endl;
    return 0;
}