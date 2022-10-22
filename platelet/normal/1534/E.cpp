#include <bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i++)
#define per(i, r, l) for(int i = (r); i >= (l); i--)
#define mem(a, b) memset(a, b, sizeof a)
#define For(i, l, r) for(int i = (l), i##e = (r); i < i##e; i++)
#define pb push_back
#define upd(a, b) (a = min(a, b))

using namespace std;
using ll = long long;

const int N = 505;

int n, K, d[N], pre[N], q[N];

int main() {
#ifdef local
	// freopen(".in", "r", stdin);
#endif
    cin >> n >> K;
    mem(d, -1);
    d[0] = 0;
    int l = 1, r = 1;
    while(l <= r) {
        int u = q[l++];
        rep(i, 0, K) if(i <= u && K - i <= n - u) {
            int v = u - i + K - i;
            if(!~d[v]) d[v] = d[u] + 1, pre[v] = u, q[++r] = v;
        }
    }
    if(~d[n]) {
        queue<int> in, out;
        rep(i, 1, n) in.push(i);
        int as = 0, x;
        for(; in.size(); scanf("%d", &x), as ^= x) {
            putchar('?');
            int R = K - in.size() + pre[in.size()] >> 1, L = K - R;
            while(L--) printf(" %d", in.front()), out.push(in.front()), in.pop();
            while(R--) printf(" %d", out.front()), in.push(out.front()), out.pop();
            puts(""), fflush(stdout);
        }
        printf("! %d", as);
    } else puts("-1");
    fflush(stdout);
    return 0;
}