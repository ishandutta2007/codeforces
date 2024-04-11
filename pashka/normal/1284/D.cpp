#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

struct seg {
    int i, s1, e1, s2, e2;

};

struct fen {
    vector<int> f;

    void init(int n) {
        f.assign(n + 1, INT_MAX);
    }

    long min(int r) { // exclusive
        r--;
        int result = INT_MAX;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            result = ::min(result, f[r]);
        return result;
    }

    void set(int i, int x) {
        for (; i < f.size(); i = (i | (i + 1)))
            f[i] = ::min(f[i], x);
    }
};

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<seg> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].s1 >> a[i].e1 >> a[i].s2 >> a[i].e2;
        a[i].i = i;
    }

    bool ok = true;
    for (int ttt = 0; ttt < 2; ttt++) {

        sort(a.begin(), a.end(), [](auto &a, auto &b) { return a.s1 < b.s1; });

        fen f1, f2;
        f1.init(n);
        f2.init(n);

        for (int i = n - 1; i >= 0; i--) {
            int l = i;
            int r = n;
            while (r > l + 1) {
                int m = (l + r) / 2;
                if (a[m].s1 <= a[i].e1) {
                    l = m;
                } else {
                    r = m;
                }
            }
            int x1 = f1.min(r);
            if (x1 < a[i].s2) ok = false;
            int x2 = -f2.min(r);
            if (x2 > a[i].e2) ok = false;
//            cout << a[i].s1 << " " << a[i].e1 << " " << a[i].s2 << " " << a[i].e2 << " " << x1 << " " << x2 << "\n";

            f1.set(i, a[i].e2);
            f2.set(i, -a[i].s2);
        }
        for (int i = 0; i < n; i++) {
            swap(a[i].s1, a[i].s2);
            swap(a[i].e1, a[i].e2);
        }
    }
    cout << (ok ? "YES" : "NO") << "\n";

    return 0;
}