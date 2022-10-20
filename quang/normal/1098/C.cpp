#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
long long s;
int cnt[N];

bool check(int u, bool out = 0) {
    long long curSum = 1ll * (n + 1) * n / 2;
    for (int i = 1; i <= n; i++) {
        cnt[i] = 1;
    }
    int now = 2;
    for (int i = n; i; i--) {
        while (now <= n && cnt[now] == 1ll * u * cnt[now - 1]) now++;
        if (now >= i) break;
        if (cnt[i] > 1) break;
        int can = i - now;
        if (curSum - can <= s) {
            cnt[i]--;
            cnt[i - (curSum - s)]++;
            curSum = s;
            break;
        } else {
            curSum -= can;
            cnt[i]--;
            cnt[now]++;
        }
    }
    if (curSum != s) return 0;
    if (out) {
        cout << "YES\n";

        vector<int> ls[N];
        int cur = 1;
        ls[1].push_back(1);
        for (int i = 2; i <= n; i++) {
            if (cnt[i] == 0) break;
            ls[i].resize(cnt[i]);
            for (int j = 0; j < cnt[i]; j++) {
                ls[i][j] = ++cur;
                cout << ls[i - 1][j / u] << ' ';
            }
        }
        cout << endl;
    }
    return 1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> s;
    long long mx = 1ll * (n + 1) * n / 2;
    long long mn = 1ll * 2 * (n - 1) + 1ll;
    if (mn > s || mx < s) {
        cout << "NO" << endl;
        return 0;
    }

    if (s == mx) {
        cout << "YES" << endl;
        for (int i = 2; i <= n; i++) cout << i - 1 << ' ';
            cout << endl;
        return 0;
    }

    if (s == mn) {
        cout << "YES" << endl;
        for (int i = 2; i <= n; i++) cout << 1 << ' ';
            cout << endl;
        return 0;
    }

    int low = 0, high = n;
    while (high - low > 1) {
        int mid = low + high >> 1;
        if (check(mid)) {
            high = mid;
        } else {
            low = mid;
        }
    }
    check(high, 1);
    return 0;
}