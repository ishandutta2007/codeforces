#ifdef ONPC
    #define _GLIBCXX_DEBUG
    #define deb(a) cerr << "@@@@@@@ " << #a << " = " << a << endl;
#else
    #define deb(a)
#endif
#define sz(a) ((int)((a).size()))
#include <bits/stdc++.h>
#define char unsigned char

using namespace std;
mt19937 rnd(240);
// mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

bool ask1(int v, int u) {
    cout << "1 " << v << ' ' << u << endl;
    int x;
    cin >> x;
    if (x == -1) { while (true);
    }
    return x;
}

bool ask2(int v, vector<int> u) {
    if (sz(u) == 0) {
        return false;
    }
    cout << "2 " << v << ' ' << sz(u);
    for (int u1 : u) {
        cout << ' ' << u1;
    }
    cout << endl;
    int x;
    cin >> x;
    return x;
}

vector<int> takeSegment(int l, int r, vector<int>& sorted) {
    vector<int> a;
    for (int i = l; i < r; i++) {
        a.push_back(sorted[i]);
    }
    return a;
}

int solve() {
    int n;
    cin >> n;
    vector<int> verts(n);
    for (int i = 0; i < n; i++) {
        verts[i] = i;
    }
    //shuffle(verts.begin(), verts.end(), rnd);
    vector<int> sorted;
    for (int i : verts) {
        
        int l = -1, r = sz(sorted);
        while (r - l > 1) {
            int mid = (r + l) / 2;
            if (ask1(i, sorted[mid])) {
                l = mid;
            } else {
                r = mid;
            }
        }
        sorted.insert(sorted.begin() + r, i);
    }
    reverse(sorted.begin(), sorted.end());
    /*
    for (int i : sorted) {
        cout << i << ' ';
    }
    cout << endl;*/
    vector<vector<int>> graph(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            graph[sorted[i]][sorted[j]] = 1;
        }
    }
    vector<vector<int>> groups;
    {
        int i = n - 1;
        while (i >= 0) {
            int curv = i;
            int l = i;
            while (true) {
                while (ask2(sorted[curv], takeSegment(0, l, sorted))) {
                    l--;
                }
                if (l == curv) {
                    break;
                }
                curv--;
            }
            //cout << "group " << sorted[l] << ' ' << sorted[i] << endl;
            vector<int> group;
            for (int x = l; x <= i; x++) {
                group.push_back(sorted[x]);
            }
            groups.push_back(group);
            i = l - 1;
        }
    }

    for (vector<int> group : groups) {
        for (int i : group) {
            for (int j : group) {
                graph[i][j] = 1;
            }
        }
    }
    cout << 3 << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << graph[i][j];
        }
        cout << endl;
    }
    int x;
    cin >> x;
    return 0;
}

int32_t main() {
    int TET = 1e9;
    cin >> TET;
    for (int i = 1; i <= TET; i++) {
        solve();
    }
    return 0;
}