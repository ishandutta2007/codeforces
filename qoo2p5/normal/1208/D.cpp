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

const int N = 1 << 18;

ll t[2 * N];
ll toadd[2 * N];
int n;
int p[N];

void push(int i, int tl, int tr) {
    t[i] += toadd[i];
    if (tl != tr - 1) {
        toadd[2 * i + 1] += toadd[i];
        toadd[2 * i + 2] += toadd[i];
    }
    toadd[i] = 0;
}

void add(int i, int tl, int tr, int l, int r, ll x) {
    push(i, tl, tr);
    if (tl >= r || tr <= l) {
        return;
    }
    if (l <= tl && tr <= r) {
        toadd[i] += x;
        push(i, tl, tr);
        return;
    }
    int tm = (tl + tr) / 2;
    add(2 * i + 1, tl, tm, l, r, x);
    add(2 * i + 2, tm, tr, l, r, x);
    t[i] = min(t[2 * i + 1], t[2 * i + 2]);
}

int find() {
    int i = 0;
    int tl = 0;
    int tr = N;
    while (tl != tr - 1) {
        int tm = (tl + tr) / 2;
        push(i, tl, tr);
        push(2 * i + 1, tl, tm);
        push(2 * i + 2, tm, tr);
        if (t[i] == t[2 * i + 2]) {
            i = 2 * i + 2;
            tl = tm;
        } else {
            i = 2 * i + 1;
            tr = tm;
        }
    }
    return tl;
}

void run() {
    cin >> n;
    rep(i, 0, n) {
        ll x;
        cin >> x;
        add(0, 0, N, i, i + 1, x);
    }
    add(0, 0, N, n, N, LINF);
    rep(i, 0, n) {
        int pos = find();
        p[pos] = i + 1;
        add(0, 0, N, pos + 1, n, -(i + 1));
        add(0, 0, N, pos, pos + 1, LINF);
    }
    rep(i, 0, n) {
        cout << p[i] << " ";
    }
    cout << "\n";
}