#include <bits/stdc++.h>

using namespace std;
long long w, n, t[200005], s[200005];
bool solve(long long ert) {
    for (int i=1; i<=n; i++) s[i]=t[i];
    for (int i=n; i>=3; i--) {
        if (s[i]<ert) return 0;
        long long mini=min((s[i]-ert)/3, t[i]/3);
        s[i-1]+=mini;
        s[i-2]+=2*mini;
    }
    return (s[1]>=ert && s[2]>=ert);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        for (int i=1; i<=n; i++) {
            cin >> t[i];
        }
        long long lo=0, hi=1e9+1, mid;
        while (hi-lo>1) {
            mid=(hi+lo)/2;
            if (solve(mid)) lo=mid;
            else hi=mid;
        }
        cout << lo << "\n";
    }
    return 0;
}