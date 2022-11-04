#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44


/*const int MOD = (int) 1e9 + 7;

inline int lgput(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (1LL * ans * a) % MOD;
        b >>= 1;
        a = (1LL * a * a) % MOD;
    }
    return ans;
}

inline void mod(int &x) {
    if(x >= MOD)
        x -= MOD;
}

inline void add(int &x, int y) {
    x += y;
    mod(x);
}

inline void sub(int &x, int y) {
    x += MOD - y;
    mod(x);
}

inline void mul(int &x, int y) {
    x = (1LL * x * y) % MOD;
}*/

using namespace std;

const int MAXN = (int) 1e5;

struct SegTree {

    int aint[4 * MAXN + 1][2], n;
    // 0  -
    // 1  +

    inline void init(int _n) {
        n = _n;
        for(int i = 1; i <= 4 * n; i++) {
            aint[i][0] = 0;
            aint[i][1] = 1;
        }
    }

    inline void push(int nod) {
        for(int i = 0; i < 2; i++) {
            aint[2 * nod][i] = aint[nod][aint[2 * nod][i]];
            aint[2 * nod + 1][i] = aint[nod][aint[2 * nod + 1][i]];
        }
        aint[nod][0] = 0;
        aint[nod][1] = 1;
    }

    void set(int nod, int left, int right, int l, int r, int sgn) {
        if(l > r) return ;

        if(l <= left && right <= r) {
            aint[nod][0] = aint[nod][1] = sgn;
            return ;
        }

        push(nod);

        int mid = (left + right) / 2;

        if(l <= mid) set(2 * nod, left, mid, l, r, sgn);
        if(mid < r) set(2 * nod + 1, mid + 1, right, l, r, sgn);
    }

    void swp(int nod, int left, int right, int l, int r) {
        if(l > r) return ;

        if(l <= left && right <= r) {
            aint[nod][0] ^= 1;
            aint[nod][1] ^= 1;
            return ;
        }

        push(nod);

        int mid = (left + right) / 2;

        if(l <= mid) swp(2 * nod, left, mid, l, r);
        if(mid < r) swp(2 * nod + 1, mid + 1, right, l, r);
    }

    int get(int nod, int left, int right, int pos, int sgn) {
        if(left == right) {
            return aint[nod][sgn];
        }

        push(nod);

        int mid = (left + right) / 2;

        if(pos <= mid) return get(2 * nod, left, mid, pos, sgn);
        return get(2 * nod + 1, mid + 1, right, pos, sgn);
    }

};

inline int get(vector < pair <int, int> > &arr, int x) {
    int n = arr.size(), res = -1;

    for(int step = 1 << 17; step; step >>= 1) {
        if(res + step < n && abs(arr[res + step].first) <= x) {
            res += step;
        }
    }

    return res + 1;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, q;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> q;

    vector < pair <int, int> > arr(n);
    for(i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr[i] = {x, i};
    }


    sort(arr.begin(), arr.end(), [&](const pair <int, int> &a, const pair <int, int> &b) {

                return abs(a.first) < abs(b.first);

         });

    SegTree st; st.init(n);

    while(q--) {
        string str;
        int x;

        cin >> str >> x;

        if(str == ">") {
            if(x >= 0) {
                st.set(1, 1, n, get(arr, x) + 1, n, 0);
            }
            else {
                x = abs(x);
                st.swp(1, 1, n, 1, get(arr, x - 1));
                st.set(1, 1, n, get(arr, x - 1) + 1, n, 0);
            }
        }
        else {
            if(x <= 0) {
                x = abs(x);
                st.set(1, 1, n, get(arr, x) + 1, n, 1);
            }
            else {
                st.swp(1, 1, n, 1, get(arr, x - 1));
                st.set(1, 1, n, get(arr, x - 1) + 1, n, 1);
            }
        }
    }

     vector <int> sol(n);
    for(i = 0; i < n; i++) {
        int cur = st.get(1, 1, n, i + 1, (arr[i].first >= 0 ? 1 : 0));
        sol[arr[i].second] = abs(arr[i].first) * (cur == 0 ? -1 : 1);
    }
    for(i = 0; i < n; i++) {
        cout << sol[i] << " ";
    }

    return 0;
}