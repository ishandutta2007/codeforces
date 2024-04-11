#include <bits/stdc++.h>

using namespace std;
const int c=200002, mod=998244353;
long long sum=1, cnt=1;
int t[c], p[c], n, m, x;
bool jo=1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m, x=m, p[m+1]=2*mod;
    for (int i=1; i<=n; i++) cin >> t[i];
    for (int i=1; i<=m; i++) cin >> p[i];
    for (int i=n; i>=1; i--) {
        if (jo && t[i]<p[x+1]) sum*=cnt, sum%=mod, jo=0;
        if (t[i]==p[x]) x--, jo=1, cnt=0;
        if (t[i]>=p[x+1]) cnt++;
        if (t[i]<p[x]) sum=0;
        if (x==0 && t[i]<p[1]) sum=0;
    }
    if (x) sum=0;
    cout << sum << "\n";
    return 0;
}