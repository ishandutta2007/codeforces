#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

int v[MAXN + 1], t[MAXN + 1];

ll aib[MAXN + 1];

inline void update(int pos, int n, int val) {
    for(int i = pos; i <= n; i += lsb(i)) {
        aib[i] += val;
    }
}

inline ll query(int pos) {
    ll ans = 0;
    for(int i = pos; i > 0; i -= lsb(i)) {
        ans += aib[i];
    }
    return ans;
}

struct Data {
    int pos;
    bool operator <(const Data &other) const {
        return v[pos] - query(pos) < v[other.pos] - query(other.pos);
    }
};

multiset <Data> mst;
multiset <Data> :: iterator it;

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for(i = 1; i <= n; i++) {
        cin >> t[i];
    }
    for(i = 1; i <= n; i++) {
        mst.insert({i});
        ll cur = 0;
        while(!mst.empty()) {
            it = mst.begin();
            if(v[it -> pos] - query(it -> pos) <= t[i]) {
               cur += v[it -> pos] - query(it -> pos);
               mst.erase(mst.begin());
            }
            else {
                break;
            }
        }
        update(1, n, t[i]);
        update(i + 1, n, -t[i]);
        cur += 1LL * mst.size() * t[i];
        cout << cur << " ";
    }
    //cin.close();
    //cout.close();
    return 0;
}