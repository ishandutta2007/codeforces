#include<bits/stdc++.h>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 1e6 + 10;

struct node{
    int cnt, l_el, r_el;
} t[4 * N];

node Merge(node a, node b){
    if (a.cnt <= 0) return b;
    if (b.cnt <= 0) return a;
    if (a.r_el != b.l_el){
        return {a.cnt + b.cnt, a.l_el, b.r_el};
    }
    else{
        if (a.cnt == b.cnt){
            return {0, -1, -1};
        }
        else if (a.cnt < b.cnt){
            return {b.cnt - a.cnt, ((b.cnt - a.cnt) % 2 == 0 ? (b.r_el ^ 1) : b.r_el), b.r_el};
        }
        else{
            return {a.cnt - b.cnt, a.l_el, ((a.cnt - b.cnt) % 2 == 0 ? (a.l_el ^ 1) : a.l_el)};
        }
    }
}

void update(int v, int l, int r, int pos, int val){
    if (l == r){
        t[v] = {1, val, val};
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m) update(2 * v, l, m, pos, val);
    else update(2 * v + 1, m + 1, r, pos, val);
    t[v] = Merge(t[v * 2], t[v * 2 + 1]);
}

node get(int v, int tl, int tr, int l, int r){
    if (l > r) return {-1, 0, 0};
    if (tl == l && tr == r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return Merge(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        for (int i = 0; i < s.size(); i++){
            if (s[i] == '(' || s[i] == ')') {
                update(1, 0, n - 1, i, 0);
            }
            else{
                update(1, 0, n - 1, i, 1);
            }
        }
        int q;
        cin >> q;
        while(q--){
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << get(1, 0, n - 1, l, r).cnt / 2 << endl;
        }
    }
    return 0;
}