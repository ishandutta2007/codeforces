#include<iostream>
#include<algorithm>
#include<vector>
#include<random>
#include<map>
#include<set>
#include<deque>
#include<assert.h>
#include<bitset>
#include<unordered_map>

using namespace std;

#define pb push_back
#define ld long double
#define ll long long
#define int long long

mt19937 rnd(51);

const int N = 8e5 + 10, INF = 1e18;
int t[4 * N];

void update(int v, int l, int r, int pos, int val){
    if (l == r){
        t[v] = min(t[v], val);
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m){
        update(2 * v, l, m, pos, val);
    }
    else{
        update(2 * v + 1, m + 1, r, pos, val);
    }
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}

int get(int v, int tl, int tr, int l, int r){
    if (l > r) return INF;
    if (tl == l && tr == r){
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return min(get(2 * v, tl, tm, l, min(r, tm)), get(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}

bool x = 0;

bool cmp(pair<int,int> a, pair<int,int> b){
    return a.first - a.second < b.first - b.second;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> u{INF, -INF};
    vector<int> a(n);
    vector<pair<int,int>> q(m);
    for (int i = 0; i < n; i++){
        cin >> a[i];
        u.pb(a[i]);
    }
    a.pb(-INF);
    a.pb(INF);
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++){
        cin >> q[i].first >> q[i].second;
        u.pb(q[i].first);
        u.pb(q[i].second);
    }
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    vector<int> dp(u.size(), INF);
    dp[0] = 0;
    int k = u.size();
    for (int i = 0; i < k * 4; i++){
        t[i] = INF;
    }
    for (int i = 0; i < a.size(); i++){
        a[i] = lower_bound(u.begin(), u.end(), a[i]) - u.begin();
    }
    for (int i = 0; i < m; i++){
        q[i].first = lower_bound(u.begin(), u.end(), q[i].first) - u.begin();
        q[i].second = lower_bound(u.begin(), u.end(), q[i].second) - u.begin();
        update(1, 0, k - 1, q[i].first, q[i].second);
    }
    int ans = INF;
    for (int i = 0; i + 1 < a.size(); i++){
        int j = a[i] + 1;
        vector<int> b;
        for (int j = (i > 0 ? a[i - 1] + 1 : 0); j <= a[i]; j++){
            b.pb(j);
        }
        vector<pair<int,int>> lol;
        multiset<int> st, stt;
        for (auto to : b){
            int val = min(a[i + 1], get(1, 0, k - 1, a[i] + 1, a[i + 1]));
            lol.pb({abs(u[a[i]] - u[to]) + dp[to], dp[to]});
            st.insert(lol.back().first);
            dp[val] = min(dp[val], dp[to] + abs(u[a[i]] - u[to]));
        }
        sort(lol.begin(), lol.end(), cmp);
        int ind = 0;
        for (int j = a[i]; j <= a[i + 1]; j++){
            while(ind < lol.size() && abs(u[j] - u[a[i]]) > lol[ind].first - lol[ind].second){
                st.erase(st.find(lol[ind].first));
                stt.insert((lol[ind].first - lol[ind].second) * 2 + lol[ind].second);
                ind++;
            }
            int val = min(a[i + 1], get(1, 0, k - 1, j + 1, a[i + 1]));
            int bst = min((st.size() > 0 ? *st.begin() + abs(u[j] - u[a[i]]) : INF), (stt.size() > 0 ? *stt.begin() : INF)) + abs(u[j] - u[a[i]]);
            dp[val] = min(dp[val], bst);
            if (i + 2 == a.size()){
                ans = min(ans, dp[val] + abs(u[a[i + 1]] - u[val]));
            }
        }
    }
    cout << ans << endl;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}