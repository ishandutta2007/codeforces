#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const int MOD = 998244353;

inline int add(int u, int v) {return (u += v) >= MOD ? u - MOD : u;}
inline int sub(int u, int v) {return (u -= v) < 0 ? u + MOD : u;}
inline int mul(int u, int v) {return (long long)u * v % MOD;}
inline int power(int u, int v) {int res = 1;for (; v; v >>= 1, u = mul(u, u)) if (v & 1) res = mul(res, u); return res;}
inline int inv(int u) {return power(u, MOD - 2);}
inline void addTo(int &u, int v) {u = add(u, v);}
inline void subTo(int &u, int v) {u = sub(u, v);}
inline void mulTo(int &u, int v) {u = mul(u, v);}

int n, m;
int d[N];
int res[N];

struct Query {
    int a, b, id;
} queries[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
        addTo(sum, d[i] % MOD);
    }
    sort(d + 1, d + n + 1);
    for (int i = 1; i <= m; i++) {
        cin >> queries[i].a >> queries[i].b;
        queries[i].id = i;
    }
    sort(queries + 1, queries + m + 1, [&](Query &u, Query &v) {
        return u.b < v.b;
    }); 
    int smallerSum = 0;
    int cur = 0;
    for (int i = 1; i <= m; i++) {
        while (cur < n && d[cur + 1] < queries[i].b) addTo(smallerSum, d[++cur] % MOD);
        if (queries[i].a > n - cur) res[queries[i].id] = 0;
        else {
            int &now = res[queries[i].id];
            addTo(now, mul(sub(sum, smallerSum), mul(n - cur - queries[i].a, inv(n - cur))));
            addTo(now, mul(smallerSum, mul(n - cur - queries[i].a + 1, inv(n - cur + 1))));
        }
    }
    for (int i = 1; i <= m; i++) cout << res[i] << '\n';
    return 0;
}