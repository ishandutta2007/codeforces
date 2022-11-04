#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;

const ll INF = (int) 1e9;
const ll LINF = (ll) 1e18;
const ld EPS = 1e-9;

#define TASK ""

const int N = 1002;
const int K = 1e4 + 200;
const int L = 100;

int n;
ll k;
ll a[N];

pair<int, ll> dp[N][K];
bool from[N][K];
int gcd[N][K];
int precalc[N][K];

int div_cnt;
ll divider[K];
int pr_div[K];
int pr_id[K];

int prime_cnt;
ll prime[L];

int pwr[K][L];
int max_p[N][L];
int nxt_p[K][L];

int run() {
    for (int i = 0; i < N; i++) {
        fill(dp[i], dp[i] + K, make_pair(INF, LINF));
    }
    fill(pr_div, pr_div + K, -1);
    
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    if (k == 1) {
        cout << "1\n";
        cout << (min_element(a, a + n) - a) + 1 << "\n";
        return 0;
    }
        
    {
        for (ll d = 1; d * d <= k; d++) {
            ll subd = k / d;
            
            if (d * subd != k) {
                continue;
            }
            
            if (d == subd) {
                divider[div_cnt++] = d;
            } else {
                divider[div_cnt++] = d;
                divider[div_cnt++] = subd;
            }
            
            assert(div_cnt + 2 < K);
        }
        
        sort(divider, divider + div_cnt);
    }
    
    {
        ll x = k;
        for (ll d = 2; d * d <= x; d++) {
            while (x % d == 0) {
                prime[prime_cnt++] = d;
                x /= d;
            }
        }
        
        if (x != 1) {
            prime[prime_cnt++] = x;
        }
        
        sort(prime, prime + prime_cnt);
    }
    
    for (int i = 0; i < div_cnt; i++) {
        for (int j = 0; j < prime_cnt; j++) {
            ll cur = 1;
            while (divider[i] % (cur * prime[j]) == 0) {
                cur *= prime[j];
                pwr[i][j]++;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < prime_cnt; j++) {
            ll cur = 1;
            while (a[i] % (cur * prime[j]) == 0) {
                cur *= prime[j];
                max_p[i][j]++;
            }
        }
    }
    
    for (int i = 0; i < div_cnt; i++) {
        for (int j = 0; j < prime_cnt; j++) {
            if (divider[i] % prime[j] == 0) {
                pr_div[i] = j;
                pr_id[i] = (int) (lower_bound(divider, divider + div_cnt, divider[i] / prime[j]) - divider);
                break;
            }
        }
    }
    
    for (int i = 0; i < div_cnt; i++) {
        for (int j = 0; j < prime_cnt; j++) {
            ll cur = divider[i] * prime[j];
            nxt_p[i][j] = (int) (lower_bound(divider, divider + div_cnt, cur) - divider);
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < div_cnt; j++) {
            if (pr_div[j] == -1) {
                gcd[i][j] = 0;
            } else {
                int pr = pr_div[j];
                int prv = pr_id[j];
                
                if (max_p[i][pr] > pwr[prv][pr]) {
                    gcd[i][j] = nxt_p[gcd[i][prv]][pr];
                } else {
                    gcd[i][j] = gcd[i][prv];
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < div_cnt; j++) {
            ll p = divider[j] / divider[gcd[i][j]];
            int t = (int) (lower_bound(divider, divider + div_cnt, p) - divider);
            precalc[i][j] = t;
        }
    }
    
    dp[0][0] = {1, 0LL};
    
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < div_cnt; j++) {
            dp[i][j] = dp[i - 1][j];
            
            int t = precalc[i - 1][j];
            pair<int, ll> val = dp[i - 1][t];
            val.first++;
            val.second += a[i - 1];
            if (val < dp[i][j]) {
                dp[i][j] = val;
                from[i][j] = true;
            }
        }
    }
        
    if (dp[n][div_cnt - 1].first == INF) {
        cout << "-1\n";
        return 0;
    }
    
    vector<int> ans;
    int cur_i = n;
    int cur_j = div_cnt - 1;
    
    while (cur_i != 0) {
        if (from[cur_i][cur_j]) {
            ans.push_back(cur_i - 1);
            cur_j = precalc[cur_i - 1][cur_j];
        }
        cur_i--;
    }
    
    cout << ans.size() << "\n";
    for (int el : ans) {
        cout << el + 1 << " ";
    }
    cout << "\n";
    
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
#ifndef DEBUG
    if (strlen(TASK) > 0) {
        freopen(TASK ".in", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
#endif

    return run();
}