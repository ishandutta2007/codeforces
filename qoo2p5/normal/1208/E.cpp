#include <bits/stdc++.h>

using namespace std;

#define rep(i, s, t) for (int i = s; i < t; i++)
#define per(i, s, t) for (int i = s; i >= t; i--)
#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

const int INF = (int) (1e9 + 1e6 + 123);
const ll LINF = (ll) (1e18 + 1e9 + 123);

template<typename A, typename B> bool mini(A& x, const B& y) {
    if (y < x) {
        x = y;
        return true;
    }
    return false;
}

template<typename A, typename B> bool maxi(A& x, const B& y) {
    if (y > x) {
        x = y;
        return true;
    }
    return false;
}

bool test(int mask, int bit) {
    return mask & (1 << bit);
}

void run();

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(12);
    run();
    return 0;
}

const int N = (int) 1e6 + 123;

struct Tree {
    int n;
    vector<int> t;
    Tree() {}
    Tree(vector<int> a) {
        n = 1;
        while (n < sz(a)) {
            n *= 2;
        }
        t.resize(2 * n);
        rep(i, 0, sz(a)) {
            t[n + i] = a[i];
        }
        per(i, n - 1, 0) {
            t[i] = max(t[2 * i], t[2 * i + 1]);
        }
    }

    int get(int l, int r) {
        int res = -INF;
        for (l += n, r += n; l <= r; l /= 2, r /= 2) {
            if ((l & 1)) {
                maxi(res, t[l++]);
            }
            if (!(r & 1)) {
                maxi(res, t[r--]);
            }
        }
        return res;
    }
};

int n, w;
vector<int> a[N];
Tree t[N];
vector<int> ev[N];
int val[N];

void run() {
    cin >> n >> w;
    rep(i, 0, n) {
        int l;
        cin >> l;
        a[i].resize(l);
        for (int& x : a[i]) {
            cin >> x;
        }
        rep(j, 0, l + 1) {
            ev[j].push_back(i);
            if (w - 1 - j >= 0) {
                ev[w - 1 - j].push_back(i);
            }
        }
        t[i] = Tree(a[i]);
    }

    ll tot = 0;
    rep(j, 0, w) {
        for (int i : ev[j]) {
            tot -= val[i];
            int l = sz(a[i]) - 1 - (w - 1 - j);
            maxi(l, 0);
            int r = j;
            mini(r, sz(a[i]) - 1);
            assert(l <= r);
            val[i] = t[i].get(l, r);
            if (val[i] < 0) {
                l = sz(a[i]) - 1 - (w - 1 - j);
                r = j;
                if (l < 0 || r >= sz(a[i])) {
                    val[i] = 0;
                }
            }
            tot += val[i];
        }
        cout << tot << " ";
    }
    cout << "\n";
}