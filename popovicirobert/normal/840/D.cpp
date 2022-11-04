#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define ld long double
// 217
// 44

using namespace std;

const int INF = 1e9;
const int MAXN = (int) 3e5;

int arr[MAXN + 1];
int fr[MAXN + 1];

struct SegTree {
    vector < vector <int> > aint;
    int n;
    SegTree(int _n) {
        n = _n;
        aint.resize(4 * n + 1);
    }
    inline void refresh(int nod, int left, int right) {
        int i;
        for(i = left; i <= right; i++) {
            fr[arr[i]]++;
        }
        for(i = left; i <= right; i++) {
            if(fr[arr[i]] && fr[arr[i]] >= (right - left + 1) / 5) {
                aint[nod].push_back(arr[i]);
            }
            fr[arr[i]] = 0;
        }
    }
    void build(int nod, int left, int right) {
        if(left < right) {
            int mid = (left + right) / 2;
            build(2 * nod, left, mid);
            build(2 * nod + 1, mid + 1, right);
        }
        refresh(nod, left, right);
    }
    void query(int nod, int left, int right, int l, int r, vector <int> &vals) {
        if(l <= left && right <= r) {
            for(auto it : aint[nod]) {
                vals.push_back(it);
            }
        }
        else {
            int mid = (left + right) / 2;
            if(l <= mid) query(2 * nod, left, mid, l, r, vals);
            if(mid < r) query(2 * nod + 1, mid + 1, right, l, r, vals);
        }
    }
};

vector <int> pos[MAXN + 1];
int vis[MAXN + 1];

inline int get(int val, int p) {
    int sz = pos[val].size();
    int res = -1;
    for(int step = 1 << 18; step; step >>= 1) {
        if(res + step < sz && pos[val][res + step] <= p) {
            res += step;
        }
    }
    return res;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> q;
    for(i = 1; i <= n; i++) {
        cin >> arr[i];
        pos[arr[i]].push_back(i);
    }
    SegTree st(n);
    st.build(1, 1, n);
    for(int t = 1; t <= q; t++) {
        int l, r, k;
        cin >> l >> r >> k;
        vector <int> vals;
        st.query(1, 1, n, l, r, vals);
        int ans = INF;
        for(auto it : vals) {
            if(vis[it] < t) {
                int cur = get(it, r) - get(it, l - 1);
                if(cur > (r - l + 1) / k) {
                    ans = min(ans, it);
                }
            }
            vis[it] = t;
        }
        if(ans == INF) {
            ans = -1;
        }
        cout << ans << "\n";
    }
    //cin.close();
    //cout.close();
    return 0;
}