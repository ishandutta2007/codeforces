#include <bits/stdc++.h>
#define MAXN 300000
#define zeros(x) (x & (-x))

using namespace std;

pair <int, int> vec[2* MAXN + 1];

struct Data {
    int l, r;
    int pos;
    bool operator <(const Data &other) const {
        return r < other.r;
    }
}v[MAXN + 1];

int aib[2 * MAXN + 1];

inline void update(int pos) {
    for(int i = pos; i <= 2 * MAXN; i += zeros(i))
        aib[i]++;
}

inline int query(int pos) {
    int ans = 0;
    for(int i = pos; i > 0; i -= zeros(i))
        ans += aib[i];
    return ans;
}

int sol[MAXN + 1];

int main() {
    //fstream cin("B.in");
    //ofstream cout("B.out");
    int n, i;
    ios::sync_with_stdio(false);
    cin >> n;
    int sz = 0;
    for(i = 1; i <= n; i++) {
        cin >> v[i].l >> v[i].r;
        vec[++sz].first = v[i].l;
        vec[sz].second = sz;
        vec[++sz].first = v[i].r;
        vec[sz].second = sz;
        v[i].pos = i;
    }
    sort(vec + 1, vec + sz + 1);
    for(i = 1; i <= sz; i++) {
        if(vec[i].second % 2 == 1)
            v[(vec[i].second + 1) / 2].l = i;
        else
            v[(vec[i].second + 1) / 2].r = i;
    }
    sort(v + 1, v + n + 1);
    for(i = 1; i <= n; i++) {
        sol[v[i].pos] = query(v[i].r) - query(v[i].l);
        update(v[i].l);
    }
    for(i = 1; i <= n; i++)
        cout << sol[i] << endl;
    //cin.close();
    //cout.close();
    return 0;
}