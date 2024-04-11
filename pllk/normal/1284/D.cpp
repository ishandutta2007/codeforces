#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int n;

set<int> s;
map<int,int> m;

#define N (1<<19)
int p[2*N];

void update(int k, int x) {
    k += N;
    if (p[k] < x) return;
    p[k] = x;
    for (k /= 2; k >= 1; k /= 2) {
        p[k] = min(p[2*k],p[2*k+1]);
    }
}

int findMin(int a, int b) {
    a += N; b += N;
    int r = p[a];
    while (a <= b) {
        if (a%2 == 1) r = min(r,p[a++]);
        if (b%2 == 0) r = min(r,p[b--]);
        a /= 2; b /= 2;
    }
    return r;
}

void check(vector<pair<int,int>> v1, vector<pair<int,int>> v2) {
    for (int i = 0; i < 2*N; i++) p[i] = 999999999;
    vector<vector<int>> e;
    for (int i = 0; i < n; i++) {
        e.push_back({v1[i].first,v1[i].second,i});
    }
    sort(e.begin(),e.end());
    set<pair<int,int>> u;
    for (int i = 0; i < n; i++) {
        int k = e[i][2];
        while (u.size()) {
            auto it = u.begin();
            if (it->first < e[i][0]) {
                int h = it->second;
                update(v2[h].second,v2[h].first);
                u.erase(it);
            } else {
                break;
            }
        }
        if (findMin(v2[k].first,N-1) <= v2[k].second) {
            cout << "NO\n";
            exit(0);
        }
        u.insert({e[i][1],k});
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    vector<pair<int,int>> v1, v2;
    for (int i = 1; i <= n; i++) {
        int a1, b1, a2, b2;
        cin >> a1 >> b1 >> a2 >> b2;
        s.insert(a1);
        s.insert(b1);
        v1.push_back({a1,b1});
        s.insert(a2);
        s.insert(b2);
        v2.push_back({a2,b2});
    }
    int c = 0;
    for (auto x : s) {
        m[x] = ++c;
    }
    for (int i = 0; i < n; i++) {
        v1[i].first = m[v1[i].first];
        v1[i].second = m[v1[i].second];
        v2[i].first = m[v2[i].first];
        v2[i].second = m[v2[i].second];
    }
    check(v1,v2);
    check(v2,v1);
    cout << "YES\n";
}