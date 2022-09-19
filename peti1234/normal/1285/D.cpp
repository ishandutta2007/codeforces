#include <bits/stdc++.h>

using namespace std;
long long n, t[100002];
long long solve(int l, int r, int b) {
    if (b==-1) {
        return 0;
    }
    int pos=l;
    if ((t[l] & (1<<b)) == (t[r] & (1<<b))) {
        return solve(l, r, b-1);
    }
    while ((t[pos] & (1<<b))==0) {
        pos++;
    }
    return (1<<b)+min(solve(l, pos-1, b-1), solve(pos, r, b-1));
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    cout << solve(1, n, 30) << "\n";
    return 0;
}