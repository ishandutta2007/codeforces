#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;
using ll = long long;

const int N = 260;

int n, a[N], b[N], c[N], A[N][N];

bool ins(vector<int> coef, int con) {
    static int a[N];
    mem(a, 0), a[n + 1] = con % 3;
    for(int i : coef) a[i] = 1;
    rep(i, 1, n) if(a[i]) if(A[i][i])
        per(j, n + 1, i) (a[j] -= a[i] * A[i][j]) %= 3;
    else {
        per(j, n + 1, i) A[i][j] = a[j] * a[i] % 3;
        return 0;
    }
    return a[n + 1];
}
bool chk(array<int, 3> e) {
    sort(e.begin(), e.end(), [](int x, int y) {
        return a[x] != a[y] ? a[x] < a[y] : b[x] < b[y];
    });
    return a[e[0]] == a[e[1]] && b[e[1]] == b[e[2]] && b[e[0]] == a[e[2]];
}
void solve() {
    scanf("%*d%d", &n), mem(A, 0);
    rep(i, 1, n) {
        scanf("%d%d%d", &a[i], &b[i], &c[i]);
        if(a[i] > b[i]) swap(a[i], b[i]);
        if(~c[i] && ins({i}, c[i])) return void(puts("-1"));
    }
    rep(i, 1, n) rep(j, i + 1, n) rep(k, j + 1, n)
    if(chk({i, j, k}) && ins({i, j, k}, 0)) return void(puts("-1"));
    per(i, n, 1) rep(j, i + 1, n) (A[i][n + 1] -= A[i][j] * A[j][n + 1]) %= 3;
    rep(i, 1, n) printf("%d ", (A[i][n + 1] + 2) % 3 + 1);
    puts("");
}
int main() {
    int T;
    for(cin >> T; T--; solve());
}