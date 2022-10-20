#include <bits/stdc++.h>

using namespace std;

const int MOD = 1000000007;

inline int add(int u, int v) {
    u += v;
    if (u >= MOD) {
        u -= MOD;
    }
    return u;
}

inline int sub(int u, int v) {
    u -= v;
    if (u < 0) {
        u += MOD;
    }
    return u;
}

inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}

inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) {
            res = mul(res, u);
        }
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}

inline int inv(int u) {
    return power(u, MOD - 2);
}

const int N = 400010;

int n;
pair<int, int> query[N];
int val[N];
set<int> buying, selling;
set<int> both;

int getCnt(int u) {
    int res = 0;
    res += (u == *buying.rbegin() || both.find(u) != both.end());
    res += (u == *selling.begin() || both.find(u) != both.end());
    return res;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        char a[10];
        memset(a, 0, sizeof a);
        scanf("%s %d", a, &query[i].second);
        query[i].first = (a[1] != 'D');
        val[i] = query[i].second;
    }
    sort(val + 1, val + n + 1);
    for (int i = 1; i <= n; i++) {
        query[i].second = lower_bound(val + 1, val + n + 1, query[i].second) - val;
    }
    int res = 1;
    buying.insert(0);
    selling.insert(n + 1);
    for (int i = 1; i <= n; i++) {
        if (query[i].first == 0) {
            if (query[i].second < *buying.rbegin()) {
                buying.insert(query[i].second);
            } else if (query[i].second > *selling.begin()) {
                selling.insert(query[i].second);
            } else {
                both.insert(query[i].second);
            }
        } else {
            int cnt = getCnt(query[i].second);
            if (cnt == 0) {
                cout << 0 << endl;
                return 0;
            }
            res = mul(res, cnt);
            for (int u : both) {
                if (u < query[i].second) {
                    buying.insert(u);
                } else if (u > query[i].second) {
                    selling.insert(u);
                }
            }
            both.clear();
            if (buying.find(query[i].second) != buying.end()) {
                buying.erase(query[i].second);
            }
            if (selling.find(query[i].second) != selling.end()) {
                selling.erase(query[i].second);
            }
        }
    }
    cout << mul(res, add((int)both.size(), 1)) << endl;
    return 0;
}