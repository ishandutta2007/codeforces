#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
typedef long long ll;
const int md = 998244353;
const int OO = 0;
using namespace std;

const int mxn = 50000;

ll pw(ll b, ll e){
    ll res = 1;
    while (e){
        if (e & 1) res = res * b % md;
        e /= 2, b = b * b % md;
    }
    return res;
}
ll inv(ll x){
    return pw(x, md - 2);
}

ll fact[mxn], ifact[mxn];

int n;
vector<int> a;

ll dp[5005], dp2[5005];

int brute(){
    auto b = a;
    sort(b.begin(), b.end());
    int ans = 0;
    do{
        bool good = true;
        for (int i = 3; i < n; i += 2)
            if (b[i - 2] >= b[i])
                good = false;
        for (int i = 1; i < n; i++){
            if (i & 1){
                if (b[i - 1] >= b[i])
                    good = false;
            }
            else{
                if (b[i - 1] <= b[i])
                    good = false;
            }
        }
        if (good) ans++;
    } while (next_permutation(b.begin(), b.end()));
    return ans;
}

void prep(){
    fact[0] = 1;
    for (int i = 1; i < mxn; i++)
        fact[i] = i * fact[i - 1] % md;
    ifact[0] = 1;
    for (int i = 1; i < mxn; i++)
        ifact[i] = inv(i) * ifact[i - 1] % md;
}

ll choose(int n, int k){
    if (n < 0 || n < k) return 0LL;
    return fact[n] * ifact[k] % md * ifact[n - k] % md;
}

void work(int i, int c){
    if (OO){
        cout << "starting " << i << " " << c << endl;
    }
    for (int i = 0; i < n; i++) dp2[i] = 0;
    for (int j = 0; j <= n / 2; j++){
        int tmpc = j == n / 2 ? c - 1 : c;
        for (int k = c - 1; k <= tmpc; k++){
            if (j - c + k > 0) {
                dp2[j] += choose(2 * j - i + 2 * k - c - 1, k) * dp[j - c + k];
                dp2[j] %= md;
            }
        }
        if (j == n / 2){
            dp2[j] += choose(n - i + c, c) * dp[n / 2];
            dp2[j] %= md;
        }
    }
    for (int i = 0; i < n; i++)
        dp[i] = dp2[i];
}

void solve(){
    cin >> n;
    a.resize(n);
    for (auto &i : a) cin >> i;
    sort(a.rbegin(), a.rend());
    int cur = 1, nxt;

    if (a[0] == a[1]){
        cout << "0" << endl;
        return;
    }

    for (int i = 1; i < n; i++){
        if (a[i - 1] != a[i]){
            for (int j = 0; j < n; j++)
                dp[j] = 0;
            dp[cur] = 1;
            nxt = i;
            cur = 1;
            break;
        }
        cur++;
    }
    for (int i = nxt + 1; i <= n; i++){
        if (i != n && a[i - 1] == a[i]){
            cur++;
            continue;
        }
        work(i, cur);
        if (OO){
            for (int j = 1; j <= n / 2; j++)
                cout << dp[j] << " ";
            cout << endl;
        }
        cur = 1;
    }
    cout << dp[n / 2] << endl;
    //cout << "brute: " << brute() << endl;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    prep();
    int t;
    cin >> t;
    while (t--) solve();
}