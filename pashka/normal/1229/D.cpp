#include <bits/stdc++.h>

#define MIN_INT -2147483648
#define MAX_INT 2147483647
#define MIN_LONG -9223372036854775808L
#define MAX_LONG 9223372036854775807L

#define long long long int

using namespace std;

// @author: pashka

int k;
vector<int> p;
vector<bool> z;
vector<vector<int>> pp;
map<vector<int>, int> pr;

void bt(int i) {
    if (i == k) {
        pp.push_back(p);
        pr[p] = pp.size() - 1;
        return;
    }
    for (int j = 0; j < k; j++) {
        if (!z[j]) {
            p[i] = j;
            z[j] = true;
            bt(i + 1);
            z[j] = false;
        }
    }
}

struct mybitset {
    unsigned long l = 0;
    unsigned long r = 0;

    bool get(int i) {
        if (i < 60) {
            return (l >> i) & 1;
        } else {
            return (r >> (i - 60)) & 1;
        }
    }

    void set(int i) {
        if (!get(i)) cnt++;
        if (i < 60) {
            l |= 1ll << i;
        } else {
            r |= 1ll << (i - 60);
        }
    }

    int cnt = 0;
};

bool operator<(mybitset a, mybitset b) {
    return a.l < b.l || (a.l == b.l && a.r < b.r);
}

vector<int> merge(vector<int> a, vector<int> b) {
    vector<int> c(k);
    for (int i = 0; i < k; i++) {
        c[i] = a[b[i]];
    }
    return c;
}

int main() {
//    freopen("input.txt", "r", stdin);

    int n;
    scanf("%d%d", &n, &k);
    p.resize(k);
    z.resize(k);
    bt(0);

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            scanf("%d", &p[j]);
            p[j]--;
        }
        a[i] = pr[p];
    }

    int m = pp.size();

    vector<vector<int>> g(m, vector<int>(m));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            g[i][j] = pr[merge(pp[i], pp[j])];
        }
    }

    vector<vector<int>> gr(n + 1, vector<int>(m, n));
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            gr[i][j] = gr[i + 1][j];
            if (j == a[i]) {
                gr[i][j] = i;
            }
        }
    }

    map<pair<mybitset, int>, mybitset> mem;

    long res = 0;

    for (int i = 0; i < n; i++) {
        mybitset z;
        vector<int> r(m + 1, n);
        for (int j = 0; j < m; j++) {
            r[j] = gr[i][j];
        }
        sort(r.begin(), r.end());
        z.set(0);
        int jj = i;
        for (int j : r) {
//            if (j == jj) continue;
            res += z.cnt * (j - jj);
//            cout << i << " " << jj << " " << j << " " << s << "\n";
            jj = j;
            if (j == n) break;
            if (z.get(a[j])) continue;

            auto o = mem.find({z, a[j]});
            if (o == mem.end()) {
                mybitset zz = z;
                z.set(a[j]);
                vector<int> q = {a[j]};
                for (int h = 0; h < q.size(); h++) {
                    int y = q[h];
                    for (int x = 0; x < m; x++) {
                        if (!z.get(x)) continue;
                        int u = g[y][x];
                        if (!z.get(u)) {
                            z.set(u);
                            q.push_back(u);
                        }
                    }
                }
                mem[{zz, a[j]}] = z;
            } else {
                z = o->second;
            }
        }
    }
    cout << res << "\n";
    return 0;
}