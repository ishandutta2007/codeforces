#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, m, k, h, maxi, pos=1, baj, cnt, t[c], f[c];
long long x, y, sum;
int main()
{
    cin >> n >> m >> x >> k >> y;
    for (int i=1; i<=n; i++) cin >> t[i];
    for (int i=1; i<=m; i++) cin >> f[i];
    for (int i=1; i<=n+1; i++) {
        if (t[i]==f[pos]) {
            pos++, h=max(h, t[i]);
            if (cnt<k && h<maxi) baj=1;
            sum+=(cnt%k)*y;
            cnt-=cnt%k;
            if (h<maxi) sum+=x, cnt-=k;
            sum+=min(cnt/k*x, cnt*y);
            h=t[i], cnt=0, maxi=0;
        } else cnt++, maxi=max(maxi, t[i]);
    }
    if (pos!=m+2 || baj) cout << -1;
    else cout << sum << "\n";
    return 0;
}