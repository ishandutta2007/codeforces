#include <bits/stdc++.h>

using namespace std;
const int c=300005;
int n, m, ki[c], t[300005];
long long ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        int x;
        cin >> x;
        ki[x]=i;
    }
    for (int i=1; i<=n+1; i++) {
        t[i]=n+1;
    }
    for (int i=1; i<=m; i++) {
        int a, b;
        cin >> a >> b;
        a=ki[a], b=ki[b];
        if (a>b) swap(a, b);
        t[a]=min(t[a], b);
    }
    for (int i=n; i>=1; i--) {
        t[i]=min(t[i], t[i+1]);
        ans+=t[i]-i;
    }
    cout << ans << "\n";
    return 0;
}