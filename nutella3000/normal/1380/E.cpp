#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 1e15 + 7;

struct dsu {
    vector<int> parent;
    dsu(int n) {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }

    int get(int v) {
        int p = v;
        while(parent[v] != v) v = parent[v];
        while(p != v) {
            int t = parent[p];
            parent[p] = v;
            p = t; 
        }
        return v;
    }

    void merge(int v1, int v2) {
        parent[v1] = v2;
    }
};

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    vector<set<int>> a(m);
    dsu b = dsu(m);
    int res = n - 1;
    int last = -1;
    for(int i = 0;i < n;i++) {
        int v;
        cin >> v;
        v--;
        if (v == last) res--;
        a[v].emplace(i);
        last = v;
    }

    cout << res << endl;

    for(int test = 0;test < m - 1;test++) {
        int v1, v2;
        cin >> v1 >> v2;
        v1--; v2--;

        v1 = b.get(v1);
        v2 = b.get(v2);

        if(a[v1].size() < a[v2].size()) {
            b.merge(v1, v2);            
            swap(v1, v2);
        } 

        for(int i : a[v2]) {
            if (a[v1].find(i - 1) != a[v1].end()) res--;
            if (a[v1].find(i + 1) != a[v1].end()) res--;
        }
        for(int i : a[v2]) a[v1].emplace(i);
            
        cout << res << endl;
    }
}