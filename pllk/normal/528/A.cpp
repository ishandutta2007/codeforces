#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int w, h, n;

set<pair<int,int>> ys, xs;
multiset<int> yp, xp;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> w >> h >> n;
    ys.insert(make_pair(0,h));
    yp.insert(h);
    xs.insert(make_pair(0,w));
    xp.insert(w);
    for (int i = 0; i < n; i++) {
        char t;
        int k;
        cin >> t >> k;
        if (t == 'H') {
            auto it = ys.upper_bound(make_pair(k,0));
            it--;
            int u = it->first;
            int z = it->second;
            ys.erase(it);
            ys.insert(make_pair(u, k-u));
            ys.insert(make_pair(k, z-(k-u)));
            yp.erase(yp.find(z));
            yp.insert(k-u);
            yp.insert(z-(k-u));
        } else {
            auto it = xs.upper_bound(make_pair(k,0));
            it--;
            int u = it->first;
            int z = it->second;
            xs.erase(it);
            xs.insert(make_pair(u, k-u));
            xs.insert(make_pair(k, z-(k-u)));
            xp.erase(xp.find(z));
            xp.insert(k-u);
            xp.insert(z-(k-u));
        }
        int a = *(yp.rbegin());
        int b = *(xp.rbegin());
        cout << (long long)a*b << "\n";
    }
}