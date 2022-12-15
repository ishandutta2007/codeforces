#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define REP(i,a) for (int i = 0; i < a; i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define MAXN 30005

long long n, m, dx, dy, x, y, cnt[1000005];

int main(){
    // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    // ios::sync_with_stdio(0);
    cin >> n >> m >> dx >> dy;
    int ans = 0;
    // cout << invv(11, 100); return 0;
    FOR (i, 1, n - 1) if ((i * dx) % n == 1) {
        dx = i;
        break;
    }
    while (m--) {
        cin >> x >> y;
        long long cur = (x * dy) % n;
        cur *= dx;
        cur %= n;
        cur = (y + n - cur) % n;
        cnt[cur]++;
        if (cnt[cur] > cnt[ans]) ans = cur;
    }
    cout << 0 << ' ' << ans;
}