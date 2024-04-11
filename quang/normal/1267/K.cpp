#include <bits/stdc++.h>

using namespace std;

int const NN = 30;

int cnt[NN];
long long fact[NN];


vector < int > get_multiset(long long k) {
    vector < int > res;
    int cur = 2;
    while (k > 0) {
        res.push_back(k % cur);
        k /= cur;
        cur++;
    }
    return res;
}

long long get_c(int x, int y) {
    if (x > y || x < 0) {
        return 0;
    }
    return fact[y] / fact[x] / fact[y - x];
}

long long get_ans(int n) {
    int sum = 0;
    long long ans = 1;
    for (int i = NN - 1; i >= 0; i--) {
        if (cnt[i] == 0) {
            continue;
        }
        ans = ans * get_c(cnt[i], min(n, n - i + 1) - sum);
        sum += cnt[i];
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    fact[0] = 1;
    for (int i = 1; i < NN; i++) {
        fact[i] = fact[i - 1] * i;
    }
    int t;
    cin >> t;
    while (t--) {
        memset(cnt, 0, sizeof(cnt));
        long long k;
        cin >> k;
        vector < int > a = get_multiset(k);
        int n = a.size();
        for (int x : a) {
            cnt[x]++;
        }
        long long ans = get_ans(n);
        if (cnt[0]) {
            cnt[0]--;
            ans -= get_ans(n - 1);
        }
        ans -= 1;
        cout << ans << endl;
    }
    return 0;
}