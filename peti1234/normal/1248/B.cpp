#include <bits/stdc++.h>

using namespace std;
long long n, t[100005], ans, sum;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i];
    }
    sort(t+1, t+n+1);
    for (int i=1; i<=n/2; i++) {
        sum+=t[i];
    }
    ans+=sum*sum;
    sum=0;
    for (int i=n/2+1; i<=n; i++) {
        sum+=t[i];
    }
    ans+=sum*sum;
    cout << ans << "\n";
    return 0;
}