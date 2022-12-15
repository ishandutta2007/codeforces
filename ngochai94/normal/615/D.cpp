#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define eps 0.00000001
#define sqr(x) (x) * (x)
#define pb push_back

long long n, val, cnt[200005], tot, ans;

long long expo(long long a, long long b) {
    long long res = 1;
    FORD (i, 30, 0) {
        res *= res;
        res %= mod;
        if ((1ll << i) & b) {
            res *= a;
            res %= mod;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin >> n;
    while (n--) {
        cin >> val;
        cnt[val]++;
    }
    ans = 1;
    tot = 1;
    bool flag = false;
    REP (i, 200005) {
        if (cnt[i] % 2 == 1 && !flag) {
            flag = true;
            tot *= (cnt[i] + 1) / 2;
            tot %= mod - 1;
            continue;
        }
        tot *= cnt[i] + 1;
        tot %= mod - 1;
    }
    FOR (i, 2, 200000) if (cnt[i]) {
        long long tmp = tot;
        if (flag) tmp *= cnt[i];
        else tmp *= cnt[i] / 2;
        tmp %= mod - 1;
        ans *= expo(i, tmp);
        ans %= mod;
    }
    cout << ans;
}