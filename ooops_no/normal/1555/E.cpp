#include<iostream>
#include<vector>
#include<algorithm>
#include<random>
#include<map>
using namespace std;

#define pb push_back
#define ld long double
#define int long long
#define ll long long

mt19937 rnd(51);

const int N = 1e6 + 10;
int t[4 * N], add[4 * N];

struct seg{
    int l, r, w;
};

bool cmp(seg a, seg b){
    return a.w < b.w;
}

void push(int v){
    t[v] += add[v];
    if (v * 2 < 4 * N){
        add[v * 2] += add[v];
        add[v * 2 + 1] += add[v];
    }
    add[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int val){
    push(v);
    if (l > r) return;
    if (tl == l && tr == r){
        add[v] += val;
        push(v);
        return;
    }
    int tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, min(r, tm), val), update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<seg> v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i].l >> v[i].r >> v[i].w;
        v[i].l--;
        v[i].r -= 2;
    }
    sort(v.begin(), v.end(), cmp);
    int now = 0, ans = 1e18;
    for (int i = 0; i < n; i++){
        if (i > 0){
            update(1, 0, m - 2, v[i - 1].l, v[i - 1].r, -1);
        }
        while(now < n && t[1] == 0){
            update(1, 0, m - 2, v[now].l, v[now].r, 1);
            now++;
        }
        if (t[1]){
            ans = min(ans, (v[now - 1].w - v[i].w));
        }
    }
    cout << ans << endl;
    return 0;
}