#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back

using namespace std;

const int N = 200 + 5;

char s[N], t[N], as[N * 4];
int n, m, f[N][N][N * 2];
tuple<int, int, int, char> pre[N][N][N * 2];

int main() {
    scanf("%s%s", s + 1, t + 1);
    n = strlen(s + 1), m = strlen(t + 1);
    mem(f, -1), f[0][0][0] = 0;
    queue<tuple<int, int, int>> q;
    q.emplace(0, 0, 0);
    while(q.size()) {
        auto [i, j, k] = q.front(); q.pop();
        int d = f[i][j][k] + 1;
        auto expand = [&](int i, int j, int k, char c) {
            tuple p(i, j, k, c);
            i += s[i + 1] == c, j += t[j + 1] == c, k += c == '(' ? 1 : -1;
            if(k >= 0 && k <= n + m && !~f[i][j][k])
                f[i][j][k] = d, pre[i][j][k] = p, q.emplace(i, j, k);
        };
        expand(i, j, k, '('), expand(i, j, k, ')');
    }
    for(int nw = f[n][m][0], i = n, j = m, k = 0; nw; nw--)
        tie(i, j, k, as[nw]) = pre[i][j][k];
    printf("%s", as + 1);
}