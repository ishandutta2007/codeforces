#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++)
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 2e5 + 7;
const int mod = 1e9 + 7;
int n, m, f[N], cnt = 0, ans = 1;
int find(int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}
#define P(i, j) ((i) * (n + 2) + j)
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    L(i, 1, (n + 2) * 2) f[i] = i;
    L(i, 1, m) {
        int x, y; char opt[20];
        cin >> x >> y >> opt;
        int l = x - y + 1, r = x + y - 1;
        if(l < 1) l = 2 - l;
        if(r > n) r = n * 2 - r;
        r += 2;
        if(opt[0] == 'o') f[find(P(1, l))] = find(P(0, r)), f[find(P(0, l))] = find(P(1, r));
        else f[find(P(1, l))] = find(P(1, r)), f[find(P(0, l))] = find(P(0, r));
    }
    L(i, 1, n + 2) if(find(P(0, i)) == find(P(1, i))) return puts("0"), 0;
    L(i, 1, (n + 2) * 2) if(find(i) == i) ++cnt;
    L(i, 1, cnt / 2 - 2) ans = (ll) ans * 2 % mod;
    cout << ans << endl;
    return 0;
}