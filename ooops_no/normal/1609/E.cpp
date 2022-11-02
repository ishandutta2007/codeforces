#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long
#define int long long

mt19937 rnd(51);

const int INF = 1e18;

struct node{
    int cnt0, cnt1, cnt2;
    int can1, can2, can12;
};

node merge(node a, node b){
    int val = min(a.cnt0, b.can12);
    a.cnt0 -= val, b.can12 -= val, b.cnt2 += val;
    val = min(a.cnt0, b.can1);
    a.cnt0 -= val, b.can1 -= val, b.cnt1 += val;
    val = min(a.cnt1, b.can2);
    a.cnt1 -= val, b.can2 -= val, b.cnt2 += val;
    val = min(a.can1, b.can2);
    a.can1 -= val, b.can2 -= val, a.can12 += val;
    val = min(a.cnt1, b.can12);
    a.cnt2 += val, a.cnt1 -= val, b.can12 -= val, a.can1 += val;
    return {a.cnt0 + b.cnt0, a.cnt1 + b.cnt1, a.cnt2 + b.cnt2, a.can1 + b.can1, a.can2 + b.can2, a.can12 + b.can12};
}

struct st{
    vector<node> t;
    void build(int n){
        t.resize(4 * n, {0, 0, 0, 0, 0, 0});
    }
    void update(int v, int l, int r, int pos, int val){
        if (l == r){
            if (val == 0){
                t[v] = {1, 0, 0, 0, 0, 0};
            }
            else if (val == 1){
                t[v] = {0, 0, 0, 1, 0, 0};
            }
            else{
                t[v] = {0, 0, 0, 0, 1, 0};
            }
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m) update(2 * v, l, m, pos, val);
        else update(2 * v + 1, m + 1, r, pos, val);
        t[v] = merge(t[v * 2], t[v * 2 + 1]);
    }
};

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    st t;
    t.build(s.size());
    for (int i = 0; i < n; i++){
        t.update(1, 0, n - 1, i, s[i] - 'a');
    }
    while(q--){
        int i;
        char c;
        cin >> i >> c;
        i--;
        s[i] = c;
        t.update(1, 0, n - 1, i, s[i] - 'a');
        cout << t.t[1].cnt2 << endl;
    }
    return 0;
}