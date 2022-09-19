#include <bits/stdc++.h>

using namespace std;
int w, n, a[52], b[52], ma, mb;
long long sum;
int main()
{
    cin >> w;
    while(w--) {
        cin >> n, sum=0, ma=INT_MAX, mb=ma;
        for (int i=1; i<=n; i++) cin >> a[i], ma=min(ma, a[i]);
        for (int i=1; i<=n; i++) cin >> b[i], mb=min(mb, b[i]);
        for (int i=1; i<=n; i++) sum+=max(a[i]-ma, b[i]-mb);
        cout << sum << "\n";
    }
    return 0;
}