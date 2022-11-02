#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define ld long double
#define ll __int128


mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 36000;
int a[N], dp[N], dpp[N];
vector<int> last[N];
vector<int> leftt(N), rightt(N);
int ans = 0, L = 0, R = 0;

void add(int a){
    if (leftt[a] <= rightt[a]){
        ans += last[a][rightt[a]] - last[a][leftt[a]];
    }
}

void del(int a){
    if (leftt[a] <= rightt[a]){
        ans -= last[a][rightt[a]] - last[a][leftt[a]];
    }
}

void make_move(int l, int r){
    while(R < r){
        R++;
        del(a[R]);
        rightt[a[R]]++;
        add(a[R]);
    }
    while(l < L){
        L--;
        del(a[L]);
        leftt[a[L]]--;
        add(a[L]);
    }
    while(R > r){
        del(a[R]);
        rightt[a[R]]--;
        add(a[R]);
        R--;
    }
    while(l > L){
        del(a[L]);
        leftt[a[L]]++;
        add(a[L]);
        L++;
    }
}

void solve(int l, int r, int l_, int r_){
    if (l > r) return;
    int m = (l + r) / 2, opt = l_;
    make_move(l_, m);
    int anss = ans;
    if (l_ > 0) anss += dp[l_ - 1];
    for (int i = l_ + 1; i <= min(m, r_); ++i){
        make_move(i, m);
        if (ans + dp[i - 1] < anss){
            anss = ans + dp[i - 1];
            opt = i;
        }
    }
    dpp[m] = anss;
    solve(l, m - 1, l_, opt), solve(m + 1, r, opt, r_);
}

int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
#endif // LOCAL
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        last[a[i]].pb(i);
    }
    for (int i = 0; i < N; i++) dp[i] = 1e9;
    for (int i = 0; i < k; i++){
        L = 0, R = 0;
        for (int j = 0; j < N; j++){
            leftt[j] = 0, rightt[j] = -1;
        }
        leftt[a[0]] = rightt[a[0]] = 0;
        for (int j = 0; j < N; j++) dpp[j] = 1e9;
        solve(0, n - 1, 0, n - 1);
        for (int j = 0; j < N; j++) dp[j] = dpp[j];
    }
    cout << dp[n - 1];
    return 0;
}