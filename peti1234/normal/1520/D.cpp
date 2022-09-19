#include <bits/stdc++.h>

using namespace std;
map<int, int> m;
int w, n, x;
long long ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        ans=0, m.clear();
        for (int i=1; i<=n; i++) {
            cin >> x;
            ans+=m[i-x]++;
        }
        cout << ans << "\n";
    }
    return 0;
}