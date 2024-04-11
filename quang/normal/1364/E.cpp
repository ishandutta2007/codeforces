#include <bits/stdc++.h>

using namespace std;

const int N = 3000;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

map<pair<int, int>, int> cache;

vector<int> ans;
int num = 0;

int ask(int u, int v) {
    if (cache.count({u, v})) return cache[{u, v}];
    num++;
    assert(num <= 4269);
    cout << "? " << u + 1 << ' ' << v + 1 << endl;
    int res;
    cin >> res;
    assert(res != -1);
    // res = ans[u] | ans[v];
    return cache[{u, v}] = cache[{v, u}] = res;
}

int find(vector<int> a, int mask) {
    if (a.size() == 1) return a[0];
    vector<int> b(a.size());
    b[0] = mask;
    // cout << "init " << b[0] << ' ' << a.size() << endl;
    for (int i = 1; i < a.size(); i++) {
        b[i] = ask(a[0], a[i]);
        b[0] &= b[i];
    }
    // cout << "here " << mask << ' ' << b[0] << endl;
    if (b[0] == 0) return a[0];
    if (b[0] == mask) {
        a.erase(a.begin());
        return find(a, mask);
    }
    vector<int> nxt;
    for (int i = 1; i < a.size(); i++) {
        if (b[i] == b[0]) {
            nxt.push_back(a[i]);
        }
    }
    return find(nxt, b[0]);
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    ans.assign(n, 0);
    for (int i = 0; i < n; i++) {
        a[i] = i;
        ans[i] = i;
    }
    shuffle(a.begin(), a.end(), rng);
    shuffle(ans.begin(), ans.end(), rng);

    int pos = find(a, (1 << (int)ceil(log2(n))) - 1);
    
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        if (pos == i) res[i] = 0;
        else {
            res[i] = ask(i, pos);
        }
    }
    for (auto val : cache) {
        assert(val.second == res[val.first.first] | res[val.first.second]);
    }
    // for (int i = 0; i < n; i++) {
    //     assert(res[i] == ans[i]);
    // }
    cout << "! ";
    for (int i = 0; i < n; i++) {
        cout << res[i];
        if (i + 1 < n) cout << ' ';
    }
    cout << endl;
    return 0;
}