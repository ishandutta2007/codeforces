#include <bits/stdc++.h>

using namespace std;
const long long c=100002, sok=1e15;
long long t[c], p[c], kom[c], n, k, sum, o=0, m1=sok, m2=sok, ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
        kom[i]=kom[i-1]+t[i];
    }
    for (int i=1; i<=n; i++) {
        cin >> p[i];
        m2=min(m2, p[i]);
        if (i<n && m2<m1) swap(m2, m1);
    }
    sum=kom[n];
    if (k>=2) {
        cout << max({o, sum-m1, t[n]-p[n]}) << "\n";
        return 0;
    }
    for (int i=2; i<=n; i++) {
        ans=max(ans, sum-kom[i-1]-p[i]);
    }
    if (k==0) {
        ans=max(ans, sum-p[1]);
        cout << ans << "\n";
        return 0;
    }
    ans=max(ans, sum-m1-m2);
    for (int i=2; i<=n; i++) {
        ans=max(ans, sum-t[i]-p[1]);
    }
    ans=max(ans, sum-t[n]-m1);
    cout << ans << "\n";
    return 0;
}