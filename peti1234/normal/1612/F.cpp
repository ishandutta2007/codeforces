#include <bits/stdc++.h>

using namespace std;
int n, m, k, ans;
set<pair<int, int> > h, regi, uj;
void add(int a, int b) {
    pair<int, int> p={a, b};
    while (uj.size()>0 && p>=*uj.begin()) {
        auto it=uj.upper_bound(p);
        it--;
        if (b>=(*it).second) uj.erase(it);
        else break;
    }
    auto it=uj.lower_bound(p);
    if (it==uj.end() || b>(*it).second) uj.insert(p);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    for (int i=0; i<k; i++) {
        int a, b;
        cin >> a >> b;
        h.insert({a, b});
    }
    regi.insert({1, 1});
    while (true) {
        ans++;
        for (auto p:regi) {
            int a=p.first, b=p.second, kov=a+b+h.count({a, b});
            add(a, min(kov, m));
            add(min(kov, n), b);
        }
        swap(regi, uj);
        uj.clear();
        if (regi.count({n, m})) break;
    }
    cout << ans << "\n";
    return 0;
}