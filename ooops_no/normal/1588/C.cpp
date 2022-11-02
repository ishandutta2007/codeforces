#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

#define ld long double
#define ll long long
#define pb push_back
#define int long long

mt19937 rnd(51);

const int INF = 1e9;

using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

struct st{
    vector<int> t, add;
    void build(int n){
        t.resize(4 * n);
        add.resize(4 * n);
    }
    void push(int v){
        t[v] += add[v];
        if (v * 2 < add.size()){
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
    int find_first(int v, int l, int r){
        push(v);
        if (l == r){
            return l;
        }
        push(v * 2), push(v * 2 + 1);
        int m = (l + r) / 2;
        if (t[v * 2] < 0){
            return find_first(2 * v, l, m);
        }
        else{
            return find_first(2 * v + 1, m + 1, r);
        }
    }
    int get(int v, int tl, int tr, int l, int r){
        push(v);
        if (l > r) return INF;
        if (tl == l && tr == r){
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return min(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }
};

int solve(int n, vector<int> a){
    vector<vector<int>> pr(n, vector<int>(2));
    vector<int> val(n);
    map<int, ordered_set> mp;
    for (int i = 0; i < n; i++){
        if (i > 0){
            pr[i][0] = pr[i - 1][0];
            pr[i][1] = pr[i - 1][1];
        }
        pr[i][i & 1] += a[i];
        mp[pr[i][0] - pr[i][1]].insert(i);
    }
    st even, odd;
        even.build(n);
        odd.build(n);
        for (int i = 0; i < n; i++){
            if (i % 2 == 0){
                even.update(1, 0, n - 1, i / 2, (n - 1) / 2, a[i]);
                odd.update(1, 0, n - 1, i / 2, (n - 2) / 2, -a[i]);
            }
            else{
                even.update(1, 0, n - 1, (i + 1) / 2, (n - 1) / 2, -a[i]);
                odd.update(1, 0, n - 1, i / 2, (n - 2) / 2, a[i]);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++){
            vector<int> col(2);
            int last = 0, pr0 = (i > 0 ? pr[i - 1][0] : 0), pr1 = (i > 0 ? pr[i - 1][1] : 0);
            int ind = n - 1;
            if (even.get(1, 0, n - 1, 0, n - 1) < 0){
                ind = min(ind, even.find_first(1, 0, n - 1) * 2);
            }
            if (odd.get(1, 0, n - 1, 0, n - 1) < 0){
                ind = min(ind, odd.find_first(1, 0, n - 1) * 2 + 1);
            }
            ans += mp[pr0 - pr1].order_of_key(ind + 1);
            if (i % 2 == 0){
                even.update(1, 0, n - 1, i / 2, (n - 1) / 2, -a[i]);
                odd.update(1, 0, n - 1, i / 2, (n - 2) / 2, a[i]);
            }
            else{
                even.update(1, 0, n - 1, (i + 1) / 2, (n - 1) / 2, a[i]);
                odd.update(1, 0, n - 1, i / 2, (n - 2) / 2, -a[i]);
            }
            mp[pr[i][0] - pr[i][1]].erase(i);
        }
    return ans;
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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        cout << solve(n, a) << endl;
    }
    return 0;
}