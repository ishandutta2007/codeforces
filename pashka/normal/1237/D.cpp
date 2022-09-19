#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

struct segtree {

    vector<int> mins;
    int size;
    int nn;

    void set(int i, int x) {
        set(i, x, 0, 0, size);
    }

    void set(int i, int x, int n, int L, int R) {
        if (R == L + 1) {
            mins[n] = x;
        } else {
            int M = (L + R) >> 1;
            if (i < M) {
                set(i, x, 2 * n + 1, L, M);
            } else {
                set(i, x, 2 * n + 2, M, R);
            }
            mins[n] = min(mins[2 * n + 1], mins[2 * n + 2]);
        }
    }

    int getmin(int l, int r) {
        return getmin(l, r, 0, 0, size);
    }

    int getmin(int l, int r, int n, int L, int R) {
//        cout << "min " << l << " " << r << " " << L << " " << R << "\n";
        if (l >= R || L >= r) return MAX_INT;
        if (L >= l && R <= r) return mins[n];
        int M = (L + R) >> 1;
        return min(
                getmin(l, r, 2 * n + 1, L, M),
                getmin(l, r, 2 * n + 2, M, R));
    }

    int find_at_most_left(int l, int x) { // returns getmin i >= l : a[i] <= x
        return find_at_most_left(l, x, 0, 0, size);
    }

    int find_at_most_left(int l, int x, int n, int L, int R) {
        if (l >= R) return nn;
        if (mins[n] > x) return nn;
        if (R == L + 1) {
            return L;
        }
        int M = (L + R) >> 1;
        int res = find_at_most_left(l, x, 2 * n + 1, L, M);
        if (res == nn) {
            res = find_at_most_left(l, x, 2 * n + 2, M, R);
        }
        return res;
    }

    int find_at_most_right(int r, int x) { // returns max i <= r : a[i] <= x
        return find_at_most_right(r, x, 0, 0, size);
    }

    int find_at_most_right(int r, int x, int n, int L, int R) {
        if (r < L) return -1;
        if (mins[n] > x) return -1;
        if (R == L + 1) {
            return L;
        }
        int M = (L + R) >> 1;
        int res = find_at_most_right(r, x, 2 * n + 2, M, R);
        if (res == -1) {
            res = find_at_most_right(r, x, 2 * n + 1, L, M);
        }
        return res;
    }

    void init(vector<int> a) {
        nn = a.size();
        size = 1;
        while (size < nn) size *= 2;
        mins.resize(2 * size);
        for (int i = 0; i < nn; i++) {
            mins[size - 1 + i] = a[i];
        }
        for (int i = size - 2; i >= 0; i--) {
            mins[i] = std::min(mins[2 * i + 1], mins[2 * i + 2]);
        }
    }
    void init(int nn) {
        size = 1;
        while (size < nn) size *= 2;
        mins.resize(2 * size);
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(3 * n);
    for (int i = 0; i < n; i++) cin >> a[i];
    {
        int mx = a[0];
        int mn = a[0];
        for (int i = 0; i < n; i++) {
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);
        }
        if (mn * 2 >= mx) {
            for (int i = 0; i < n; i++) cout << "-1 ";
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        a[n + i] = a[i];
        a[2 * n + i] = a[i];
    }

    segtree st;
    st.init(a);

    vector<int> r(3 * n);

    for (int i = 3 * n - 1; i >= 0; i--) {
        r[i] = st.find_at_most_left(i, (a[i] - 1) / 2);
    }

    vector<int> res(3 * n);

    segtree st2;
    st2.init(3 * n);
    for (int i = 3 * n - 1; i >= 0; i--) {
        int x = st2.getmin(i + 1, min(3 * n, r[i]));
//        cout << x << " " << r[i] << "\n";
        x = min(x, r[i]);
        res[i] = x;
        st2.set(i, x);
//        for (int i = 0; i < 2 * n; i++) {
//            cout << st2.getmin(i, i + 1) << " ";
//        }
//        cout << "\n";
    }

//    for (int i = 0; i < 3 * n; i++) cout << a[i] << " "; cout << "\n";
//    for (int i = 0; i < 3 * n; i++) cout << r[i] << " "; cout << "\n";
//    for (int i = 0; i < 3 * n; i++) cout << res[i] << " "; cout << "\n";

    for (int i = 0; i < n; i++) {
        cout << res[i] - i << " ";
    }


    return 0;
}