#include <bits/stdc++.h>

using namespace std;
int w, n, x;
long long ans;
map<int, long long> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> w;
    while (w--) {
        cin >> n;
        ans=0;
        m.clear();
        for (int i=1; i<=n; i++) {
            cin >> x;
            ans+=m[x]*(n-i+1);
            m[x]+=i;
        }
        cout << ans << "\n";
    }
    return 0;
}