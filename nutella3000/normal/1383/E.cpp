#include <bits/stdc++.h>
using namespace std;
 
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
 
#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())
typedef long double ld;
const int inf = 1e15 + 7, mod = 1e9 + 7;
const int max_n = 1e5 + 1;
 
int n;
string s;
vector<pii> a;
 
 
void solve() {
    cin >> s;
    n = s.size();
    int cnt = 1;
    for(int i = 1;i <= n;i++) {
        if (i == n || s[i] != s[i - 1]) {
            a.emplace_back(cnt, s[i - 1] - '0');
            cnt = 0;
        }
        cnt++;
    }
 
    n = a.size();
 
    vector<int> dp(n + 1);
    dp[n] = 1;
 
    dp[n - 1] = a[n - 1].first;
 
    deque<int> id;
    int res = 0;
    
    int id_temp = 0;

    for(int i = n - 1;i >= 0;i--) {
        //cout << res << endl;
        if (a[i].second == 0) {
            if (i == n - 1) id_temp = 1;


            dp[i] = dp[i + 1] * (a[i].first) % mod;
            while(id.size() > id_temp && a[id.front()].first <= a[i].first) {
                int v = id.front();
                res -= a[v].first * (dp[v + 1]);
                res %= mod;

                id.pop_front();
                if (id.size() > id_temp) {
                    //cout << id.front() << endl;
                    res += (a[v].first) * (dp[id.front() + 1]); 
                    res %= mod;
                }
            }
        
            if (id.size() > id_temp) {
                //cout << id.front() << endl;
                res -= (a[i].first) * dp[id.front() + 1];
            }
            res += a[i].first * dp[i + 1];
            id.emplace_front(i);
            res %= mod;
        }else {
 
            dp[i] = ((res + 1) * a[i].first) % mod;
            if (i + 2 < n) dp[i] = (dp[i] + dp[i + 2]) % mod;
        }
    
        //cout << id.size() << " " << id.back() << " " << res << endl;
        /*cout << i << ":" << endl;
        for(int j : id) cout << j << " ";
        cout << endl;*/
    }
 
    //for(int i = 0;i < n;i++) cout << dp[i] << " ";
    if (n == 1) {
        cout << (dp[0] % mod + mod) % mod << endl;
        return;
    }
    int q = dp[0];
    //cout << n << " " << a[1].second << " " << q << " " << dp[1] << endl;
    if (a[1].second == 1) {
        q += dp[1];
    }
    //cout << q << endl;
    cout << (q % mod + mod) % mod << endl;
}
 
 
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
 
    solve();
}