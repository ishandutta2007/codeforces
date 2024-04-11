#include <bits/stdc++.h>
 
using namespace std;
const int N = 2e5 + 5;
const int K = 20;
int t[N][K][2];
int a[N];
int b[N];
int n;
int pow2[K];
int lg2[N];
 
void init() {
    pow2[0] = 1;
    for (int i = 1; i < K; i++)
        pow2[i] = pow2[i - 1] * 2;
 
    lg2[1] = 0;
    for (int i = 2; i < N; i++)
        lg2[i] = lg2[i / 2] + 1;
 
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; i + pow2[j] <= n; j++) {
            if (j == 0) {
                t[i][j][0] = a[i];
                t[i][j][1] = b[i];
            } else {
                t[i][j][0] = max(t[i][j - 1][0], t[i + pow2[j - 1]][j - 1][0]);
                t[i][j][1] = min(t[i][j - 1][1], t[i + pow2[j - 1]][j - 1][1]);
            }
        }
    }
}
 
int res(int l, int r) {
    int p = lg2[r - l];
    int ans1 = max(t[l][p][0], t[r - pow2[p]][p][0]);
    int ans2 = min(t[l][p][1], t[r - pow2[p]][p][1]);
    return ans1 - ans2;
}
 
int upp_bound(int tl, int tr, int val) {
    int l = tl;
    int r = tr;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (res(tl, m) <= val)
            l = m;
        else
            r = m;
    }
    if (res(tl, r) <= val)
        l++;
    return l;
}
 
 
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    init();
    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans += upp_bound(i, n, 0) - upp_bound(i, n, -1);
    cout << ans << endl;
    return 0;
}