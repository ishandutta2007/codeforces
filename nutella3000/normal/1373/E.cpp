#include <bits/stdc++.h>
using namespace std;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

#define int long long
#define pii pair<int, int>
#define sz(a) ((int)a.size())  
typedef long double ld;
const int inf = 9e18 + 7;
const int mod = 998244353;
int n, k;
int ans;

void make_res(int sum, int cnt, int num) {
    if (cnt + (sum - 8 + 8) / 9 >= 18) return;
    //cout << sum << " " << cnt << " " << num << " ";
    int res = 0;
    if (sum < 8) res = sum * 10;
    else {  
        res = (sum % 9 + 1) % 9 * 10;
        sum -= (sum % 9 + 1) % 9;
        while(sum > 8) {
            res = (res + 9) * 10;
            sum -= 9;
        }
        //cout << res << " ";
        res = (res + 8) * 10;
        //cout << res << " ";
    }

    //cout << res << " ";
    while(cnt > 0) {
        res = (res + 9) * 10;
        cnt--;
    }

    res += num;
    //cout << res << endl;
    ans = min(ans, res);
}

void solve() {
    ans = inf;
    cin >> n >> k;
    for(int cnt = 0;cnt <= 16;cnt++) {
        for(int num = 0;num <= 9;num++) {
            int sum = 0;
            for(int i = num;i <= num + k;i++) {
                if (i >= 10) sum += 1 + i - 10;
                else sum += i + 9 * cnt;
            }
            if (sum > n || (n - sum) % (k + 1) != 0) continue;
            make_res((n - sum) / (k + 1), cnt, num);
        }
    }

    if (ans == inf) cout << -1 << endl;
    else cout << ans << endl;
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif 
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) solve();
}