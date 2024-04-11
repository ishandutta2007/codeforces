#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

#define ll long long

int n;
int l[101010];
vector<int> v[101010];
ll s;
multiset<int> z;
ll u = 1e9;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> l[i];
    for (int i = 1; i <= n; i++) {
        int d;
        cin >> d;
        v[l[i]].push_back(d);
        s += d;
    }
    ll x = s;
    for (int i = 1; i <= 100000; i++) {
        if (v[i].size() == 0) continue;
        s = x;
        sort(v[i].begin(), v[i].end());
        reverse(v[i].begin(), v[i].end());
        vector<int> q;
        for (int j = 0; j < v[i].size(); j++) {
            s -= v[i][j];
            if (j != 0 && z.size() > 0) {
                auto it = z.end();
                it--;
                s -= *it;
                q.push_back(*it);
                z.erase(it);
            }
            u = min(u,s);
        }
        for (int j = 0; j < v[i].size(); j++) {
            z.insert(v[i][j]);
        }
        for (int j = 0; j < q.size(); j++) {
            z.insert(q[j]);
        }
    }
    cout << u << "\n";
}