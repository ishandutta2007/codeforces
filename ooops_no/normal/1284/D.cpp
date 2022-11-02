#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define int long long

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 3e5 + 10;
int q[N], t[N];

void inc(int i, int d){
    for (; i < N; i = (i | (i + 1))){
        t[i] += d;
    }
}

int res(int i){
    int ans = 0;
    for (; i >= 0; i = (i & (i + 1)) - 1){
        ans += t[i];
    }
    return ans;
}

vector<int> func(vector<pair<int,int>> a){
    for (int i = 0; i < N; i++) t[i] = 0;
    vector<int> b;
    for (auto to : a){
        b.pb(to.first);
        b.pb(to.second);
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    int n = a.size();
    vector<int> ans(n);
    vector<pair<int, pair<int, pair<int, int>>>> u;
    int now = 0;
    for (auto to : a){
        int i = lower_bound(b.begin(), b.end(), to.first) - b.begin(), j = lower_bound(b.begin(), b.end(), to.second) - b.begin();
        u.pb({i, {0, {now, j}}});
        u.pb({j, {1, {now, i}}});
        now++;
    }
    sort(u.begin(), u.end());
    for (int i = 0; i < u.size(); i++){
        if (u[i].second.first == 0){
            inc(u[i].second.second.second, q[u[i].second.second.first]);
        }
        else{
            ans[u[i].second.second.first] = res(N - 1) - res(u[i].second.second.second - 1);
        }
    }
    return ans;
}

signed main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    int mx = 0;
    for (int i = 0; i < n; i++){
        int v = 0;
        while(v < 1e12){
            v *= 10;
            v += rnd() % 10;
        }
        mx = max(mx, v);
        q[i] = v;
    }
    vector<pair<int,int>> u(n), v(n);
    for (int i = 0; i < n; i++){
        cin >> u[i].first >> u[i].second >> v[i].first >> v[i].second;
    }
    vector<int> col = func(u), col1 = func(v);
    for (int i = 0; i < n; i++){
        if (col[i] != col1[i]){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}