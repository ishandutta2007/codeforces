#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int N = 3e5 + 10;
vector<int> c(N), f(N), pos;
int MOD;

int add(int a, int b) {
    return a + b >= MOD ? a + b - MOD : a + b;
}

int sub(int a, int b) {
    return a - b < 0 ? a - b + MOD : a - b;
}

bool get_ans() {
    while (pos.size() > 0) {
        int i = pos.back();
        if (c[i] != 0) {
            break;
        }
        pos.pop_back();
    }
    return (pos.size() == 0);
}

void upd(int i, int val) {
    if (val < 0) val += MOD;
    c[i] = add(c[i], val);
    pos.pb(i);
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q, bal = 0;
    cin >> n >> q >> MOD;
    f[1] = f[2] = 1;
    for (int i = 3; i < N; i++) {
        f[i] = add(f[i - 1], f[i - 2]);
    }
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        if (i == 0) c[0] = sub(b[0], a[0]);
        else if (i == 1) c[1] = sub(sub(b[1], a[1]), sub(b[0], a[0]));
        else c[i] = sub(sub(b[i], a[i]), add(sub(b[i - 1], a[i - 1]), sub(b[i - 2], a[i - 2])));
        pos.pb(i);
    }
    for (int i = 0; i < q; i++) {
        char a;
        cin >> a;
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (a == 'A') {
            upd(l, -1);
            if (r + 1 < n) upd(r + 1, f[r - l + 2]);
            if (r + 2 < n) upd(r + 2, f[r - l + 1]);
        } else {
            upd(l, 1);
            if (r + 1 < n) upd(r + 1, -f[r - l + 2]);
            if (r + 2 < n) upd(r + 2, -f[r - l + 1]);
        }
        cout << (get_ans() ? "YES\n" : "NO\n");
    }
    return 0;
}