#include <bits/stdc++.h>

using namespace std;
const int c=100002;
int n, m, p;
long long ert[c], kom[c], t[c], dp[102][c];
long long dist(int a, int b) {
    if (a>b) {
        return 0;
    }
    return t[b]*(b-a)-kom[b]+kom[a];
}
void solve(int x, int lo, int hi, int kezd, int veg) {
    if (lo>hi) {
        return;
    }
    int mid=(hi+lo)/2, pos=kezd;
    for (int i=kezd; i<=veg; i++) {
        if (dp[x-1][pos]+dist(pos, mid)>dp[x-1][i]+dist(i, mid)) {
            pos=i;
        }
    }
    dp[x][mid]=dp[x-1][pos]+dist(pos, mid);
    solve(x, lo, mid-1, kezd, pos);
    solve(x, mid+1, hi, pos, veg);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> m >> n >> p;
    for (int i=2; i<=m; i++) {
        cin >> ert[i];
        ert[i]+=ert[i-1];
    }
    for (int i=1; i<=n; i++) {
        int a, b; cin >> a >> b;
        t[i]=b-ert[a];
    }
    sort(t+1, t+n+1);
    for (int i=1; i<=n; i++) {
        kom[i]=kom[i-1]+t[i];
    }
    for (int i=1; i<=n; i++) {
        dp[0][i]=1e15;
    }
    for (int i=1; i<=p; i++) {
        solve(i, 1, n, 0, n);
    }
    cout << dp[p][n] << "\n";
    return 0;
}