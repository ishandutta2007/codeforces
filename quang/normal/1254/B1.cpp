#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
#define int long long
const long long INF = 1e18;

int n;
int a[N];
int b[N];

long long eval(vector<pair<int, int>> &u, long long k) {
    long long curSum = 0;
    int pos = 0;
    for (int i = 0; i < u.size(); i++) {
        curSum += u[i].first;
        if (curSum * 2 > k) {
            pos = u[i].second;
            break;
        }
    }
    long long res = 0;
    for (int i = 0; i < u.size(); i++) {
        res += 1ll * u[i].first * abs(u[i].second - pos);
    }
    return res;
}

long long solve(long long k) {
    for (int i = 1; i <= n; i++) a[i] = b[i];
    long long curSum = 0;
    vector<pair<int, int>> cur;
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        if (!a[i]) continue;
        if (curSum == 0) a[i] %= k;

        long long now = min(k - curSum, 1ll * a[i]);
        a[i] -= now;
        cur.push_back({now, i});
        curSum += now;
        if (curSum == k) {
            res += eval(cur, k);
            i--;
            curSum = 0;
            cur.clear();
            continue;
        }
    }
    return res;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
        sum += a[i];
    }
    if (sum == 1) {
        cout << -1 << endl;
        return 0;
    }

    long long res = INF;

    for (int i = 2; 1ll * i * i <= sum; i++) {
        if (sum % i == 0) {
            while (sum % i == 0) sum /= i;
            res = min(res, solve(i));
        }
    }

    if (sum > 1) {
        res = min(res, solve(sum));
    }

    cout << res << endl;
    return 0;
}