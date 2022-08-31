#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define ar array
#define all(a) (a).begin(), (a).end()
typedef long long ll;
typedef long double ld;
using namespace std;

const ll INF = 1e18 + 5;
const int INFi = 1e9;
const int maxN = 1e5 + 5;
const int md2 = 998244353;
const int md = 1e9 + 7;


int add(int a, int b) {
    if (a + b >= md) return a + b - md;
    return a + b;
}

int sub(int a, int b) {
    if (a - b < 0) return a - b + md;
    return a - b;
}

int mul(int a, int b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}

void solve() {
    int n; cin >> n;
    vector<int> p(n);
    range(i, n) {
        cin >> p[i];
        p[i]--;
    }
    vector<int> a;
    vector<int> was(n);
    int ans = 0;
    range(i ,n) {
        if (was[i]) continue;
        int cnt = 0;
        int j = i;
        while(!was[j]) {
            was[j] = true;
            j = p[j];
            cnt++;
        }
        if (cnt == 1) {
            a.push_back(1);
            continue;
        }
        if (cnt % 3 == 0) {
            ans += cnt / 3 - 1;
        } else if (cnt % 3 == 1) {
            ans += cnt / 3 - 1;
            a.push_back(4);
        } else {
            ans += cnt / 3;
            a.push_back(2);
        }
    }
    if (n % 3 == 0) {
        cout << binpow(3, n / 3) << ' ';
    } else if (n % 3 == 1) {
        cout << mul(binpow(3, n / 3 - 1), 4) << ' ';
    } else {
        cout << mul(binpow(3, n / 3), 2) << ' ';
    }
    int need = n % 3;
    if (need == 0) {
        int cnt1 = 0, cnt2 = 0;
        for(auto &x : a) {
            if (x == 4) {
                cnt1++;
                ans++;
            } else if (x == 1) {
                cnt1++;
            } else {
                cnt2++;
            }
        }
        ans += min(cnt1, cnt2);
        int x = min(cnt1, cnt2);
        cnt1 -= x;
        cnt2 -= x;
        if (cnt1 != 0) {
            ans += (cnt1 / 3) * 2;
        } else if (cnt2 != 0) {
            ans += cnt2;
        }
        cout << ans << '\n';
        return;
    }
    ar<int, 5> cnt = {0, 0, 0, 0, 0};
    for(auto &x : a) cnt[x]++;
    while(cnt[1] > 5 && cnt[2] > 5) {
        ans++;
        cnt[1]--;
        cnt[2]--;
    }
    while(cnt[2] > 3 && cnt[4] > 3) {
        ans += 2;
        cnt[2]--;
        cnt[4]--;
    }
    function<int(ar<int, 5>)> sol = [&] (ar<int, 5> cnt) {
        int ost = 0;
        range(i, 5) ost += cnt[i] * i;
        if (ost == 0) return 0;
        if (ost == 1) return 1;
        if (ost == 2) {
            return cnt[1] + cnt[2] - 1;
        }
        if (ost == 4) {
            if (cnt[4] == 1) return 0;
            return cnt[1] / 2;
        }
        int res = INFi;
        if (cnt[1] >= 3) {
            cnt[1] -= 3;
            res = min(res, sol(cnt) + 2);
            cnt[1] += 3;
        }
        if (cnt[1] && cnt[2]) {
            cnt[1]--;
            cnt[2]--;
            res = min(res, sol(cnt) + 1);
            cnt[1]++;
            cnt[2]++;
        }
        if (cnt[2] >= 3) {
            cnt[2] -= 3;
            res = min(res, sol(cnt) + 3);
            cnt[2] += 3;
        }
        if (cnt[4] && cnt[2]) {
            cnt[2]--;
            cnt[4]--;
            res = min(res, sol(cnt) + 2);
            cnt[2]++;
            cnt[4]++;
        }
        if (cnt[4]) {
            cnt[4]--;
            cnt[1]++;
            res = min(res, sol(cnt) + 1);
            cnt[4]++;
            cnt[1]--;
        }
        return res;
    };
    ans += sol(cnt);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}