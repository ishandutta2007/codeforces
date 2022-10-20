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

int n, k;
int a[N];
int b[N];
int nxt[N], pre[N];
int used[N];
int pos[N];

int get(int u, int *a) {
    if (u < 1 || u > n) return u;
    if (!used[u]) return u;
    return a[u] = get(a[u], a);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin >> tc;
    while (tc--) {
        cin >> n >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            pos[a[i]] = i;
        }
        for (int i = 1; i <= k; i++) cin >> b[i];
        for (int i = 1; i <= n; i++) {
            nxt[i] = i + 1;
            pre[i] = i - 1;
            used[i] = 0;
        }
        set<int> s;
        for (int i = 1; i <= k; i++) s.insert(b[i]);
        int res = 1;
        for (int i = 1; i <= k; i++) {
            int p = pos[b[i]];
            // cout << "# " << i << ' ' << p << endl;
            int cnt = 0;
            int foo = -1;
            int u = get(p + 1, nxt);
            if (u >= 1 && u <= n && !s.count(a[u])) {
                cnt++;
                foo = u;
            }
            int v = get(p - 1, pre);
            if (v >= 1 && v <= n && !s.count(a[v])) {
                cnt++;
                foo = v;
            }
            s.erase(b[i]);
            // cout << u << ' ' << v << ' ' << cnt << ' ' << foo << endl;
            if (!cnt) {
                res = 0;
                break;
            }
            used[foo] = 1;
            res = mul(res, cnt);
        }
        cout << res << '\n';
    }   
    return 0;
}