#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1e5 + 1;
const int P = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

struct pt {
    ll x = 0, y = 0, z = 0;
};

pt operator+(pt a, pt b) {
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

pt operator-(pt &a, pt &b) {
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

double dist(pt &a, pt &b) {
    pt c = a - b;
    return sqrt((double) (c.x * c.x + c.y * c.y + c.z * c.z));
}

double dist(pt &a) {
    return sqrt((double) (a.x * a.x + a.y * a.y + a.z * a.z));
}

double EPS = 0.0000001;

bool eq(double a, double b) {
    return abs(a - b) < EPS;
}

bool operator==(const pt &a, const pt &b) {
    return eq(a.x, b.x) && eq(a.y, b.y) && eq(a.z, b.z);
}

bool operator!=(const pt &a, const pt &b) {
    return !(a == b);
}

bool operator<(const pt &a, const pt &b) {
    if (a.x != b.x) return a.x < b.x;
    if (a.y != b.y) return a.y < b.y;
    return a.z < b.z;
}

vector<int> w[8];
set<pt> v[8];

bool check(int &Aw, int &v1w, int &v2w, int &v3w) {
    pt A = {w[Aw][0], w[Aw][1], w[Aw][2]};
    pt B = {w[v1w][0], w[v1w][1], w[v1w][2]};
    pt C = {w[v2w][0], w[v2w][1], w[v2w][2]};
    pt D = {w[v3w][0], w[v3w][1], w[v3w][2]};
    pt v1 = B - A, v2 = C - A, v3 = D - A;

    if (!eq(dist(v1), dist(v2)) || !eq(dist(v1), dist(v3)) || eq(dist(v1), 0)) {
        return false;
    }
    vector<pt> others = {
            (A + v1) + v2,
            A + v1 + v3,
            A + v2 + v3,
            A + v1 + v2 + v3
    };

    vector<int> used(8, -1);
    range(i, 8) {
        if (i == v1w || i == v2w || i == v3w || i == Aw) {
            used[i] = i + 8;
        }
    }
    for (int i = 0; i < 4; ++i) {
        range(j, 8) {
            if (used[j] == -1) {
                if (v[j].count(others[i])) {
                    used[j] = i;
                    break;
                }
            }
        }
    }
    range(i, 8) {
        if (used[i] == -1) return false;
    }
    cout << "YES\n";
    range(i, 8) {
        if (used[i] >= 8) {
            cout << w[i][0] << " " << w[i][1] << " " << w[i][2] << "\n";
        } else {
            int j = used[i];
            cout << others[j].x << " " << others[j].y << " " << others[j].z << "\n";
        }
    }
    exit(0);
}

mt19937 rng(199937);

bool check2(int A, int v1, int v2, int v3) {
        range(j, 6) {
            next_permutation(all(w[v1]));
            range(e, 6) {
                next_permutation(all(w[v2]));
                range(d, 6) {
                    next_permutation(all(w[v3]));
                    check(A, v1, v2, v3);
                }
            }
        }
}

void solve() {
    range(i, 8) {
        int x, y, z;
        cin >> x >> y >> z;
        w[i] = {x, y, z};
        range(j, 6) {
            next_permutation(all(w[i]));
            pt p = {w[i][0], w[i][1], w[i][2]};
            v[i].insert(p);
        }
    }
    for (int i = 1; i < 8; ++i) {
        for (int j = i + 1; j < 8; ++j) {
            for (int e = j + 1; e < 8; ++e) {
                check2(0, i, j, e);
            }
        }
    }
    cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}