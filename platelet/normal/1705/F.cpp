#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

int n, cnt[256];
char s[256][1280], ans[1280];

inline int read() {
    int x;
    cin >> x;
    if(x == n) exit(0);
    return x;
}
void find(int qb, int q, int kb, int k) {
    if(q == 1) return void(ans[kb] = cnt[qb] ? 'T' : 'F');
    q >>= 1, k = k - q >> 1;
    For(i, 0, q) {
        int x = cnt[qb + i], y = cnt[qb + q + i], z = (x ^ y) & 1;
        ans[kb + k * 2 + i] = z ? 'T' : 'F';
        cnt[qb + i] = y + x - z >> 1, cnt[qb + q + i] = y - x + z >> 1;
    }
    find(qb, q, kb, k), find(qb + q, q, kb + k, k);
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int k = 1, q = 1;
    s[0][0] = 1;
    cin >> n;
    while(k < n) {
        For(i, 0, q) For(j, 0, k) s[i + q][j] = s[i + q][j + k] = s[i][j], s[i][j + k] = -s[i][j];
        For(i, 0, q) s[i][k * 2 + i] = 1;
        k = k * 2 + q, q *= 2;
    }
    For(i, 0, q) {
        For(j, 0, n) cout << (s[i][j] > 0 ? 'T' : 'F');
        cout << '\n';
        For(j, 0, n) cout << (s[i][j] < 0 ? 'T' : 'F');
        cout << '\n';
    }
    cout.flush();
    For(i, 0, q) {
        cnt[i] = reduce(s[i], s[i] + k, 0) + read();
        cnt[i] = cnt[i] - read() >> 1;
    }
    find(0, q, 0, k);
    For(i, 0, n) cout << ans[i];
    cout << endl;
}