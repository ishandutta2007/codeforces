#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
#define pb push_back

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1e6 + 10;
int t[N], dp[N];
vector<int> kek[N], not_kek[N];

int get(int r){
    int ans = 0;
    for (; r >= 0; r = (r & (r + 1)) - 1){
        ans += t[r];
    }
    return ans;
}

void inc(int i, int d){
    for (; i < N; i = (i | (i + 1))){
        t[i] += d;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, d;
    cin >> n >> d;
    vector<int> u;
    vector<pair<int,int>> b;
    for (int i = 0; i < n; i++){
        int s, a;
        cin >> s >> a;
        if (s >= d){
            b.pb({s, max(a, d)});
            u.pb(s);
            u.pb(a);
        }
    }
    sort(u.begin(), u.end());
    u.erase(unique(u.begin(), u.end()), u.end());
    n = b.size();
    int ans = 0;
    for (int i = 0; i < n; i++){
        b[i].first = lower_bound(u.begin(), u.end(), b[i].first) - u.begin();
        b[i].second = lower_bound(u.begin(), u.end(), b[i].second) - u.begin();
        if (b[i].first >= b[i].second){
            ans++;
            kek[b[i].first].pb(b[i].second);
        }
        else{
            not_kek[b[i].second].pb(i);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= u.size(); i++){
        dp[i] = dp[i - 1];
        for (auto to : not_kek[i]){
            dp[i] = max(dp[i], dp[b[to].first] - (cnt - get(b[to].first)) + 1);
        }
        for (auto to : kek[i]){
            inc(to, 1);
            cnt++;
        }
    }
    cout << ans + dp[u.size()] << endl;
    return 0;
}