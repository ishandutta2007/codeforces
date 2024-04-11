#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
 
using namespace std;
using ll = long long;

ll read() {
    const int M = 1e6;
    static streambuf* in = cin.rdbuf();
    #define gc (p1 == p2 && (p2 = (p1 = buf) + in -> sgetn(buf, M), p1 == p2) ? -1 : *p1++)
    static char buf[M], *p1, *p2;
    int c = gc; ll r = 0;
    while(c < 48) c = gc;
    while(c > 47) r = r * 10 + (c & 15), c = gc;
    return r;
}

const int N = 1e6 + 5;

int n, L[2][N], c[2][15][N][2];
ll a[N], sum, ans;

void add(int c[][2], int i, int v) {
    for(int v2 = i * v; i <= n; i += i & -i) c[i][0] += v, c[i][1] += v2;
}
int qry(int c[][2], int i, int r = 0) {
    for(int j = i + 1; i; i &= i - 1) r += j * c[i][0] - c[i][1];
    return r;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    rep(i, 1, n) a[i] = read();
    for(int d = 0; d < 60; d += 15) {
        mem(c, 0), sum = 0;
        rep(i, 1, n) {
            rep(t, 0, 1) {
                auto mdfy = [&](int i, int v) {
                    int p = __builtin_popcountll(a[i]) - d;
                    if(p < 0 || p > 14) return;
                    add(c[t][p], L[t][i] + 1, v), add(c[t][p], i + 1, -v);
                    sum += (qry(c[!t][p], i) - qry(c[!t][p], L[t][i])) * v;
                };
                for(int& j = L[t][i] = i - 1; j && (a[j] < a[i]) != t; j = L[t][j]) mdfy(j, -1);
                mdfy(i, 1);
            }
            ans += sum;
        }
    }
    cout << ans;
}