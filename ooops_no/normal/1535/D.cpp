#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 3e5 + 10;
int t[4 * N], col[4 * N], add[4 * N];

void push(int v){
    t[v] += add[v];
    if (v * 2 < 4 * N) add[v * 2] += add[v];
    if (v * 2 + 1 < 4 * N) add[v * 2 + 1] += add[v];
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
    t[v] = max(t[v * 2], t[v * 2 + 1]);
    col[v] = 0;
    if (t[v] == t[v * 2]) col[v] += col[v * 2];
    if (t[v] == t[v * 2 + 1]) col[v] += col[v * 2 + 1];
}

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    int k;
    cin >> k;
    vector<int> po(20);
    for (int i = 0; i < 4 * N; i++) col[i] = 1;
    po[0] = 1;
    for (int i = 1; i < 20; i++) po[i] = po[i - 1] * 2;
    int n = po[k];
    string s;
    cin >> s;
    vector<pair<pair<int,int>, pair<int,int>>> a(s.size());
    int now = 0;
    for (int i = 0; i < k; i++){
        for (int j = 0; j + po[i] * 2 <= n; j += po[i] * 2){
            a[now++] = {{j, j + po[i] - 1}, {j + po[i], j + po[i] * 2 - 1}};
        }
    }
    for (int i = 0; i < s.size(); i++){
        if (s[i] == '0'){
            update(1, 0, N - 1, a[i].first.first, a[i].first.second, 1);
        }
        else if (s[i] == '1'){
            update(1, 0, N - 1, a[i].second.first, a[i].second.second, 1);
        }
        else{
            update(1, 0, N - 1, a[i].first.first, a[i].first.second, 1);
            update(1, 0, N - 1, a[i].second.first, a[i].second.second, 1);
        }
    }
    int q;
    cin >> q;
    while(q--){
        int i;
        char c;
        cin >> i >> c;
        i--;
        if (s[i] == '0'){
            update(1, 0, N - 1, a[i].first.first, a[i].first.second, -1);
        }
        else if (s[i] == '1'){
            update(1, 0, N - 1, a[i].second.first, a[i].second.second, -1);
        }
        else{
            update(1, 0, N - 1, a[i].first.first, a[i].first.second, -1);
            update(1, 0, N - 1, a[i].second.first, a[i].second.second, -1);
        }
        s[i] = c;
        if (s[i] == '0'){
            update(1, 0, N - 1, a[i].first.first, a[i].first.second, 1);
        }
        else if (s[i] == '1'){
            update(1, 0, N - 1, a[i].second.first, a[i].second.second, 1);
        }
        else{
            update(1, 0, N - 1, a[i].first.first, a[i].first.second, 1);
            update(1, 0, N - 1, a[i].second.first, a[i].second.second, 1);
        }
        cout << col[1] << "\n";
    }
    return 0;
}