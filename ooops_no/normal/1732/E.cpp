#include<bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int N = 5e4 + 10, K = 170;
const ll INF = 1e10;
int a[N], b[N], type[N], n, q;
ll ans[N];
ll res[N / K + 5][N];

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a % b);
    }
}

ll get_pos(int i) {
    int j = i / K;
    if (type[j] == -1) {
        ll g = gcd(a[i], b[i]);
        return (ll)a[i] * b[i] / (g * g);
    } else {
        ll g = gcd(type[j], b[i]);
        return (ll)type[j] * b[i] / (g * g);
    }
}

void upd_type(int i) {
    if (type[i] != -1) {
        for (int j = i * K; j < (i + 1) * K && j < n; j++) {
            a[j] = type[i];
        }
    }
    type[i] = -1;
}

void upd_block(int i) {
    ans[i] = INF;
    for (int j = i * K; j < (i + 1) * K && j < n; j++) {
        ans[i] = min(ans[i], get_pos(j));
    }
}

void upd(int l, int r, int x) {
    int L = l / K, R = r / K;
    upd_type(L), upd_type(R);
    int need = min(r - l + 1, K - l % K);
    while (need--) {
        a[l++] = x;
    }
    need = min(r - l + 1, (r + 1) % K);
    while (need--) {
        a[r--] = x;
    }
    upd_block(L);
    if (L != R) {
        upd_block(R);
    }
    if (l <= r) {
        for (int i = l / K; i <= r / K; i++) {
            ans[i] = INF;
            type[i] = x;
        }
    }
}

void pre_calc(int j) {
    vector<ll> mn(N, INF);
    for (int i = 0; i < N; i++) {
        res[j][i] = INF;
    }
    for (int i = j * K; i < (j + 1) * K && i < n; i++) {
        mn[b[i]] = b[i];
    }
    for (int i = N - 1; i >= 1; i--) {
        for (int f = i; f < N; f += i) {
            mn[i] = min(mn[i], mn[f]);
        }
        if (mn[i] != INF) {
            for (int f = i; f < N; f += i) {
                res[j][f] = min(res[j][f], (ll)f * mn[i] / ((ll)i * i));
            }
        }
    }
}

ll get(int l, int r) {
    ll anss = INF;
    int need = min(r - l + 1, K - l % K);
    while (need--) {
        anss = min(anss, get_pos(l++));
    }
    need = min(r - l + 1, (r + 1) % K);
    while (need--) {
        anss = min(anss, get_pos(r--));
    }
    if (l <= r) {
        for (int i = l / K; i <= r / K; i++) {
            if (type[i] == -1) {
                assert(ans[i] != -1);
                anss = min(anss, ans[i]);
            } else {
                anss = min(anss, res[i][type[i]]);
            }
        }
    }
    return anss;
}

signed main() {
#ifdef LOCAL
   // freopen("input.txt", "r", stdin);
#endif // LCOAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i < N; i++) {
        ans[i] = INF;
        type[i] = -1;
    }
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i * K < n; i++) {
        pre_calc(i);
        upd_block(i);
    }
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int l, r, x;
            cin >> l >> r >> x;
            l--, r--;
            upd(l, r, x);
        } else {
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << get(l, r) << endl;
        }
    }
    return 0;
}