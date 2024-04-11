#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;
const int MOD1 = (int)1e9 + 7;
const int MOD2 = (int)1e9 + 9;
const int BASE = (int)1e4 + 7;

inline pair<int, int> add(pair<int, int> u, pair<int, int> v) {
    u.first += v.first;
    u.second += v.second;
    if (u.first >= MOD1) u.first -= MOD1;
    if (u.second >= MOD2) u.second -= MOD2;
    return u;
}

inline pair<int, int> sub(pair<int, int> u, pair<int, int> v) {
    u.first -= v.first;
    u.second -= v.second;
    if (u.first < 0) u.first += MOD1;
    if (u.second < 0) u.second += MOD2;
    return u;
}

inline pair<int, int> mul(pair<int, int> u, pair<int, int> v) {
    return {(long long)u.first * v.first % MOD1, (long long)u.second * v.second % MOD2};
}

string s, t;
pair<int, int> p[N];
pair<int, int> h[N];

pair<int, int> getH(int l, int r) {
    return sub(h[r], mul(h[l], p[r - l]));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    cin >> t;
    int cnt[2] = {0, 0};
    for (char u : s) {
        cnt[u - '0']++;
    }

    p[0] = {1, 1};
    for (int i = 1; i < N; i++) {
        p[i] = mul(p[i - 1], {BASE, BASE});
    }

    t = ' ' + t;
    h[0] = {0, 0};
    int n = t.size() - 1;
    for (int i = 1; i <= n; i++) {
        h[i] = mul(h[i - 1], {BASE, BASE});
        h[i] = add(h[i], {t[i], t[i]});
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (i * cnt[0] >= n) {
            break;
        }
        if ((n - i * cnt[0]) % cnt[1]) continue;
        int j = (n - i * cnt[0]) / cnt[1];

        int cur = 0;
        pair<int, int> arr[2];
        arr[0] = arr[1] = {-1, -1};
        int f = 1;
        for (int k = 0; k < s.size(); k++) {
            if (s[k] == '0') {
                pair<int, int> foo = getH(cur, cur + i);
                if (arr[0].first == -1) arr[0] = foo;
                else if (arr[0] != foo) {
                    f = 0;
                    break;
                }
                cur += i;
            } else {
                pair<int, int> foo = getH(cur, cur + j);
                if (arr[1].first == -1) arr[1] = foo;
                else if (arr[1] != foo) {
                    f = 0;
                    break;
                }
                cur += j;
            }
        }
        if (f && arr[0] != arr[1]) {
            res++;
        }
    }
    cout << res << endl;
    return 0;
}