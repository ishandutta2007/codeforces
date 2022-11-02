#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long

mt19937 rnd(51);

const int MOD = 998244353, N = 5e5 + 10;
int col[100];

struct st{
    int L_el, R_el, ans, ansL, ansR, ansLR;
};

st t[4 * N];

int add(int a, int b){
    return a + b >= MOD ? a + b - MOD : a + b;
}

int mul(int a, int b){
    return ((ll)a * b % MOD);
}

st merge(st a, st b){
    int ans = 0, ansr = 0, ansl = 0, anslr = 0, val = col[a.R_el * 10 + b.L_el];
    ans = add(ans, mul(a.ans, b.ans));
    ans = add(ans, mul(val, mul(a.ansR, b.ansL)));
    ansl = add(ansl, mul(val, mul(a.ansLR, b.ansL)));
    ansl = add(ansl, mul(a.ansL, b.ans));
    ansr = add(ansr, mul(val, mul(a.ansR, b.ansLR)));
    ansr = add(ansr, mul(a.ans, b.ansR));
    anslr = add(anslr, mul(a.ansL, b.ansR));
    anslr = add(anslr, mul(val, mul(a.ansLR, b.ansLR)));
    return {a.L_el, b.R_el, ans, ansl, ansr, anslr};
}

void update(int v, int l, int r, int pos, int val){
    if (l == r){
        t[v] = {val, val, val + 1, 1, 1, 0};
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) update(2 * v, l, m, pos, val);
    else update(2 * v + 1, m + 1, r, pos, val);
    t[v] = merge(t[v * 2], t[v * 2 + 1]);
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (int i = 0; i <= 9; i++){
        for (int j = 0; j <= 9; j++){
            if (i + j >= 10)
                col[i + j]++;
        }
    }
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++){
        update(1, 0, (int)(s.size()) - 1, i, s[i] - '0');
    }
    for (int i = 0; i < m; i++){
        int j;
        char c;
        cin >> j >> c;
        update(1, 0, (int)(s.size()) - 1, j - 1, c - '0');
        cout << t[1].ans << "\n";
    }
    return 0;
}