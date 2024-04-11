#include <bits/stdc++.h>
using namespace std;

#define pb push_back

const int N = 4000;
int t[4 * N], add[4 * N];

void push(int v){
    add[v * 2] += add[v];
    add[v * 2 + 1] += add[v];
    t[v] += add[v];
    add[v] = 0;
}

void update(int v,  int tl, int tr, int l, int r, int val){
    push(v);
    if (l > r) return;
    if (tl == l && tr == r){
        add[v] += val;
        push(v);
        return;
    }
    push(v);
    int tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, min(r, tm), val), update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
}

int get(int v, int l, int r, int pos){
    push(v);
    if (l == r){
        return t[v];
    }
    push(v);
    int m = (l + r) / 2;
    if (pos <= m){
        return get(2 * v, l, m, pos);
    }
    else{
        return get(2 * v + 1, m + 1, r, pos);
    }
}

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int>> v;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        a--, b--;
        v.pb({a, b});
    }
    int mx = 0;
    for (int i = 0; i < n; i++){
        vector<int> col(N);
        for (int i = 0; i < 4 * N; i++){
            t[i] = add[i] = 0;
        }
        int ans = 0;
        for (int q = 0; q < m; q++){
            pair<int,int> f = {i, i + k - 1};
            ans += max(0,  min(v[q].second, f.second) - max(v[q].first, f.first) + 1);
        }
        for (int q = 0; q < m; q++){
            int add = 0;
            int last = 0;
            pair<int,int> f = {i, i + k - 1};
            if (v[q].first >= i && v[q].second > i + k - 1){
                if (max(0, (min(v[q].second, f.second) - max(v[q].first, f.first)) + 1) > 0){
                    if (abs(v[q].second - v[q].first) + 1 > k){
                        int pl = v[q].first - i;
                        if (pl == 0) continue;
                        update(1, 0, N - 1, i + 1, v[q].first, 1);
                        update(1, 0, N - 1, v[q].second - k + 2, v[q].second - k + pl + 1, -1);
                    }
                    else{
                        int pl = v[q].second - f.second;
                        if (pl == 0) continue;
                        update(1, 0, N - 1, i + 1, i + pl, 1);
                        update(1, 0, N - 1, v[q].first + 1, v[q].first + pl, -1);
                    }
                }
                else{
                    if (abs(v[q].second - v[q].first) + 1 > k){
                        update(1, 0, N - 1, v[q].first - k + 1, v[q].first, 1);
                        update(1, 0, N - 1, v[q].second - k + 2, v[q].second + 1, -1);
                    }
                    else{
                        update(1, 0, N - 1, v[q].first - k + 1, v[q].second - k + 1, 1);
                        update(1, 0, N - 1, v[q].first + 1, v[q].second + 1, -1);
                    }
                }
            }
        }
        mx = max(mx, ans);
        int now = 0;
        for (int j = i + 1; j < n; j++){
            now += get(1, 0, N - 1, j);
            mx = max(mx, now + ans);
        }
    }
    cout << mx << endl;
    return 0;
}