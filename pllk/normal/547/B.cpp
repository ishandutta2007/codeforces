#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n;
vector<pair<int,int>> v;
int t[202020];
set<pair<int,int>> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.rbegin(), v.rend());
    int x = 0, u = 0;
    for (int i = 0; i < n; i++) {
        auto it = s.upper_bound({v[i].second,v[i].second});
        if (it != s.end()) {
            if (v[i].second+1 == it->first) {
                auto e = it;
                if (it != s.begin()) {
                    it--;
                    if (it->second+1 == v[i].second) {
                        pair<int,int> p = {it->first,e->second};
                        s.erase(e);
                        s.erase(it);
                        s.insert(p);
                        x = max(x, p.second-p.first+1);
                    } else {
                        pair<int,int> p = {v[i].second,e->second};
                        s.erase(e);
                        s.insert(p);
                        x = max(x, p.second-p.first+1);
                    }
                } else {
                    pair<int,int> p = {v[i].second,it->second};
                    s.erase(it);
                    s.insert(p);
                    x = max(x, p.second-p.first+1);
                }
            } else if (it != s.begin()) {
                it--;
                if (it->second+1 == v[i].second) {
                    pair<int,int> p = {it->first,v[i].second};
                    s.erase(it);
                    s.insert(p);
                    x = max(x, p.second-p.first+1);
                } else {
                    x = max(x, 1);
                    s.insert({v[i].second,v[i].second});
                }
            } else {
                x = max(x, 1);
                s.insert({v[i].second,v[i].second});
            }
        } else if (it != s.begin()) {
            it--;
            if (it->second+1 == v[i].second) {
                pair<int,int> p = {it->first,v[i].second};
                s.erase(it);
                s.insert(p);
                x = max(x, p.second-p.first+1);
            } else {
                x = max(x, 1);
                s.insert({v[i].second,v[i].second});
            }
        } else {
            x = max(x, 1);
            s.insert({v[i].second,v[i].second});
        }
        while (u < x) {
            u++;
            t[u] = v[i].first;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << t[i] << " ";
    }
    cout << "\n";
}