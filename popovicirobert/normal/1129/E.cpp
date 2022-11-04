#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))

using namespace std;

inline int ask(vector <int> &s, vector <int> &t, int nod) {
    if(s.size() == 0) {
        return 0;
    }
    cout << s.size() << "\n";
    for(auto it : s) {
        cout << it << " ";
    }
    cout << "\n" << t.size() << "\n";
    for(auto it : t) {
        cout << it << " ";
    }
    cout << "\n" << nod << "\n";
    int ans;
    cin >> ans;
    return ans;
}

inline bool check(int pos, set <int> &nodes, int nod) {
    vector <int> s, t;
    auto it = nodes.begin();
    for(int i = 0; i <= pos; i++) {
        if(*it != nod) {
            s.push_back(*it);
        }
        it = next(it);
    }
    t.push_back(1);
    return ask(s, t, nod) > 0;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, j, n;
    //ios::sync_with_stdio(false);
    //cin.tie(0), cout.tie(0);
    cin >> n;
    vector <int> sz(n + 1);
    sz[1] = n;
    for(i = 2; i <= n; i++) {
        vector <int> s, t;
        for(j = 2; j <= n; j++) {
            s.push_back(j);
        }
        t.push_back(1);
        sz[i] = ask(s, t, i);
    }
    vector <int> ord(n + 1);
    iota(ord.begin(), ord.end(), 0);
    sort(ord.begin(), ord.end(), [&](const int &a, const int &b) {return sz[a] < sz[b];});
    set <int> nodes;
    for(i = 2; i <= n; i++) {
        nodes.insert(i);
    }
    vector <int> par(n + 1);
    for(i = 1; i <= n; i++) {
        do {
            int res = -1;
            for(int step = 1 << 9; step; step >>= 1) {
                if(res + step < nodes.size() && check(res + step, nodes, ord[i]) == 0) {
                    res += step;
                }
            }
            res++;
            if(res == nodes.size()) {
                break;
            }
            auto it = nodes.begin();
            for(j = 0; j < res; j++) {
                it = next(it);
            }
            par[*it] = ord[i];
            nodes.erase(it);
        }while(true);
    }
    cout << "ANSWER\n";
    for(i = 2; i <= n; i++) {
        cout << par[i] << " " << i << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}