#include <bits/stdc++.h>

#define long long long int
using namespace std;

// @author: pashka

int main() {
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<vector<long>> a(n);
    vector<long> s(n);
    long q = 0;
    map<int, int> w;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[i].resize(x);
        for (int j = 0; j < x; j++) {
            cin >> a[i][j];
            s[i] += a[i][j];
            q += a[i][j];
            w[a[i][j]] = i;
        }
    }

    if (q % n != 0) {
        cout << "No\n";
        return 0;
    }
    q /= n;
    for (int i = 0; i < n; i++) {
        s[i] = s[i] - q;
    }

    vector<bool> good(1 << n);
    vector<int> ss(1 << n);
    for (int i = 0; i < n; i++) {
        for (int st : a[i]) {
            int x = st;
            int p = i;
            bool ok = true;
            int e = 0;
            while (!(e & (1 << p))) {
                e |= (1 << p);
                int xx = x - s[p];
                if (w.find(xx) == w.end()) {
                    ok = false;
                    break;
                }
                int pp = w[xx];
                if (pp < i) {
                    ok = false;
                    break;
                }
                x = xx;
                p = pp;
            }
            if (ok && p == i && x == st) {
                good[e] = true;
                ss[e] = st;
            }
        }
    }

    vector<bool> d(1 << n);
    d[0] = true;
    vector<int> p(1 << n);

    for (int x = 1; x < (1 << n); x++) {
        for (int y = x; y > 0; y = (y - 1) & x) {
            if (good[y] && d[x - y]) {
                d[x] = true;
                p[x] = y;
            }
        }
    }

    if (!d[(1 << n) - 1]) {
        cout << "No";
        return 0;
    }

    vector<int> resx(n), resp(n);

    int xxx = (1 << n) - 1;
    while (xxx > 0) {
        int y = p[xxx];
        int p = 0;
        while (!(y & (1 << p))) p++;
        int x = ss[y];
        int e = 0;
        while (!(e & (1 << p))) {
            e |= (1 << p);
            int xx = x - s[p];
            int pp = w[xx];

            resx[pp] = xx;
            resp[pp] = p;

            x = xx;
            p = pp;
        }
        xxx -= y;
    }

    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        cout << resx[i] << " " << resp[i] + 1 << "\n";
    }

    return 0;
}