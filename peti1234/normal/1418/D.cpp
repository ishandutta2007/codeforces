
#include <bits/stdc++.h>

using namespace std;
int n, m, x, y;
multiset<int> a, b;
void del(int x) {
    b.erase(b.find(x));
}
void add() {
    auto p=a.lower_bound(x), q=p;
    if (p!=a.begin()) {
        p--;
        b.insert(x-*p);
        if (q!=a.end()) {
            del(*q-*p);
        }
    }
    if (q!=a.end()) b.insert(*q-x);
    a.insert(x);
}
void tor() {
    auto p=a.lower_bound(x), q=p; q++;
    if (p!=a.begin()) {
        p--;
        del(x-*p);
        if (q!=a.end()) {
            b.insert(*q-*p);
        }
    }
    if (q!=a.end()) del(*q-x);
    a.erase(x);
}
void ans() {
    if (b.empty()) cout << 0 << "\n";
    else cout << *a.rbegin()-*a.begin()-*b.rbegin() << "\n";
}
int main()
{
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        cin >> x;
        add();
    }
    ans();
    for (int i=1; i<=m; i++) {
        cin >> y >> x;
        if (y) add();
        else tor();
        ans();
    }
    return 0;
}