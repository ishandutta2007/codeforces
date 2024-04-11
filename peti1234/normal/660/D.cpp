#include <bits/stdc++.h>

using namespace std;
const int c=2005;
int n, x[c], y[c];
long long ans;
map<pair<int, int>, int> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            int a=x[i]+x[j], b=y[i]+y[j];
            ans+=m[{a, b}]++;
        }
    }
    cout << ans << "\n";
    return 0;
}