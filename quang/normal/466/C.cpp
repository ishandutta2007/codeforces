#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 500010;

int n, a[N];
long long sum[N], s;
int dau[N], cuoi[N];

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n;
    sum[0] = 0ll;
    for(int i = 1; i <= n; i++) cin >> a[i], sum[i] = sum[i - 1] + a[i];
    if(sum[n] % 3) {
        cout << 0;
        return 0;
    }
    s = sum[n] / 3;
    memset(dau, 0, sizeof(dau));
    memset(cuoi, 0, sizeof(cuoi));
    for(int i = 1; i <= n; i++) dau[i] = (sum[i] == s);
    for(int i = n; i; i--) cuoi[i] = cuoi[i + 1] + (sum[n] - sum[i - 1] == s);
    long long res = 0;
    for(int i = 1; i <= n; i++)
        res += 1ll * dau[i] * cuoi[i + 2];
    cout << res;
    return 0;
}