#include<bits/stdc++.h>

using namespace std;

#define ld long double
#define pb push_back
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 2e6 + 10;
vector<bool> prime(N, 1);

struct st{
    vector<int> t;
    void build(int n){
        t.resize(4 * n, -1);
    }
    void update(int v, int l, int r, int pos, int val){
        if (l == r){
            t[v] = val;
            return;
        }
        int m = (l + r) / 2;
        if (pos <= m) update(2 * v, l, m, pos, val);
        else update(2 * v + 1, m + 1, r, pos, val);
        t[v] = max(t[v * 2], t[v * 2 + 1]);
    }
    int get(int v, int tl, int tr, int l, int r){
        if (l > r) return -1;
        if (tl == l && tr == r){
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return max(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
    }
};

int solve(vector<int> a){
    map<int,int> mx;
    for (auto to : a) mx[to] = -1;
    int l = -1, val = a.size(), ans = 0, last = -1;
    st t;
    t.build(a.size());
    for (int j = 0; j < a.size(); j++){
        int v = a[j], l = -1;
        if (v != 1){
            if (!prime[v]){
                l = max(l, j);
            }
            else{
                l = last;
                last = j;
            }
        }
        t.update(1, 0, val - 1, j, l);
    }
    int cnt = 0;
    for (auto to : a){
        if (to == 1){
            ans -= cnt;
            cnt++;
        }
        else cnt = 0;
    }
    int r = 0;
    for (int j = 0; j < a.size(); j++){
        r = max(r, j);
        while(r + 1 < a.size() && t.get(1, 0, val - 1, j, r + 1) < j){
            r++;
        }
        ans += r - j;
    }
    return ans;
}

int solvee(vector<int> a){
    int ans = 0;
    for (int i = 0; i < a.size(); i++){
        int now = 1;
        for (int j = i; j < a.size(); j++){
            now *= a[j];
            if (prime[now] && j > i) ans++;
        }
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
    prime[1] = 0;
    for (int i = 2; i < N; i++){
        if (prime[i]){
            for (int j = i + i; j < N; j += i){
                prime[j] = 0;
            }
        }
    }
    int t;
    cin >> t;
    while(t--){
        int n, e;
        cin >> n >> e;
        vector<int> a(n);
        vector<vector<int>> arr(e);
        for (int i = 0; i < n; i++){
            cin >> a[i];
            arr[i % e].pb(a[i]);
        }
        int ans = 0;
        for (int i = 0; i < arr.size(); i++){
            ans += solve(arr[i]);
        }
        cout << ans << endl;
    }
    return 0;
}