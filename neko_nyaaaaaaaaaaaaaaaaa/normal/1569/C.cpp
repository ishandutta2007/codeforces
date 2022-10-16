#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second

using namespace std;

const int MOD = 998244353;

int gt[200001];

int fpow(int a, int n) {
    int tmp = 1;
    while (n) {
        if (n & 1) {
            tmp = (tmp * a) % MOD;
        }
        a = (a * a) % MOD;
        n >>= 1;
    }
    return tmp;
}

int C(int k, int n) {
    int tmp = gt[n];
    tmp = (tmp * fpow(gt[k], MOD-2)) % MOD;
    tmp = (tmp * fpow(gt[n-k], MOD-2)) % MOD;
    return tmp;
}

signed main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    //freopen("t.inp", "r", stdin);
    int t;
    cin >> t;
    gt[0] = 1;
    for (int i = 1 ; i <= 200000 ; i++) {
        gt[i] = (i * gt[i-1]) % MOD;
    }
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        map<int, int> cnt;
        for (int i = 0 ; i < n ; i++) {
            int x;
            cin >> x;
            cnt[x]++;
            if (cnt[x] == 1) {
                a.push_back(x);
            }
        }
        sort(a.begin(), a.end(), greater<int>());
        if (cnt[a[0]] > 1) {
            cout << gt[n] << "\n";
            continue;
        }
        if (a[0] - a[1] >= 2) {
            cout << 0 << "\n";
            continue;
        }
        int res = 1;
        int slots = cnt[a[0]] + cnt[a[1]] + 1;
        int num = n-cnt[a[0]] - cnt[a[1]];
        res = (res * gt[cnt[a[1]]]) % MOD;
        //cout << res << " 1\n";
        res = (res * gt[cnt[a[0]]]) % MOD;
        //cout << res << " 2\n";
        res = (res * C(slots-1, num+slots-1)) % MOD;
        res = (res * gt[num]) % MOD;
        //cout << slots << " " << num << " " << " 3\n";
        res = (gt[n] - res + MOD) % MOD;
        cout << res << "\n";
    }
    return 0;
}