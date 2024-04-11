#include <bits/stdc++.h>

using namespace std;
const int c=200002;
int n, t[c], mini=1e9, pos=1, x;
long long ans[c], sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) cin >> t[i];
    t[0]=t[n];
    for (int i=1; i<=n; i++) {
        mini=min(mini, t[i]);
        if (t[i]>t[pos] || (t[i]==t[pos] && t[i]>t[i-1])) pos=i;
    }
    if (mini==t[pos] && mini) {
        cout << "NO\n";
        return 0;
    }
    if (!t[pos]) t[pos]++, x=1;
    for (int i=pos; i; i--) {
        sum+=t[i];
        if (!t[i] && !x) sum*=2, x=1;
        ans[i]=sum;
    }
    for (int i=n; i>pos; i--) {
        sum+=t[i];
        if (!t[i] && !x) sum*=2, x=1;
        ans[i]=sum;
    }
    cout << "YES\n";
    for (int i=1; i<=n; i++) cout << ans[i] << " ";
    cout << "\n";
    return 0;
}