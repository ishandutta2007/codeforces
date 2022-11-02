#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define fast ios::sync_with_stdio(false); cin.tie(0);
#define foru(i, k, n) for (int i = k; i < n; i++)
#define ford(i, k, n) for (int i = k; i >= n; i--)
#define ff first
#define ss second

#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <numeric>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef long double ld;
typedef bitset<26> bs;
typedef vector<int> vi;

const int sz = 3e2 + 5;
int n, m;
string b[sz];
pll hsh[sz][sz];
bs valid[sz][sz];
ll pr[2][26], mod[2];

ll foo(vector<pll> s) {
    if (s.empty())return 0;
    int n = s.size();
    ll tot = 0;
    vector<vector<int>> p(2, vector<int>(n, 0));
    for (int z = 0, l = 0, r = 0; z < 2; z++, l = 0, r = 0) {
        for (int i = 0; i < n; i++)
        {
            int nz = (1 - z);
            if (i < r) p[z][i] = min(r - i + nz, p[z][l + r - i + nz]);
            int L = i - p[z][i], R = i + p[z][i] - nz;
            while (L - 1 >= 0 && R + 1 < n && s[L - 1] == s[R + 1]) p[z][i]++, L--, R++;
            if (R > r) l = L, r = R;
        }
    }
    foru(z, 0, 2) {
        foru(i, 0, n)tot += p[z][i]+z;
    }
    return tot;
}

void prec() {
    pr[0][0] = pr[1][0] = 1;
    pr[0][1] = 971;
    pr[1][1] = 983;
    mod[0] = 1e9 + 7;
    mod[1] = 1e9 + 9;
    foru(i, 2, 26) {
        foru(j, 0, 2) {
            pr[j][i] = (pr[j][i - 1] * pr[j][1]) % mod[j];
        }
    }
}

int main() {
    fast;
    prec();
    cin >> n >> m;
    foru(i, 0, n)cin >> b[i];
    ll tot = 0;
    for (int len = 1; len <= m; len++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j + len <= m; j++) {
                int nj = j + len - 1;
                int c = b[i][nj] - 'a';
                valid[i][j][c] = !valid[i][j][c];
                hsh[i][j].ff = (hsh[i][j].ff + pr[0][c]) % mod[0];
                hsh[i][j].ss = (hsh[i][j].ss + pr[1][c]) % mod[1];
            }
        }
        for (int j = 0; j + len <= m; j++) {
            vector<pll> cur;
            for (int i = 0; i < n; i++) {
                if (valid[i][j].count() <= 1)cur.push_back(hsh[i][j]);
                else tot += foo(cur), cur.clear();
            }
            tot += foo(cur);
        }
    }
    cout << tot << '\n';
    return 0;
}