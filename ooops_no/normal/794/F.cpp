#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 1e5 + 10;
int a[N], nxt[8 * N][10], sum[8 * N][10];

void build(int v, int l, int r){
    for (int i = 0; i < 10; i++) nxt[v][i] = i;
    if (l == r){
        for (int i = 0; i < 10; i++){
            int now = 1;
            while(a[l] > 0){
                sum[v][a[l] % 10] += now;
                a[l] /= 10;
                now *= 10;
            }
        }
        return;
    }
    int m = (l + r) / 2;
    build(2 * v, l, m), build(2 * v + 1, m + 1, r);
    for (int i = 0; i < 10; i++) sum[v][i] = sum[v * 2][i] + sum[v * 2 + 1][i];
}

void push(int v){
    vector<int> nxt1(10), nxt2(10), ans(10);
    for (int i = 0; i < 10; i++){
        nxt1[i] = nxt[v][nxt[v * 2][i]];
        nxt2[i] = nxt[v][nxt[v * 2 + 1][i]];
    }
    for (int i = 0; i < 10; i++){
        nxt[v * 2][i] = nxt1[i];
        nxt[v * 2 + 1][i] = nxt2[i];
    }
    for (int i = 0; i < 10; i++){
        ans[nxt[v][i]] += sum[v][i];
    }
    for (int i = 0; i < 10; i++){
        sum[v][i] = ans[i];
        nxt[v][i] = i;
    }
}

void update(int v, int tl, int tr, int l, int r, int u, int val){
    push(v);
    if (l > r) return;
    if (tl == l && tr == r){
        nxt[v][u] = val;
        push(v);
        return;
    }
    int tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, min(r, tm), u, val), update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, u, val);
    for (int i = 0; i < 10; i++) sum[v][i] = sum[v * 2][i] + sum[v * 2 + 1][i];
}

int get(int v, int tl, int tr, int l, int r){
    push(v);
    if (l > r) return 0;
    if (tl == l && tr == r){
        int ans = 0;
        for (int i = 0; i < 10; i++){
            ans += i * sum[v][i];
        }
        return ans;
    }
    int tm = (tl + tr) / 2;
    return get(2 * v, tl, tm, l, min(r, tm)) + get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r);
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    build(1, 0, n - 1);
    while(q--){
        int t;
        cin >> t;
        if (t == 1){
            int l, r, x, y;
            cin >> l >> r >> x >> y;
            l--, r--;
            update(1, 0, n - 1, l, r, x, y);
        }
        else{
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << get(1, 0, n - 1, l, r) << endl;
        }
    }
    return 0;
}