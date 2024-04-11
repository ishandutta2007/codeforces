#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int a[101010];
vector<int> v;
vector<pair<int,int>> r;
vector<int> w;
int f[101010];
int g[101010];

void rip() {
    cout << "-1\n";
    exit(0);
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        if (a[i]) v.push_back(i);
        if (a[i] == 1) w.push_back(i);
    }
    reverse(w.begin(),w.end());
    int k = 0;
    for (int i = 0; i < v.size(); i++) {
        if (w.size() && w.back() == v[i]) w.pop_back();
        if (a[v[i]] == 1 && f[v[i]]) continue;
        f[v[i]] = 1;
        if (i == 0 || !g[v[i]]) {
            k++;
            r.push_back({k,v[i]});
        }
        if (a[v[i]] >= 2 && i == v.size()-1) rip();
        if (a[v[i]] == 2) {
            if (w.size() == 0) rip();
            if (f[w.back()] == 1) rip();
            r.push_back({k,w.back()});
            f[w.back()] = 1;
            w.pop_back();
        }
        if (a[v[i]] == 3) {
            int d = -1;
            for (int j = i+1; j < v.size(); j++) {
                if (!f[v[j]]) {d = v[j]; break;}
            }
            if (d == -1) rip();
            f[d] = 1;
            g[d] = 1;
            r.push_back({k,d});
            k++;
            r.push_back({k,d});
        }
    }
    cout << r.size() << "\n";
    for (auto u : r) {
        cout << u.first << " " << u.second << "\n";
    }
}