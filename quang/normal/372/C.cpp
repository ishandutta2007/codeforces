#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 150001

using namespace std;

int n, m, d, top, bot;
int st[N];
long long x[N], y[N];

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n >> m >> d;
    memset(x, 0 ,sizeof(x));
    int tr = 0, a, b, t;
    for(int i = 1; i <= m; i++) {
        cin >> a >> b >> t;
        deque <int> dq;
        long long interval = min(1ll * n, 1ll * (t - tr) * d);
        for (long long j = 1; j <= interval; j++){
            while (dq.size() && x[dq[dq.size() - 1]] <= x[(int)j]) dq.pop_back();
            dq.push_back((int)j);
        }
        for (long long j = 1; j <= 1ll * n; j++){
            long long  k = j + interval;
            if (k <= (1ll * n)){
                while (dq.size() && x[dq[dq.size() - 1]] <= x[(int)k]) dq.pop_back();
                dq.push_back((int)k);
            }
            y[j] = x[dq[0]] + 1ll * (b - abs(a - j));
            while (dq.size() && dq[0] <= (int)(j - interval)) dq.pop_front();
        }
        tr = t;
        memcpy(x, y, sizeof(y));
    }
    long long ans = -12139847239812321ll;
    for(int i = 1; i <= n; i++) ans = max(ans, y[i]);
    cout << ans;
    return 0;
}