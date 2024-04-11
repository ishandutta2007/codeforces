#include <bits/stdc++.h>

using namespace std;
map<int, int> m;
int n;
long long ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin >> n;
    for (int i=1; i<=n; i++) {
        long long x;
        cin >> x;
        for (int j=0; j<=30; j++) {
            ans+=m[(1<<j)-x];
        }
        m[x]++;
    }
    cout << ans << "\n";
    return 0;
}