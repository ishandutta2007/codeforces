#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))

using namespace std;

const int MAXN = (int) 1e5;

int a[MAXN + 1], k[MAXN + 1];
ll sp[MAXN + 1], sp2[MAXN + 1];

class SegTree {

private:

    struct Node {
        ll mx, sum;
        pair <ll, bool> lazy;
    };

    vector <Node> aint;
    int n;

public:

    inline void init(int _n) {
        n = _n;
        aint.resize(4 * n + 1);
    }

    inline void solve_lazy(int nod, int l, int r) {
        if(aint[nod].lazy.second == 0) {
            return ;
        }
        if(2 * nod + 1 <= 4 * n) {
            aint[2 * nod].lazy = aint[2 * nod + 1].lazy = aint[nod].lazy;
        }
        aint[nod].mx = aint[nod].lazy.first;
        aint[nod].sum = 1LL * aint[nod].mx * (r - l + 1);
        aint[nod].lazy.second = 0;
    }

    inline void refresh(int nod, int l, int r) {
        int mid = (l + r) / 2;
        solve_lazy(2 * nod, l, mid), solve_lazy(2 * nod + 1, mid + 1, r);
        aint[nod].mx = max(aint[2 * nod].mx, aint[2 * nod + 1].mx);
        aint[nod].sum = aint[2 * nod].sum + aint[2 * nod + 1].sum;
    }

    void fix(int nod, int left, int right, int l, int r, ll val) {
        solve_lazy(nod, left, right);
        if(l <= left && right <= r) {
            aint[nod].lazy = {val, 1};
            solve_lazy(nod, left, right);
        }
        else {
            int mid = (left + right) / 2;
            if(l <= mid) fix(2 * nod, left, mid, l, r, val);
            if(mid < r) fix(2 * nod + 1, mid + 1, right, l, r, val);
            refresh(nod, left, right);
        }
    }

    ll query(int nod, int left, int right, int l, int r) {
        solve_lazy(nod, left, right);
        if(l <= left && right <= r) {
            return aint[nod].sum;
        }
        else {
            int mid = (left + right) / 2;
            ll ans = 0;
            if(l <= mid) ans += query(2 * nod, left, mid, l, r);
            if(mid < r) ans += query(2 * nod + 1, mid + 1, right, l, r);
            refresh(nod, left, right);
            return ans;
        }
    }

    int get(int nod, int left, int right, ll val) {
        solve_lazy(nod, left, right);
        if(left == right) {
            if(aint[nod].mx <= val) return n + 1;
            return left;
        }
        else {
            int mid = (left + right) / 2;
            int ans;
            solve_lazy(2 * nod, left, mid), solve_lazy(2 * nod + 1, mid + 1, right);
            if(aint[2 * nod].mx > val) ans = get(2 * nod, left, mid, val);
            else ans = get(2 * nod + 1, mid + 1, right, val);
            refresh(nod, left, right);
            return ans;
        }
    }

};

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(i = 1; i < n; i++) {
        cin >> k[i];
        sp[i] = sp[i - 1] + k[i];
    }
    for(i = n - 1; i >= 0; i--) {
        sp[i + 1] = sp[i];
    }
    SegTree st; st.init(n);
    for(i = 1; i <= n; i++) {
        sp2[i] = sp2[i - 1] + sp[i];
        st.fix(1, 1, n, i, i, a[i] - sp[i]);
    }
    cin >> q;
    while(q > 0) {
        q--;
        char ch;
        cin >> ch;
        if(ch == '+') {
            int pos, x;
            cin >> pos >> x;
            ll cur = st.query(1, 1, n, pos, pos) + x;
            st.fix(1, 1, n, pos, st.get(1, 1, n, cur) - 1, cur);
        }
        else {
            int l, r;
            cin >> l >> r;
            cout << st.query(1, 1, n, l, r) + sp2[r] - sp2[l - 1] << "\n";
        }
    }
    //cin.close();
    //cout.close();
    return 0;
}