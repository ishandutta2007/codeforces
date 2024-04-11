#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
bool has[N];

int query(vector<int> ls) {
    cout << ls.size() << endl;
    for (int u : ls) cout << u << ' ';
    cout << endl;

    int res;
    cin >> res;
    assert(res != -1);
    return res;
}

set<int> ask(set<int> s, int base) {
    while (s.size() >= base) {
        vector<int> ls;
        for (int u : s) {
            ls.push_back(u);
            if (ls.size() >= base) break;
        }
        
        for (int u : ls) {
            s.erase(u);   
            has[u] = 1;
        }

        int id = query(ls);
        for (int it = 0; it < base; it++) {
            if (has[id]) {
                has[id] = 0;
                s.insert(id);
            }
            id++;
            if (id > n) id = 1;
        }
    }
    return s;
}

int main() {
    cin >> n;
    // set<int> pool;
    // for (int i = 1; i <= n; i++) {
    //     pool.insert(i);
    // }
    pair<int, int> res(0, 0);

    for (int i = 1; i <= n; i++) {
        int cur = (n / i) - 1;
        int tot = cur * (i - 1);
        int now = n % i;
        if (now) tot += now - 1;

        res = max(res, {tot, i});
        
    }


    if (res.first == 0) {
        cout << 0 << endl;
        return 0;
    }

    set<int> s;
    for (int i = 1; i <= n; i += res.second) {
        for (int j = i; j < i + res.second - 1 && j < n; j++) {
            s.insert(j);
        }
    }

    ask(s, res.second);
    cout << 0 << endl;
    return 0;
}