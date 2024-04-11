#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int maxn = 2e6;

struct tree{
    int va, vb;
};

tree q[maxn];

int a, b, n, zap;

void upd(int v, int l, int r, int k, int val){
    if (l == r){
        q[v].va = min(val + q[v].va, a);
        q[v].vb = min(val + q[v].vb, b);
        return;
    }
    int m = (l + r) / 2;
    if (k <= m)
        upd(2 * v, l, m, k, val);
    else
        upd(2 * v + 1, m + 1, r, k, val);
    q[v].va = q[2 * v].va + q[2 * v + 1].va;
    q[v].vb = q[2 * v].vb + q[2 * v + 1].vb;
}

int sum(int v, int tl, int tr, int l, int r, bool t){
    if (l > r)
        return 0;
    if (tl == l && tr == r)
        return t ? q[v].vb : q[v].va;
    int m = (tl + tr) / 2;
    return sum(2 * v, tl, m, l, min(r, m), t) + sum(2 * v + 1, m + 1, tr, max(l, m + 1), r, t);
}

int main()
{
    int k;
    cin >> n >> k >> a >> b >> zap;
    for (int i = 0; i < zap; i++){
        int t;
        cin >> t;
        if (t == 1){
            int d, a;
            cin >> d >> a;
            d--;
            upd(1, 0, n - 1, d, a);
        }
        else{
            int d;
            cin >> d;
            d--;
            cout << sum(1, 0, n - 1, 0, d - 1, 1) + sum(1, 0, n - 1, d + k, n - 1, 0) << '\n';
        }
    }
}