#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 5e5 + 5;

int n, m, z[N * 2], z2[N];
ll sum, ans;
char a[N], b[N], s[N * 2];
vector<int> va[N * 2], vb[N * 2];

void Z(char t[], int a[]) {
    int l = 0, r = 0;
    for(int i = 0; t[i]; i++) {
        int& j = a[i] = i <= r ? min(z[i - l], r - i + 1) : 0;
        while(s[j] && t[i + j] == s[j]) j++;
        if(i + j >= r) l = i, r = i + j - 1;
    }
}
struct {
    int c[N];
    void add(int i, int v) {
        for(; i <= n; i += i & -i) c[i] += v;
    }
    int qry(int i, int r = 0) {
        for(; i; i &= i - 1) r += c[i];
        return r;
    }
} ta, tb;

int main() {
    scanf("%d%d%s%s%s", &n, &m, a, b, s);
    Z(s + 1, z + 1), Z(a, z2 + 1);
    rep(i, 1, n) va[z2[i]].pb(i);
    reverse(s, s + m), Z(s + 1, z + 1);
    reverse(b, b + n), Z(b, z2 + 1);
    rep(i, 1, n) vb[z2[i]].pb(n + 1 - i);
    rep(i, 1, n) ta.c[i] = i & -i;
    For(i, 0, m) {
        for(int j : vb[m - i]) {
            sum += ta.qry(j) - ta.qry(max(0, j - m + 1));
            tb.add(j, 1);
        }
        if(i) ans += sum;
        for(int j : va[i]) {
            sum -= tb.qry(min(n, j + m - 2)) - tb.qry(j - 1);
            ta.add(j, -1);
        }
    }
    cout << ans;
}