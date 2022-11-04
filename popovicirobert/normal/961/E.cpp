#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 2e5;

int v[MAXN + 1];

vector < pair <int, int> > qry[MAXN + 1];

int aib[MAXN + 5];

inline void update(int pos) {
    for(int i = pos; i > 0; i -= lsb(i))
        aib[i]++;
}

inline int query(int pos) {
    int ans = 0;
    for(int i = pos; i <= MAXN; i += lsb(i))
        ans += aib[i];
    return ans;
}

int sol[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
        v[i] = min(v[i], n);
        if(v[i] > i) {
            qry[i + 1].push_back({i, 1});
            qry[v[i] + 1].push_back({i, -1});
        }
        // interval [i + 1, v[i]]
    }
    for(i = n; i >= 1; i--) {
        update(v[i]);
        for(auto it : qry[i]) {
            sol[it.first] += query(it.first) * it.second;
        }
    }
    ll ans = 0;
    for(i = 1; i <= n; i++) {
        ans += sol[i];
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}