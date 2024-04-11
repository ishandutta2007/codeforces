#include <bits/stdc++.h>
 
using namespace std;
 
const int N = 1100010;
const int MOD = 1000000007;
const int LOG = 22;
const int BASE = 10007;
 
inline int add(int u, int v) {
    return (u += v) >= MOD ? u - MOD : u;
}
 
inline int sub(int u, int v) {
    return (u -= v) < 0 ? u + MOD : u;
}
 
inline int mul(int u, int v) {
    return (long long)u * v % MOD;
}
 
inline int power(int u, int v) {
    int res = 1;
    while (v) {
        if (v & 1) res = mul(res, u);
        u = mul(u, u);
        v >>= 1;
    }
    return res;
}
 
inline int inv(int u) {
    return power(u, MOD - 2);
}
 
int n;
int powerOfBase[N];
vector<int> h[N];
vector<int> orders[N];
int len[N];
string a[N];
int invBase;
 
int getHash(int u, int pos, int l) {
    if (l < pos) return h[u][l];
    l++;
    int res = 0;
    if (pos > 0) res = h[u][pos - 1];
    int now = mul(sub(h[u][l], h[u][pos]), invBase);
    return add(res, now);
}
 
bool smallerOrEqual(int u, int posU, int v, int posV) {
    int lenU = len[u] - (posU != len[u]);
    int lenV = len[v] - (posV != len[v]);
    int lenMin = min(lenU, lenV);
    int low = -1, high = lenMin;
    while (high - low > 1) {
        int mid = low + high >> 1;
        int h1 = getHash(u, posU, mid);
        int h2 = getHash(v, posV, mid);
        if (h1 == h2) low = mid;
        else high = mid;
    }
    // cout << getHash(u, posU, 0) << endl;
    // cout << getHash(v, posV, 0) << endl;
    int uu = low + 1 + (posU <= low + 1);
    int vv = low + 1 + (posV <= low + 1);
    if (uu >= len[u]) return 1;
    if (vv >= len[v]) return 0;
    return a[u][uu] < a[v][vv];
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    invBase = inv(BASE);
    powerOfBase[0] = 1;
    for (int i = 1; i < N; i++) {
        powerOfBase[i] = mul(powerOfBase[i - 1], BASE);
    }
    cin >> n;
 
    vector<pair<int, int>> last;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        a[i] = s;
        len[i] = s.size();
        s += (char)('a' - 1);
        vector<int> nxt(len[i]);
        nxt.back() = len[i];
        for (int j = len[i] - 2; j >= 0; j--) {
            if (s[j] == s[j + 1]) nxt[j] = nxt[j + 1];
            else nxt[j] = j + 1;
        }
        orders[i].assign(len[i] + 1, 0);
        int l = 0, r = len[i];
        for (int j = 0; j < len[i]; j++) {
            if (s[j] < s[nxt[j]]) {
                orders[i][r--] = j;
            } else {
                orders[i][l++] = j;
            }
        }
        orders[i][l] = len[i];
        
        h[i].assign(len[i], 0);
        for (int j = 0; j < len[i]; j++) {
            if (j > 0) h[i][j] = h[i][j - 1];
            h[i][j] = add(h[i][j], mul(s[j], powerOfBase[j]));
        }
    }
    
    for (int i = 1; i <= n; i++) {
        vector<pair<int, int>> now;
        if (i == 1) {
            for (int j = 0; j <= len[i]; j++) {
                now.push_back({orders[i][j], 1});
            }    
        } else {
            int cur = 0;
            int sum = 0;
            for (int j = 0; j <= len[i]; j++) {
                while (cur < last.size() && smallerOrEqual(i - 1, last[cur].first, i, orders[i][j])) {
                    sum = add(sum, last[cur].second);
                    cur++;
                }
                now.push_back({orders[i][j], sum});
            }
        }
        last.swap(now);
        // cout << "# " << i << endl;
        // for (auto u : last) cout << u.first << ' ' << u.second << endl;
    }
 
    int res = 0;
    for (auto u : last) res = add(res, u.second);
    cout << res << endl;
    return 0;
}